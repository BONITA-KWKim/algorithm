#include "SBT-tree.h"

SBTTree::SBTTree()
{

}

SBTTree::~SBTTree()
{

}

void SBTTree::version_info ()
{
    std::cout << "Version V0.1.0" << std::endl;
}

TreeNode *SBTTree::create_SBT_node (ElementType data)
{
    return BaseTree::create_node(data);
}

void SBTTree::destroy_SBT_node (SBTNode *node)
{
    return BaseTree::destroy_node(node);
}

void SBTTree::destroy_SBT_tree (SBTNode *node)
{
    return BaseTree::destroy_tree(node);
}

void SBTTree::preorder_print (SBTNode *node)
{
    if (NULL == node) return;

    std::cout << node->data << " ";
    preorder_print(node->left);
    preorder_print(node->right);
}

void SBTTree::preorder_print (std::string *result, SBTNode *node)
{
    if (NULL == node) return;

    *result += node->data;
    *result +=  " ";
    preorder_print(result, node->left);
    preorder_print(result, node->right);
}


void SBTTree::inorder_print (SBTNode *node)
{
    if (NULL == node) return;

    inorder_print(node->left);
    std::cout << node->data << " ";
    inorder_print(node->right);
}

void SBTTree::inorder_print (std::string *result, SBTNode *node)
{
    if (NULL == node) return;

    inorder_print(result, node->left);
    *result += node->data;
    *result +=  " ";
    inorder_print(result, node->right);
}

void SBTTree::postorder_print (SBTNode *node)
{
    if (NULL == node) return;

    postorder_print(node->left);
    postorder_print(node->right);
    std::cout << node->data << " ";
}

void SBTTree::postorder_print (std::string *result, SBTNode *node)
{
    if (NULL == node) return;

    postorder_print(result, node->left);
    postorder_print(result, node->right);
    *result += node->data;
    *result +=  " ";
}