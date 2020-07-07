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
set (SEARCH_INC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SEARCH_LIB ${CMAKE_CURRENT_SOURCE_DIR}/libs)

include_directories(${SEARCH_INC})

## ========== library ==========
set (SEARCH_LIB_FILES ${SEARCH_LIB}/binary-search.cc 
                      ${SEARCH_LIB}/binary-search-tree.cc 
                      ${SEARCH_LIB}/sequential-search.cc
                      ${SEARCH_LIB}/red-black-tree.cc)
add_library (tsearch STATIC ${SEARCH_LIB_FILES})

## ========== operating ==========
set (SEARCH_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test-search.cc 
                  ${SEARCH_LIB_FILES})
add_executable (test_search ${SEARCH_FILES})
target_link_libraries (test_search PUBLIC gtest) 

set (BENCHMARK_SEARCH_FILES ${CMAKE_CURRENT_SOURCE_DIR}/benchmark-search.cc 
                            ${SEARCH_LIB_FILES})
add_executable (benchmark_search ${BENCHMARK_SEARCH_FILES})
target_link_libraries (benchmark_search PUBLIC benchmark)

## ========== custon target ==========
add_custom_target (run_test_search
  COMMAND test_search
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "run generated test_search in ${CMAKE_CURRENT_BINARY_DIR}"
  SOURCES ${SEARCH_FILES}
)

add_custom_target (run_benchmark_search
  COMMAND benchmark_search
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "run generated test_search in ${CMAKE_CURRENT_BINARY_DIR}"
  SOURCES ${BENCHMARK_SEARCH_FILES}
)