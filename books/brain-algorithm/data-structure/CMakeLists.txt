cmake_minimum_required (VERSION 3.5.1)

add_definitions (-std=c++11)

set (TREE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tree)

include_directories(${TREE_SRC})

## ========== operating ==========
set (TREE_FILES ${TREE_SRC}/LCRS-tree-main.cc ${TREE_SRC}/LCRS-tree.cc)
add_executable (LCRS-tree ${TREE_FILES})