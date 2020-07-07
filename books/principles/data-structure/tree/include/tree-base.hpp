#ifndef __TREE_BASE_H__
#define __TREE_BASE_H__

#include <cstdlib>

typedef char ElementType;

typedef struct tagTreeNode {
    tagTreeNode *left;
    tagTreeNode *right;

    ElementType data;
} TreeNode;

class BaseTree {
public:
    BaseTree(){}
    ~BaseTree(){}

    TreeNode *create_node(ElementType data){
        TreeNode *node;
        node = (TreeNode *)malloc(sizeof(TreeNode));

        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    void destroy_node(TreeNode *node){
        free(node);
    }

    void destroy_tree(TreeNode *node){
        if(NULL != node->right) {
            destroy_node(node->right);
        }

        if(NULL != node->left) {
            destroy_node(node->left);
        }
        node->left = NULL;
        node->right = NULL;
        node->data = '\0';
        this->destroy_node(node);
    }
protected:
private:
};

#endif