#include "benchmark/benchmark.h"

#include "binary-search-tree.h"

void test_binary_tree_search (void) {
    int search_target = 8;
    std::string tree_elements = "";

    BinarySearchTree *bst_tree = new BinarySearchTree();
    BSTNode *head = bst_tree->create_node(1);
    BSTNode *node1 = bst_tree->create_node(2);
    BSTNode *node2 = bst_tree->create_node(3);
    BSTNode *node3 = bst_tree->create_node(4);
    BSTNode *node4 = bst_tree->create_node(5);
    BSTNode *node5 = bst_tree->create_node(6);
    BSTNode *node6 = bst_tree->create_node(7);
    BSTNode *node7 = bst_tree->create_node(8);

    bst_tree->insert_node(head, node1);
    bst_tree->insert_node(head, node2);
    bst_tree->insert_node(head, node3);
    bst_tree->insert_node(head, node4);
    bst_tree->insert_node(head, node5);
    bst_tree->insert_node(head, node6);
    bst_tree->insert_node(head, node7);

    bst_tree->inorder_print_tree (&tree_elements, head);
    
    tree_elements = "";
    bst_tree->remove_node(head, 2);
    bst_tree->remove_node(head, 4);
    bst_tree->remove_node(head, 7);

    bst_tree->inorder_print_tree (&tree_elements, head);

    // test search
    BSTNode *test_search = bst_tree->search_node(head, search_target);

    bst_tree->destroy_tree(head);
}

static void BM_BinarySearchTree(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_binary_tree_search();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_BinarySearchTree);

// Run the benchmark
BENCHMARK_MAIN();