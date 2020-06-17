#ifndef __LCRS_tree_H__
#define __LCRS_tree_H__

#include <iostream>
#include "tree-base.h"

typedef TreeNode LCRSNode;

class LCRSTree: public BaseTree {
public:
    LCRSTree();
    ~LCRSTree();

    LCRSNode *create_LCRS_node(ElementType);
    void destroy_LCRS_node (LCRSNode *);
    void destroy_LCRS_tree(LCRSNode *);

    void add_child(LCRSNode *, LCRSNode *);
    void print_tree(LCRSNode *, int depth=0);

    void version_info();
private:
};

#endif