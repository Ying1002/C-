#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <utility>
#include <vector>

int TwoWayPartition(std::vector<int> &v, int low, int high) {
  int pivot = low;
  while (low <= high) {
    if (v[low] <= v[pivot]) {
      ++low;
    } else {
      std::swap(v[low], v[high]);
      --high;
    }
  }
  std::swap(v[pivot], v[low - 1]);
  return low - 1;
}

std::pair<int, int> ThreeWayPartition(std::vector<int> &v, int low, int high) {
  int pivot = v[low];
  int mid = low;
  while (mid <= high) {
    if (v[mid] < pivot) {
      std::swap(v[low], v[mid]);
      ++low;
      ++mid;
    } else if (v[mid] == pivot) {
      ++mid;
    } else {
      std::swap(v[mid], v[high]);
      --high;
    }
  }
  return std::make_pair(low, high);
}

void ThreeWayQuickSort(std::vector<int> &v, const int low, const int high) {
  if (low < high) {
    auto partition = ThreeWayPartition(v, low, high);
    ThreeWayQuickSort(v, low, partition.first - 1);
    ThreeWayQuickSort(v, partition.second + 1, high);
  }
}

void QuickSort(std::vector<int> &v, const int low, const int high) {
  if (low < high) {
    int partition = TwoWayPartition(v, low, high);
    QuickSort(v, low, partition);
    QuickSort(v, partition + 1, high);
  }
}

void PrintVector(const std::vector<int> &v) {
  for (const auto &ele : v) {
    std::cout << ele << "\t";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(0);
  v.push_back(2);
  v.push_back(5);
  v.push_back(4);
  v.push_back(3);
  v.push_back(7);
  v.push_back(6);
  QuickSort(v, 0, v.size() - 1);
  PrintVector(v);

  std::vector<int> v2{4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4, 4, 9, 1};
  ThreeWayQuickSort(v2, 0, v2.size() - 1);
  PrintVector(v2);
  return 0;
}