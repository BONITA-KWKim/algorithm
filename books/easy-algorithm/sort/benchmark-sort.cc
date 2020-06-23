#include "benchmark/benchmark.h"

#include "insertion-sort.h"
#include "selection-sort.h"
#include "bubble-sort.h"
#include "quick-sort.h"

void test_insertion_sort (void) {
    int test_arr[6] = {3, 6, 4, 8, 9, 7};

    Sort *sort = new InsertionSort();
    sort->sort(test_arr, 6);
}

static void BM_InsertionSort(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_insertion_sort();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_InsertionSort);

void test_selection_sort (void) {
    int test_arr[6] = {3, 6, 4, 8, 9, 7};

    Sort *sort = new SelectionSort();
    sort->sort(test_arr, 6);
}

static void BM_SelectionSort(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_selection_sort();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SelectionSort);

void test_bubble_sort (void) {
    int test_arr[6] = {3, 6, 4, 8, 9, 7};

    Sort *sort = new BubbleSort();
    sort->sort(test_arr, 6);
}

static void BM_BubbleSort(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_bubble_sort();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_BubbleSort);

void test_best_case_bubble_sort (void) {
    int test_arr[6] = {3, 4, 6, 7, 8, 9};

    Sort *sort = new BubbleSort();
    sort->sort(test_arr, 6);
}
static void BM_Best_Case_BubbleSort(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_best_case_bubble_sort();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_Best_Case_BubbleSort);

void test_quick_sort (void) {
    int test_arr[6] = {3, 6, 4, 8, 9, 7};

    Sort *sort = new QuickSort();
    sort->sort(test_arr, 0, 5);
}

static void BM_QuickSort(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    test_quick_sort();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_QuickSort);

// Run the benchmark
BENCHMARK_MAIN();