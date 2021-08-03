file(GLOB SRCS *.cpp *.hpp)
ADD_EXECUTABLE(mymultiply_unittest ${SRCS})

remove_definitions(-DBUILDING_MULTIPLY)
add_definitions(-DUNITTEST_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

TARGET_LINK_LIBRARIES(mymultiply_unittest
    mymultiply
    gtest_main
)

add_test(NAME mymultiply_unittest
COMMAND mymultiply_unittest)