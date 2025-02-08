//problem link : https://leetcode.com/problems/design-a-number-container-system/description/

#include <bits/stdc++.h>
using namespace std;
class NumberContainers {
    public:
        map<int, int>k2v;
        map<int, set<int>> v2k;
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if (k2v.find(index)!=k2v.end())
            {
                v2k[k2v[index]].erase(index);
            }
            k2v[index]=number;
            v2k[number].insert(index);
        }
        
        int find(int number) {
            if(v2k[number].size()==0) return -1;
            return *v2k[number].begin();
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */