#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

#include <iostream>
#include <cstdlib>
#include <string>

enum Color {RED, BLACK};

typedef struct tagRBTNode {
    tagRBTNode *parent;
    tagRBTNode *left;
    tagRBTNode *right;

    Color color;

    int data;
} RBTNode;

class RedBlackTree {
public:
    RedBlackTree();
    ~RedBlackTree();

    void version_info (void);
    void version_info (std::string &);

    RBTNode *create_node (int);

    void destroy_node (RBTNode *);
    void destroy_tree (RBTNode *);
private:
    RBTNode *Nil;
};

#endif