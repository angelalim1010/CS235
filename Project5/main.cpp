#include "SortingTests.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

    size_t ARRAY_SIZE = 100000;
  	int arr[ARRAY_SIZE];

  	generateRandomArray(arr, ARRAY_SIZE);
  	// generateAscendingArray(arr, ARRAY_SIZE);
  	// generateDescendingArray(arr, ARRAY_SIZE);
  	// generateLastTenRandomArray(arr, ARRAY_SIZE);
  	// generateFewRandomArray(arr, ARRAY_SIZE);

  	// double run_time_avg = sortTest(&selectionSort, arr, ARRAY_SIZE);
  	double run_time_avg = mergeSortTest(arr, ARRAY_SIZE);

  	cout << run_time_avg <<"\n";

    return 0;
}
