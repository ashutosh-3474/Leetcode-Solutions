class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int lmax = 0, rmax = 0 , total =0, l=0, r=n-1;

        while(l<r)
        {
            if (h[l]<=h[r])
            {
                if (h[l] <= lmax) total += (lmax - h[l]);
                else lmax = h[l];
                l++;
            }
            else 
            {
                if (h[r] <= rmax) total += (rmax - h[r]);
                else rmax = h[r];
                r--;
            }

        }
        return total;
    }
};