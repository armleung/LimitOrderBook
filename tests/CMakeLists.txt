# Include FetchContent module
include(FetchContent)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main)

FetchContent_MakeAvailable(googletest)

set(Sources
    OrderBookUnitTest.cpp
    BenchmarkingTest.cpp
    OrderPipeline.cpp
)

add_executable(OrderBookTests ${Sources})

# Link GoogleTest libraries to the test target
target_link_libraries(OrderBookTests gtest gtest_main OrderBook_lib)

# Add the test executable to CTest
add_test(NAME OrderBookTests COMMAND OrderBookTests)