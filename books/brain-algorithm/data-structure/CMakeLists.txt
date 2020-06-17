cmake_minimum_required (VERSION 3.5.1)

add_definitions (-std=c++11)

set (GTEST_INC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/include)
set (GTEST_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)
set (TREE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tree)

include_directories(${TREE_SRC} ${GTEST_INC})
link_directories(${GTEST_LIB})

## ========== operating ==========
set (LCRS_TREE_FILES ${TREE_SRC}/test-LCRS-tree.cc ${TREE_SRC}/LCRS-tree.cc)
add_executable (LCRS-tree ${LCRS_TREE_FILES})
target_link_libraries (LCRS-tree PUBLIC gtest)

set (SBT_TREE_FILES ${TREE_SRC}/test-SBT-tree.cc ${TREE_SRC}/SBT-tree.cc)
add_executable (SBT-tree ${SBT_TREE_FILES})
target_link_libraries (SBT-tree PUBLIC gtest)