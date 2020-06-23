#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <cstdlib>

typedef struct tagBSTNode {
    int data;

    tagBSTNode *left;
    tagBSTNode *right;
} BSTNode;

class BinarySearchTree{
public:
    BinarySearchTree(){};
    ~BinarySearchTree(){};

    // create
    BSTNode *create_node (int data) {
        BSTNode *node;
        node = (BSTNode *)malloc(sizeof(BSTNode));

        node->data = data;
        node->data = data;
        node->data = data;

        return node;
    }
    // insert
    void insert_node (BSTNode *head, BSTNode *node) {
        if (NULL == head || NULL == node) return;

        BSTNode *tmp = head;
        while (NULL != tmp) {
            if (tmp->data > node->data) {
                if (NULL == tmp->left) {
                    tmp->left = node;
                    continue;
                } else {
                    tmp = tmp->left
                }
            } else {
                if (NULL == tmp->right) {
                    tmp->right = node;
                    continue;
                } else {
                    tmp = tmp->right;
                }
            }
        }
    }
    // delete
    // remove
    void remove_node (BSTNode *node) {
        free(node);
    }

    void remove_tree (BSTNode *node) {
        if(NULL != node->right) {
            remove_node(node->right);
        }

        if(NULL != node->left) {
            remove_node(node->left);
        }
        node->left = NULL;
        node->right = NULL;
        node->data = 0;
        this->remove_node(node);
    }
    // print
    void print_tree (BSTNode *heazd) {
        return;
    }
private:
};

#endif