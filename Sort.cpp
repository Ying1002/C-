#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <vector>

void WriteArray(const std::vector<int> &arr) {
  for (const int i : arr) {
    std::cout << i << "\t";
  }
  std::cout << std::endl;
}

void InsertionSort(std::vector<int> &arr) {
  for (int i = 1; i < arr.size(); ++i) {
    int value = arr[i];
    int j = i;
    while (j > 0) {
      if (arr[j] < arr[j - 1]) {
        std::swap(arr[j], arr[j - 1]);
        --j;
      } else {
        break;
      }
    }
  }
}

std::vector<int> MergeSort(const std::vector<int> &arr, const int start,
                           int end) {
  if (start == end) {
    return std::vector<int>{arr[start]};
  }
  int mid = (start + end) / 2;
  std::vector<int> first = MergeSort(arr, start, mid);
  std::vector<int> second = MergeSort(arr, mid + 1, end);
  int i = 0;
  int j = 0;
  int length = end - start + 1;
  std::vector<int> merged;
  merged.resize(length);
  for (int num = 0; num < length; ++num) {
    if ((j >= second.size() || first[i] < second[j]) && i < first.size()) {
      merged[num] = first[i];
      ++i;
    } else {
      merged[num] = second[j];
      ++j;
    }
  }
  return merged;
}

int main() {
  std::vector<int> arr{1,  3,  5,  8,  6,  4,  2,  7,  9, 11,
                       15, 13, 12, 29, 18, 21, 30, 16, 4};

  auto start = std::chrono::high_resolution_clock::now();
  auto sorted = MergeSort(arr, 0, arr.size() - 1);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << duration.count() << std::endl;
  WriteArray(sorted);

  start = std::chrono::high_resolution_clock::now();
  InsertionSort(arr);
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << duration.count() << std::endl;
  WriteArray(arr);
  return 0;
}