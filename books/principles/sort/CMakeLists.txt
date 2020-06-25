cmake_minimum_required (VERSION 3.5.1)

add_definitions (-std=c++11)

## ========== external library ==========
# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()
# benchmark
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${benchmark_SOURCE_DIR}/include")
endif()

## ========== variables ==========
set (SORT_INC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SORT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/libs)

include_directories(${SORT_INC})

## ========== operating ==========
set (SORT_LIB_FILES ${SORT_LIB}/bubble-sort.cc 
                    ${SORT_LIB}/insertion-sort.cc 
                    ${SORT_LIB}/quick-sort.cc 
                    ${SORT_LIB}/selection-sort.cc)
add_library (tsort STATIC ${SORT_LIB_FILES})

## ========== operating ==========
set (SORT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test-sort.cc 
                ${SORT_LIB_FILES})
add_executable (test_sort ${SORT_FILES})
target_link_libraries (test_sort PUBLIC gtest)

set (BENCHMARK_SORT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/benchmark-sort.cc 
                          ${SORT_LIB_FILES})
add_executable (benchmark_sort ${BENCHMARK_SORT_FILES})
target_link_libraries (benchmark_sort PUBLIC benchmark)

## ========== custon target ==========
add_custom_target (run_test_sort
  COMMAND test_sort
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "run generated test_search in ${CMAKE_CURRENT_BINARY_DIR}"
  SOURCES ${SORT_FILES}
)

add_custom_target (run_benchmark_sort
  COMMAND benchmark_sort
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "run generated test_search in ${CMAKE_CURRENT_BINARY_DIR}"
  SOURCES ${BENCHMARK_SORT_FILES}
)