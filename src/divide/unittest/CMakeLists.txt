file(GLOB SRCS *.cpp *.hpp)
ADD_EXECUTABLE(libdivide_unittest ${SRCS})

remove_definitions(-DBUILDING_MULTIPLY)
add_definitions(-DUNITTEST_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

TARGET_LINK_LIBRARIES(libdivide_unittest
    libdivide
    gtest_main
)

add_test(NAME libdivide_unittest
COMMAND libdivide_unittest)