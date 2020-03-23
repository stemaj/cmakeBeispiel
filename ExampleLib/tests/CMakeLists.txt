# tell CMake to use CTest extension
enable_testing()

# create an executable, which instantiates a runner from
# GoogleTest, Boost.Test, QtTest or whatever framework you use
add_executable(ExampleLibTest src/ExampleLibTest.cpp)

target_link_libraries (ExampleLibTest LINK_PUBLIC ExampleLib)

# depending on the framework, you need to link to it
#target_link_libraries(my_test
#                      gtest_main)

# now register the executable with CTest
add_test(NAME ExampleLibTest COMMAND ExampleLibTest)