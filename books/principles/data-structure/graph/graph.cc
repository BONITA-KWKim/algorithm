#include "graph.h"

TGraph *Graph::create_graph (void) {
    TGraph *graph = (TGraph *)malloc(sizeof(TGraph));

    graph->vertex = NULL;
    graph->graph_size = 0;

    return graph;
}

void Graph::destroy_graph (TGraph *graph) {
    free(graph);
}

TVertex *Graph::create_vertex (ElementType data) {
    TVertex *vertex = (TVertex *)malloc(sizeof(TVertex));

    vertex->data = data;
    vertex->visited = 0;
    vertex->index = -1;

    vertex->next = NULL;
    vertex->adjacent = NULL;

    return vertex;
}

void Graph::destroy_vertex (TVertex *vertex) {
    free(vertex);
}

TEdge *Graph::create_edge (TVertex *from, TVertex *target, int weight) {
    TEdge *edge = (TEdge *)malloc(sizeof(TEdge));

    edge->weight = weight;
    edge->next = NULL;
    edge->from = from;
    edge->target = target;

    return edge;
}

void Graph::destroy_edge (TEdge *edge) {
    free(edge);
}

void Graph::add_vertex (TGraph *graph, TVertex *vertex) {
    if (NULL == graph) return;

    TVertex *tmp = graph->vertex;
    if (NULL == tmp) {
        graph->vertex = vertex;
    } else {
        while (NULL != tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = vertex;
    }

    ++graph->graph_size;
}

void Graph::add_edge (TVertex *vertex, TEdge *edge) {
    if (NULL == vertex || NULL == edge) return;

    TEdge *tmp = NULL;
    if (NULL == (tmp = vertex->adjacent)) {
        vertex->adjacent = edge;
        return;
    } 

    while (NULL != tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = edge;
}

void Graph::print_graph (TGraph *graph) {
    if (NULL == graph || 0 >= graph->graph_size) return;

    TVertex *printed_vertex = NULL;
    TEdge *printed_edge = NULL;

    if (NULL == (printed_vertex = graph->vertex)) return;
    
    std::cout << "Graph size: " << graph->graph_size << std::endl;
    while (NULL != printed_vertex) {
        std::cout << "vertex: " << printed_vertex->data << ", ";
        printed_edge = printed_vertex->adjacent;
        while (NULL != printed_edge) {
            std::cout << printed_edge->target->data << "[" << printed_edge->weight << "], ";
            printed_edge = printed_edge->next;
        }

        std::cout << std::endl;
        printed_vertex = printed_vertex->next;
    }
}
