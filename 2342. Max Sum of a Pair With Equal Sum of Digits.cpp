// 2342. Max Sum of a Pair With Equal Sum of Digits
//Problem Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            map<int, vector<int>> mp;
            for (int i=0;i<nums.size();i++)
            {
                int x=nums[i];
                int sum=0;
                while(x)
                {
                    sum+=x%10;
                    x/=10;
                }
                cout<<sum<<" ";
                mp[sum].push_back(nums[i]);
            }
            int mx=-1;
            for (auto it : mp)
            {
                auto v=it.second;
                sort(v.begin(),v.end());
                int m=v.size();
                if (m>=2)
                {
                    mx=max(mx, v[m-1]+v[m-2]);
                }
            }
            return mx;
        }
    };