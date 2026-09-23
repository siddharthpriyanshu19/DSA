class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int x: nums){
            total += x;
        }
        int target = total-x;
        if(target<0) return -1;
        if(target==0) return n;
        int minlen = -1;
        int sum =0;
        for(int i=0,j=0; j<n; j++){
            sum += nums[j];
            while(sum>target && i<j){
                sum -= nums[i];
                i++;
            }
            if(sum == target){
                minlen = max(minlen, (j-i+1));

            }
        }
        return (minlen == -1) ? -1 : nums.size() - minlen;

    }
};