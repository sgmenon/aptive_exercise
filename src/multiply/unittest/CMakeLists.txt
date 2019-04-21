file(GLOB SRCS *.cpp *.hpp)
ADD_EXECUTABLE(libmultiply_unittest ${SRCS})

remove_definitions(-DBUILDING_MULTIPLY)
add_definitions(-DUNITTEST_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

TARGET_LINK_LIBRARIES(libmultiply_unittest
    libmultiply
    gtest_main
)

add_test(NAME libmultiply_unittest
COMMAND libmultiply_unittest)