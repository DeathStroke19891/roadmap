#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
int main()
{
    Solution sol;
    int k=2;
    vector<int> nums={1,1,1,2,2,3};
    
    auto res = sol.topKFrequent(nums, k);
    for(auto j:res)
    {
       cout<<j<<" ";
    }
    cout<< endl;
}
