#include <gtest/gtest.h>
#include "SBT-tree.h"

SBTNode *make_test_tree (void);

TEST(TEST_SBT, testCreateTree) 
{
    SBTTree *tree = new SBTTree();

    SBTNode *test_node = tree->create_SBT_node('a');

    EXPECT_EQ('a', test_node->data);

    tree->destroy_SBT_node(test_node);
}

TEST(TEST_SBT, testPreorderPrintTree) 
{
    SBTTree *tree = new SBTTree();
    SBTNode *test_tree = make_test_tree();

    std::string res = "";
    tree->preorder_print(&res, test_tree);

    std::string expected_str = "a b c d e f g ";
    EXPECT_STREQ(res.c_str(), expected_str.c_str());

    tree->destroy_SBT_tree(test_tree);
}

TEST(TEST_SBT, testInorderPrintTree) 
{
    SBTTree *tree = new SBTTree();
    SBTNode *test_tree = make_test_tree();

    std::string res = "";
    tree->inorder_print(&res, test_tree);

    std::string expected_str = "c b d a f e g ";
    EXPECT_STREQ(res.c_str(), expected_str.c_str());

    tree->destroy_SBT_tree(test_tree);
}

TEST(TEST_SBT, testPostorderPrintTree) 
{
    SBTTree *tree = new SBTTree();
    SBTNode *test_tree = make_test_tree();

    std::string res = "";
    tree->postorder_print(&res, test_tree);

    std::string expected_str = "c d b f g e a ";
    EXPECT_STREQ(res.c_str(), expected_str.c_str());

    tree->destroy_SBT_tree(test_tree);
}

SBTNode *make_test_tree (void)
{
    SBTTree *tree = new SBTTree();

    SBTNode *root = tree->create_SBT_node('a');
    SBTNode *node1 = tree->create_SBT_node('b');
    SBTNode *node2 = tree->create_SBT_node('c');
    SBTNode *node3 = tree->create_SBT_node('d');
    SBTNode *node4 = tree->create_SBT_node('e');
    SBTNode *node5 = tree->create_SBT_node('f');
    SBTNode *node6 = tree->create_SBT_node('g');

    root->left = node1;
    node1->left = node2;
    node1->right = node3;

    root->right = node4;
    node4->left = node5;
    node4->right = node6;

    return root;
} 

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    SBTTree *tree = new SBTTree();
    tree->version_info();

    return RUN_ALL_TESTS();
}