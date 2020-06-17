#include "gtest/gtest.h"
#include "LCRS-tree.h"

LCRSNode *make_test_tree(void);
void remove_test_tree (LCRSNode *root);

TEST(LCRSTreeTEST, testCreateNode) 
{
    char test = 'a';
    LCRSTree *tree = new LCRSTree();
    LCRSNode *node = tree->create_LCRS_node(test);

    EXPECT_EQ(NULL, node->left);
    EXPECT_EQ(NULL, node->right);
    EXPECT_EQ(test, node->data);
}

LCRSNode *make_test_tree (void)
{
    LCRSTree *tree = new LCRSTree();
    LCRSNode *root = tree->create_LCRS_node('a');
    LCRSNode *node1 = tree->create_LCRS_node('b');
    LCRSNode *node2 = tree->create_LCRS_node('c');
    LCRSNode *node3 = tree->create_LCRS_node('d');
    LCRSNode *node4 = tree->create_LCRS_node('e');
    LCRSNode *node5 = tree->create_LCRS_node('f');
    LCRSNode *node6 = tree->create_LCRS_node('g');
    LCRSNode *node7 = tree->create_LCRS_node('h');

    /// a
    /// b - c ---- d
    ///     e - f  g
    ///         h
    tree->add_child(root, node1);
    tree->add_child(root, node2);
    tree->add_child(root, node3);

    tree->add_child(node2, node4);
    tree->add_child(node2, node5);

    tree->add_child(node3, node6);

    tree->add_child(node5, node7);
}

void remove_test_tree (LCRSNode *root)
{   
    LCRSTree *tree = new LCRSTree();
    tree->destroy_LCRS_tree(root);
}

int main(int argc, char *argv[])
{
    LCRSTree *tree = new LCRSTree();
    tree->version_info();

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}