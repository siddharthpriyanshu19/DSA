class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp_min(n,0); // stores min ele from i-n-1
        vector<int> dp_max(n,0); // stores max ele from 0-i

        dp_max[0] = nums[0];
        dp_min[n-1] = nums[n-1];

        int i =1;
        int j = n-2;

        while(i<n && j>=0){
            dp_max[i] = max(dp_max[i-1],nums[i]);
            dp_min[j] = min(dp_min[j+1], nums[j]);
            i++;
            j--;
        }
        int idx = n;
        for(int i = 0; i<n; i++){
            if((dp_max[i]-dp_min[i])<=k){
                idx = min(i,idx);
            }
        }

        return idx == n ? -1 : idx;

        
    }
};