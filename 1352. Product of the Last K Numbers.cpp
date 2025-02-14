//1352. Product of the Last K Numbers
// Problem link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14

#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    public:
        vector<long long > v;
        int n=0;
        int lz=-1;
        ProductOfNumbers() {
            v.push_back(1);
        }
        
        void add(int num) {
            if (num==0) {
                v={1};
                n=0;
                return;
            }
            v.push_back(v[n]*num);
            n++;
    
        }
        
        int getProduct(int k) {
            if (n==0) return NULL;
            if (k>n) return 0;
            return v[n]/v[n-k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */