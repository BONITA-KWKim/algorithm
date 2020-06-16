#ifndef __LCRS_tree_H__
#define __LCRS_tree_H__

#include <iostream>

typedef char ElementType;

typedef struct tagLCRSNode {
    tagLCRSNode *left;
    tagLCRSNode *right;

    ElementType data;
} LCRSNode;

class LCRSTree {
public:
    LCRSTree();
    ~LCRSTree();

    LCRSNode *create_LCRS_node(ElementType);
    LCRSNode *create_LCRS_tree(ElementType);
    LCRSNode *create_LCRS_tree(LCRSNode *);

    void destory_LCRS_node();
    void destory_LCRS_tree(LCRSNode *);

    void add_child(LCRSNode *, LCRSNode *);
    void print_tree();

    LCRSNode *get_tree();
private:
    LCRSNode *tree;
};

#endif