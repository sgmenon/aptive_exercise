# Step 1: Download 3P Dependencies

For Windows:
* [Google Test Framework](https://github.com/google/googletest)
* [CMake](https://cmake.org/download/)
	
For Linux (Ubuntu or Debian):
* ``` sh
        > sudo apt-get install libgtest-dev
        > sudo apt-get install cmake 
  ```
  
# Step 2: Build and Run Unit Tests

Assuming cmake and ctest are installed and are on the system path
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
