#include "gtest/gtest.h"

#include "sequential-search.h"
#include "binary-search-tree.h"

TEST (SEQUENTIAL, TEST_CASE_001) {
    BaseSearch *search = new SequentialSearch();

    EXPECT_EQ(0, 0);
}

TEST (BINARY_SEARCH_TREE, TEST_CASE_001) {
    BinarySearchTree *bst_tree = new BinarySearchTree();
    BSTNode *head = bst_tree->create_node(1);
    bst_tree->remove_node(head);

    EXPECT_EQ(0, head->data);
    EXPECT_EQ(NULL, head->left);
    EXPECT_EQ(NULL, head->right);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}