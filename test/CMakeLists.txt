cmake_minimum_required(VERSION 3.22.3)

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
    CheckoutTests.cpp
    CMockTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    gmock_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
