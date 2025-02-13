//3066. Minimum Operations to Exceed Threshold Value II
// Problem link : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue <long long , vector<long long >, greater<long long > > q; 
            for (auto it: nums) q.push(it);
            int cnt=0;
            while(q.size()>=2 && q.top()<k)
            {
                long long  a=q.top()*2;
                q.pop();
                a+=q.top();
                q.pop();
                q.push(a);
                cnt++;
    
            }
            cout<<q.top();
            return cnt;
        }
    };