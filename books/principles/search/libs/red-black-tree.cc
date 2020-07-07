#include "red-black-tree.h"

RedBlackTree::RedBlackTree () {
    this->Nil = this->create_node(0);
    this->Nil->color = BLACK;
}

RedBlackTree::~RedBlackTree () {
    this->destroy_node(this->Nil);
}

void RedBlackTree::version_info (void) {
    std::cout << "Red Black Tree develop-v0.1.0" << std::endl;
}

void RedBlackTree::version_info (std::string &version) {
    version = "Red Black Tree develop-v0.1.0";
}

RBTNode *RedBlackTree::create_node (int data) {
    RBTNode *node = (RBTNode *)malloc(sizeof(RBTNode));

    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = RED;
    node->data = data;

    return node;
}

void RedBlackTree::destroy_node (RBTNode *node) {
    free(node);
}

void RedBlackTree::destroy_tree (RBTNode *node) {
    if (NULL == node) return;

    RBTNode *tmp = node;
    while (NULL != tmp) {
        if (NULL != tmp->left) {
            this->destroy_tree(tmp->left);
        }
        if (NULL != tmp->right) {
            this->destroy_tree(tmp->right);
        }

        node->left = this->Nil;
        node->right = this->Nil;

        destroy_node(node);
    }
}