#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> um;
    for (auto &s : strs) {
      string temp = s;
      sort(temp.begin(), temp.end());
      um[temp].push_back(s);
    }
    for (auto &p : um) {
      ans.push_back(p.second);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = sol.groupAnagrams(input);
  for (auto i = res.begin(); i != res.end(); i++) {
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }
}
