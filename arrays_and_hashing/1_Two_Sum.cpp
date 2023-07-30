#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (map.count(complement) && map[complement] != i) {
                return {i, map[complement]};
            }
        }
        return {};
    }
};
int main(){
  Solution sol;
  vector<int> nums = {1, 2, 3, 5};
  auto res = sol.twoSum(nums, 5);
  cout << res[0]<<" "<<res[1] << endl;
}
