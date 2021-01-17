include(CTest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK false)
add_subdirectory(gtest)

set(GTEST_INCLUDE gtest/GoogleTest/include)
include_directories(${GTEST_INCLUDE})
include_directories(${LIBTOY_INCLUDE})

add_executable(testsuite1 testsuite1.cpp)
target_link_libraries(testsuite1 gtest_main libtoy)



