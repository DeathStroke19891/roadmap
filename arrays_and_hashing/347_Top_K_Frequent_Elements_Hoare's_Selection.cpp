#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> unique;
    map<int, int> count_map;

public:
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = count_map[unique[pivot_index]];
        swap(unique[pivot_index], unique[right]);
        int store_index = left;
        for (int i = left; i <= right; i++) {
            if (count_map[unique[i]] < pivot_frequency) {
                swap(unique[store_index], unique[i]);
                store_index += 1;
            }
        }
        swap(unique[right], unique[store_index]);
        return store_index;
    }
    void quickselect(int left, int right, int k_smallest) {
        if (left == right) return;
        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(left, right, pivot_index);
        if (k_smallest == pivot_index) {
            return;
        } else if (k_smallest < pivot_index) {
            quickselect(left, pivot_index - 1, k_smallest);
        } else {
            quickselect(pivot_index + 1, right, k_smallest);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n : nums) {
            count_map[n] += 1;
        }
        int n = count_map.size();
        for (pair<int, int> p : count_map) {
            unique.push_back(p.first);
        }
        quickselect(0, n - 1, n - k);
        vector<int> top_k_frequent(k);
        copy(unique.begin() + n - k, unique.end(), top_k_frequent.begin());
        return top_k_frequent;
    }
};
int main(){
  Solution sol;
  vector<int> nums = {1, 3, 5, 3, 7, 9, 2, 4, 6};
  auto res = sol.topKFrequent(nums, 3);
  for(auto x: res){
    cout << x << " ";
  }
  cout << endl;
}
