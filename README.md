# Step 1: Download 3P Dependencies

For Windows:
* [CMake](https://cmake.org/download/)
	
For Linux (Ubuntu or Debian):
``` sh
> sudo apt-get install cmake 
```
  
# Step 2: Build and Run Unit Tests

I have chosen to use the Google Test framework to unit-test my code.
To make things easier I have hooked up the CMakeList file to automatically build and download Google Test if you do not already have Google Test installed.

Assuming cmake is installed and are on the system path
For Linux
``` sh
    > cd $(git rev-parse --git-dir)/../build
    > cmake ../
    > cmake --build .
    > ctest -C "Debug"
```
For Windows (in this example we explicitly want to use the MSVC 2017 64 bit compiler)
```sh
   > cd build
   > cmake -G "Visual Studio 15 2017 Win64" ../
   > cmake --build .
   > ctest -C "Debug" -V
```

# References

[CMAKE + GTEST](https://github.com/kaizouman/gtest-cmake-example)
