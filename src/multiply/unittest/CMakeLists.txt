file(GLOB SRCS *.cpp *.hpp)
ADD_EXECUTABLE(project_unittest ${SRCS})

remove_definitions(-DBUILDING_MULTIPLY)

TARGET_LINK_LIBRARIES(project_unittest
    libsid_project
    gtest_main
)

add_test(NAME project_unittest
COMMAND project_unittest)