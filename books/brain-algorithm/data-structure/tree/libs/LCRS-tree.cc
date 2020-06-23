#include "LCRS-tree.h"

LCRSTree::LCRSTree()
{

}

LCRSTree::~LCRSTree()
{

}

void LCRSTree::version_info (void)
{
    std::cout << "LCSR tree Version 0.1.0" << std::endl;
}

LCRSNode *LCRSTree::create_LCRS_node (ElementType data)
{
    return BaseTree::create_node(data);
}

void LCRSTree::destroy_LCRS_node (LCRSNode *node)
{
    return BaseTree::destroy_node(node);
}

void LCRSTree::destroy_LCRS_tree (LCRSNode *node)
{
    return BaseTree::destroy_tree(node);
}

void LCRSTree::add_child(LCRSNode *parent, LCRSNode *node)
{
    if(NULL == parent->left) {
        parent->left = node;
    } else {
        LCRSNode *temp = parent->left;
        while(NULL != temp->right) {
            temp = temp->right;
        }
        temp->right = node;
    }
}

void LCRSTree::print_tree(LCRSNode *node, int depth)
{
    if(NULL == node)
        return;

    for(int i = 0; depth > i; ++i)
        std::cout << "-";

    std::cout << node->data << std::endl;

    if(NULL != node->left) {
        print_tree(node->left, ++depth);
    }

    if(NULL != node->right) {
        print_tree(node->right, depth);
    }
}
