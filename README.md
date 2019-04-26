# :1234: A Simple Calculation Engine
## Problem statement
Develop a program that performs calculations on a series of integers. The program will run
from the command line. It has two versions:
```
calc <engine_name> <file_list>
calc <engine_name> <list of integers>
```
Files will contain one or more lines of integers. All file names have an implicit “.txt” on the end
of them – e.g. “input” on the command line maps to the file “input.txt”. All files are in the
current working directory (i.e. don't worry about directory names).
The program should supply two engines:

* Multiplier – multiplies all the integers together; it should only work with a file list as input
data
* Divider – divides all the integers, one after another; it should work with both file list and
integer lists as input data

The program should read the input data, calculate a result and display the result on stdout.
Supply an API so that a user can write his own Engine, say to calculate standard deviation.
The user should be able to easily add the engine to the library by recompiling all your source
code.
As part of the API, you should also supply a factory to generate Engines. At minimum, a user
of the factory would specify a calculation and an allowable input type.
Only do unit tests to test the Divider calculations.

## Step 1: Download 3P Dependencies

For Windows:
* [CMake](https://cmake.org/download/)
	
For Linux (Ubuntu or Debian):
``` sh
> sudo apt-get install cmake 
```
  
## Step 2: Build and Run Unit Tests

I have chosen to use the Google Test framework to unit-test my code.
To make things easier I have hooked up the CMakeList file to automatically build and download Google Test if you do not already have Google Test installed.

Assuming cmake is installed and are on the system path
For Linux
``` sh
    > cd $(git rev-parse --git-dir)
    > mkdir build
    > cd build
    > cmake ../
    > cmake --build .
    > ctest -C "Debug"
```
For Windows (in this example we explicitly want to use the MSVC 2017 64 bit compiler)
```cmd
   > cd $(git rev-parse --git-dir)
   > mkdir build
   > cd build
   > cmake -G "Visual Studio 15 2017 Win64" ../
   > cmake --build .
   > ctest -C "Debug" -V
```
## Instructions on how to add a new "Engine" for this calculator

The best way to add a new calculator would be to make a library similar to *libmultiply* and *libdivide*.

Here are some basic instructions on how to add a new engine directly to the **calc** executable module
1. Create a new source file and header file under src/calc. For example:
   * `StandardDeviation.hpp`
   * `StandardDeviation.cpp`
2. The header must have a class that derives from the interface class `aptive_exercise::EngineInterface`. For example: StandardDeviation.hpp woulld look something like this:
```C++
   #ifndef _std_dev_
   #define _std_dev_
   class  StandardDeviation : public aptive_exercise::EngineInterface<int>
    {
    public:
        StandardDeviation();
        virtual const std::string getName() const override {return "StandardDeviation";}
        virtual STATUS processArguments(const std::vector<int>& args) override;
        virtual STATUS processFile(const std::string& aFile) override;
    };
    #endif
```
I have provided doxygen style comments to the EngineInterface.hpp file for further information.

3. Provide the body for the class in the appropriate cpp file
4. In calc.cpp, include the new header file, and add the engine the the `calculator` object. For example
   * Add a `#include "StandardDeviation.h"` to the top of the file
   * Just before the line that looks like `auto engine = calculator.getEngine(argv[1]);`, add the command
   ```C++
    calculator.addEngine<StandardDeviation>(); //for an engine that supports files and command line inputs
    /*
    calculator.addEngine<StandardDeviation>(false); //for an engine that does not support command line inputs
    calculator.addEngine<StandardDeviation>(true, false); //for an engine that does not support file inputs
    */
   ```
5. Interactively verify that everything works as expected
6. Then do the responsible thing and move your code to a shared/static library so that it can be exported modularly and unittested effectively :smirk:

## References

[CMAKE + GTEST](https://github.com/kaizouman/gtest-cmake-example)
