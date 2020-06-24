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
    BSTNode *create_node (int data) {
        BSTNode *node;
        node = (BSTNode *)malloc(sizeof(BSTNode));

        node->data = data;
        node->left = NULL;
        node->right = NULL;

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
                    break;;
                } else {
                    tmp = tmp->left;
                }
            } else {
                if (NULL == tmp->right) {
                    tmp->right = node;
                    break;
                } else {
                    tmp = tmp->right;
                }
            }
        }
    }
    // delete
    // remove
    void remove_node (BSTNode *tree, int target) {
        if(NULL == tree) return;

        BSTNode *parent = NULL;
        BSTNode *now = tree;
        while (NULL != now) {
            if (target > now->data) {
                // go to right
                parent = now;
                now = now->right;
            } else if (target < now->data) {
                // go to left
                parent = now;
                now = now->left;
            } else {
                // working
                if (NULL == now->left && NULL == now->right) {
                    // left node
                    if (parent->left == now) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                } else {
                    BSTNode *tmp;
                    // not left node
                    if (NULL != now->left && NULL != now->right) {
                        // not implement
                        // find smallest node
                        BSTNode *smallest_node = this->search_min_node(now);
                        // set the node in now position
                        if (parent->left == now) {
                            parent->left = smallest_node;
                        } else {
                            parent->right = smallest_node;
                        }
                        // remove the node
                        remove_node(now, smallest_node->data);
                    } else {
                        tmp = (NULL != now->left) ? now->left : now->right;

                        if (parent->left == now) {
                            parent->left = tmp;
                        } else {
                            parent->right = tmp;
                        }
                    }
                }

                this->destroy_node(now);
                break;
            }
        }

        return;
    }

    void destroy_node (BSTNode *node) {
        free(node);
    }

    void destroy_tree (BSTNode *node) {
        if(NULL != node->right) {
            this->destroy_node(node->right);
        }

        if(NULL != node->left) {
            this->destroy_node(node->left);
        }
        node->left = NULL;
        node->right = NULL;
        node->data = 0;
        this->destroy_node(node);
    }
    // search
    BSTNode *search_node(BSTNode *root, int target) {
        if(NULL == root) return NULL;

        BSTNode *result = root;
        while (NULL != result) {
            if (target == result->data) {
                break;
            } else {
                if (target > result->data) {
                    result = result->right;
                } else {
                    result = result->left;
                }
            }
        }
        return result;
    }

    BSTNode *search_min_node(BSTNode *node) {
        if(NULL == node) return NULL;

        BSTNode *result = node;
        while (NULL != result) {
            result = result->left;
        }

        return result;
    }

    // print
    void inorder_print_tree (BSTNode *node) {
        if (NULL == node) return;

        inorder_print_tree(node->left);
        std::cout << node->data << " ";
        inorder_print_tree(node->right);
    }

    void inorder_print_tree (std::string *rst, BSTNode *node) {
        if (NULL == node) return;

        inorder_print_tree(rst, node->left);
        *rst += std::to_string(node->data);
        *rst += " ";
        inorder_print_tree(rst, node->right);
    }
private:
};

#endif