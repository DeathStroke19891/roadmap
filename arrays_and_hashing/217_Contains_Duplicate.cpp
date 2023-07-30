#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> map;
        for(auto i = nums.begin(); i < nums.end() ; i++){
            map[*i]++;
            if(map[*i]>=2){
                return true;
            }
        }
        return false;
    }
};
int main(){
  Solution sol;
  vector<int> nums = {1, 2, 3, 1};
  bool res = sol.containsDuplicate(nums);
  cout << res << endl;
}
