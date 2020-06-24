#include <iostream>
#include <string>
#include "gtest/gtest.h"

#include "sequential-search.h"
#include "binary-search-tree.h"

TEST (SEQUENTIAL, TEST_CASE_001) {
    BaseSearch *search = new SequentialSearch();

    EXPECT_EQ(0, 0);
}

TEST (BINARY_SEARCH_TREE, TEST_CASE_001) {
    int search_target = 8;
    std::string tree_elements = "";

    BinarySearchTree *bst_tree = new BinarySearchTree();
    BSTNode *head = bst_tree->create_node(1);
    BSTNode *node1 = bst_tree->create_node(2);
    BSTNode *node2 = bst_tree->create_node(3);
    BSTNode *node3 = bst_tree->create_node(4);
    BSTNode *node4 = bst_tree->create_node(5);
    BSTNode *node5 = bst_tree->create_node(6);
    BSTNode *node6 = bst_tree->create_node(7);
    BSTNode *node7 = bst_tree->create_node(8);

    bst_tree->insert_node(head, node1);
    bst_tree->insert_node(head, node2);
    bst_tree->insert_node(head, node3);
    bst_tree->insert_node(head, node4);
    bst_tree->insert_node(head, node5);
    bst_tree->insert_node(head, node6);
    bst_tree->insert_node(head, node7);

    bst_tree->inorder_print_tree (&tree_elements, head);
    EXPECT_STREQ("1 2 3 4 5 6 7 8 ", tree_elements.c_str());
    
    tree_elements = "";
    bst_tree->remove_node(head, 2);
    bst_tree->remove_node(head, 4);
    bst_tree->remove_node(head, 7);

    bst_tree->inorder_print_tree (&tree_elements, head);
    EXPECT_STREQ("1 3 5 6 8 ", tree_elements.c_str());

    // test search
    BSTNode *test_search = bst_tree->search_node(head, search_target);

    EXPECT_EQ(search_target, test_search->data);

}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}