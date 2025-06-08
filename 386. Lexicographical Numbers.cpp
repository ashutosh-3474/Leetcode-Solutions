class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int k=1;
        vector<int> ans;
        // ans.push_back(k);
        // while(k*10 <= n)
        // {
        //     k*=10;
        //     ans.push_back(k);
        // }
        for (int i=0;i<n;i++)
        {
            ans.push_back(k);
            if (k*10 <= n)
            {
                k*=10;
            }
            else 
            {
                while (k%10 == 9 || k == n){
                    k/=10;
                    // ans.push_back(k);
                }
                k++;
            }
            
        }
        return ans;
    }
};