#include <iostream>
#include <vector>
#include <mutex>
#include <chrono> // Include chrono for timing
#include <algorithm> // For std::sort
#include "mergeSort.cpp"
#include "parallelMergeSort.cpp"

int main(int argc, char *argv[]) {

    const int SIZE = 1e7; // 10 million elements
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);
    std::vector<int> nums2(SIZE); // For std::sort

    for (int i = 0; i < SIZE; ++i) {
        int val = rand() % 10000000;
        nums[i] = val;
        nums1[i] = val;
        nums2[i] = val;
    }

    // Measure time for MergeSort
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;

    std::cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort;

    // Measure time for std::sort
    start = std::chrono::high_resolution_clock::now();
    std::sort(nums2.begin(), nums2.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdSortDuration = end - start;

    std::cout << "std::sort time taken: " << stdSortDuration.count() << " seconds" << std::endl;

    // Measure time for ParallelMergeSort
    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelMergeSortDuration = end - start;

    std::cout << "ParallelMergeSort time taken: " << parallelMergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort1;

    return 0;
}
