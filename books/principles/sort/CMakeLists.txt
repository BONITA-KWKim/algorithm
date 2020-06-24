cmake_minimum_required (VERSION 3.5.1)

add_definitions (-std=c++11)

set (GTEST_INC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/include)
set (GTEST_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)
set (SORT_SRC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${SORT_SRC} ${GTEST_INC})
link_directories(${GTEST_LIB})

## ========== operating ==========
set (SORT_FILES ${SORT_SRC}/test-sort.cc)
add_executable (TEST_SORT ${SORT_FILES})
target_link_libraries (TEST_SORT PUBLIC gtest)
