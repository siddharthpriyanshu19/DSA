class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int z= 0;
        int xr=0;
        for (int i =0; i<n; i++){
           xr = xr^nums[i];
            if(nums[i]==0) z++;

        }
        if(z==n){return 0;}
        if(xr != 0){ return n;}
        return n-1;
        
    }
};