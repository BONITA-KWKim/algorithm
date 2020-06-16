#include "LCRS-tree.h"

LCRSTree::LCRSTree()
{
    this->tree = NULL;
}

LCRSTree::~LCRSTree()
{
    destory_LCRS_tree(this->tree);
}

LCRSNode *LCRSTree::create_LCRS_node(ElementType input)
{
    LCRSNode *node;

    node = (LCRSNode*)malloc(sizeof(LCRSNode));

    node->left = NULL;
    node->right = NULL;
    node->data = input;

    return node;
}

LCRSNode *LCRSTree::create_LCRS_tree(ElementType input)
{
    this->tree = create_LCRS_node(input);

    return this->tree;
}

LCRSNode *LCRSTree::create_LCRS_tree(LCRSNode *input)
{
    this->tree = input;

    return this->tree;
}


void LCRSTree::destory_LCRS_tree(LCRSNode *tree)
{
    return;
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


void LCRSTree::print_tree()
{
    if(NULL == this->tree) {
        std::cout << "tree is empty\n";
        return;
    }

    LCRSNode *first = this->tree;
    LCRSNode *temp = NULL;
    while(NULL != first) {
        temp = first;
        std::cout << temp->data << " ";
        while(NULL != temp->right) {
            temp = temp->right;
            std::cout << temp->data << " ";
        }
        std::cout << std::endl;

        first = first->left;
    }
}

LCRSNode *LCRSTree::get_tree()
{
    return this->tree;
}