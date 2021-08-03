file(GLOB SRCS *.cpp *.hpp)
ADD_EXECUTABLE(mydivide_unittest ${SRCS})

remove_definitions(-DBUILDING_MULTIPLY)
add_definitions(-DUNITTEST_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

TARGET_LINK_LIBRARIES(mydivide_unittest
    mydivide
    gtest_main
)

add_test(NAME mydivide_unittest
COMMAND mydivide_unittest)