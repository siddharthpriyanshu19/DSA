class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ;
        int high = nums.size()-1;
        int ans = INT_MAX;
        int n = nums.size();
        if(nums[0]<=nums[n-1]) return nums[0];
        while(low<=high){
           int mid = (low+high)/2;
           if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];

           if(nums[mid]>nums[n-1] && nums[0]>=nums[n-1]){ // left part of array
              low = mid+1;
           }
           else{
            high = mid-1;
           }
        }
        return -1;
        
    }
};