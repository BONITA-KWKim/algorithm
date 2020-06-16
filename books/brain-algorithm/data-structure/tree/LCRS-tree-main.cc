#include "LCRS-tree.h"

int main(void)
{
    std::cout << "Hello" << std::endl;

    LCRSTree *tree = new LCRSTree();

    LCRSNode *head = tree->create_LCRS_tree('a');
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
    tree->add_child(head, node1);
    tree->add_child(head, node2);
    tree->add_child(head, node3);

    tree->add_child(node2, node4);
    tree->add_child(node2, node5);

    tree->add_child(node3, node6);

    tree->add_child(node5, node7);

    /// show tree
    tree->print_tree();

    return 0;
}