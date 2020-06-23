cmake_minimum_required (VERSION 3.5.1)

add_definitions (-std=c++11)

set (GTEST_INC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/include)
set (GTEST_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)
set (TREE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../data-structure/tree) 
set (SEARCH_INC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${SEARCH_INC} ${GTEST_INC} ${TREE_DIR}/include)
link_directories(${GTEST_LIB} ${TREE_DIR}/libs)

## ========== operating ==========
set (SEARCH_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test-search.cc)
add_executable (test_search ${SEARCH_FILES})
target_link_libraries (test_search PUBLIC gtest tree)

add_custom_target(run_test
  COMMAND test_search
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "run generated test_search in ${CMAKE_CURRENT_BINARY_DIR}"
  SOURCES ${SEARCH_FILES}
)