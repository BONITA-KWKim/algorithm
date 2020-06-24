#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <iostream>
#include <cstdlib>
#include <string>

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
    BSTNode *create_node (int data);
    // insert
    void insert_node (BSTNode *head, BSTNode *node);
    // delete
    // remove
    void remove_node (BSTNode *tree, int target);

    void destroy_node (BSTNode *node);
    void destroy_tree (BSTNode *node);
    // search
    BSTNode *search_node(BSTNode *root, int target);
    BSTNode *search_min_node(BSTNode *node);
    // print
    void inorder_print_tree (BSTNode *node);
    void inorder_print_tree (std::string *rst, BSTNode *node);
private:
};

#endif