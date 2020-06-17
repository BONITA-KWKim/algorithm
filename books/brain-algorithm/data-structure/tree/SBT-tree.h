#ifndef __SBT_TREE_H__
#define __SBT_TREE_H__

#include <iostream>
#include <cstring>
#include "tree-base.h"

typedef TreeNode SBTNode;

class SBTTree: public BaseTree {
public:
    SBTTree();
    ~SBTTree();

    void version_info();
    SBTNode *create_SBT_node (ElementType);
    void destroy_SBT_node (SBTNode *);
    void destroy_SBT_tree (SBTNode *);

    void preorder_print (SBTNode *);
    void preorder_print (std::string *, SBTNode *);
    void inorder_print (SBTNode *);
    void inorder_print (std::string *result, SBTNode *node);
    void postorder_print (SBTNode *);
    void postorder_print (std::string *result, SBTNode *node);
private:
};

#endif