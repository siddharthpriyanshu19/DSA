class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        if(n==1 && nums[0]==target) return 0;
        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid]==target) return mid;

            else if(nums[mid]<=nums[n-1]){ //we are in right part 
                 if(nums[mid]<=target && target<=nums[n-1]) low = mid+1;
                 else high = mid-1;

            }
            else{//left part of array
                if(nums[mid]>=target && target>=nums[0]) high = mid-1;
                else low=mid+1;

            }

        

            
        }
        return -1;
        
    }
};