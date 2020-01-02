#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

void TwoWayPartition(std::vector<int> &v) {
  if (v.empty()) {
    return;
  }
  int low = 0;
  int high = v.size() - 1;
  while (low <= high) {
    if (v[low] == 0) {
      ++low;
    } else {
      std::swap(v[low], v[high]);
      --high;
    }
  }
}

void ThreeWayPartition(std::vector<int> &v) {
  if (v.empty()) {
    return;
  }
  int low = 0;
  int mid = 0;
  int high = v.size() - 1;
  while (mid <= high) {
    if (v[mid] == 0) {
      std::swap(v[low], v[mid]);
      ++low;
      ++mid;
    } else if (v[mid] == 1) {
      ++mid;
    } else {
      std::swap(v[mid], v[high]);
      --high;
    }
  }
}

void PrintVector(const std::vector<int> &v) {
  for (const auto &ele : v) {
    std::cout << ele << "\t";
  }
  std::cout << std::endl;
}

int main() {
  // Two partition
  std::vector<int> v1;
  v1.push_back(0);
  v1.push_back(1);
  v1.push_back(0);
  v1.push_back(1);
  v1.push_back(0);
  v1.push_back(0);
  v1.push_back(1);
  TwoWayPartition(v1);
  PrintVector(v1);
  // Three partition
  std::vector<int> v2;
  v2.push_back(0);
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(0);
  v2.push_back(2);
  v2.push_back(2);
  v2.push_back(1);
  ThreeWayPartition(v2);
  PrintVector(v2);
  return 0;
}