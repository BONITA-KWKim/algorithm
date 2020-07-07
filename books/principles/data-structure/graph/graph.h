#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>

typedef int ElementType;

typedef struct tagVertex {
    ElementType data;
    int visited;
    int index;

    struct tagVertex *next;
    struct tagEdge *adjacent;
} TVertex;

typedef struct tagEdge {
    int weight;
    struct tagEdge *next;
    TVertex *from;
    TVertex *target;
} TEdge;

typedef struct tagGraph {
    TVertex *vertex;
    int graph_size;
} TGraph;

class Graph {
public:
    Graph(){};
    ~Graph(){};

    TGraph *create_graph (void);
    void destroy_graph (TGraph *graph);

    TVertex *create_vertex (ElementType data);
    void destroy_vertex (TVertex *vertex);

    TEdge *create_edge (TVertex *from, TVertex *target, int weight);
    void destroy_edge (TEdge *edge);

    void add_vertex (TGraph *graph, TVertex *vertex);
    void add_edge (TVertex *vertex, TEdge *edge);
    
    void print_graph (TGraph *graph);
private:
};

#endif