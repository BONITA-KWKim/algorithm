#include "gtest/gtest.h"

#include "graph.h"

TEST (GRAPH_TEST_CASE, TESTNO_001)
{
    Graph *graph = new Graph();
    TGraph *tgraph = graph->create_graph();

    TVertex *vertex1 = graph->create_vertex(1);
    TVertex *vertex2 = graph->create_vertex(2);
    TVertex *vertex3 = graph->create_vertex(3);
    TVertex *vertex4 = graph->create_vertex(4);
    TVertex *vertex5 = graph->create_vertex(5);

    graph->add_vertex(tgraph, vertex1);
    graph->add_vertex(tgraph, vertex2);
    graph->add_vertex(tgraph, vertex3);
    graph->add_vertex(tgraph, vertex4);
    graph->add_vertex(tgraph, vertex5);

    TEdge *edge1 = graph->create_edge(vertex1, vertex2, 10);
    TEdge *edge2 = graph->create_edge(vertex1, vertex3, 10);
    TEdge *edge3 = graph->create_edge(vertex1, vertex4, 10);
    TEdge *edge4 = graph->create_edge(vertex1, vertex5, 10);
    TEdge *edge5 = graph->create_edge(vertex2, vertex3, 10);
    TEdge *edge6 = graph->create_edge(vertex2, vertex5, 10);
    TEdge *edge7 = graph->create_edge(vertex5, vertex4, 10);

    graph->add_edge(vertex1, edge1);
    graph->add_edge(vertex1, edge2);
    graph->add_edge(vertex1, edge3);
    graph->add_edge(vertex1, edge4);
    graph->add_edge(vertex2, edge2);
    //graph->add_edge(vertex2, edge4);
    //graph->add_edge(vertex5, edge7);

    graph->print_graph(tgraph);

    EXPECT_EQ(0, 0);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}