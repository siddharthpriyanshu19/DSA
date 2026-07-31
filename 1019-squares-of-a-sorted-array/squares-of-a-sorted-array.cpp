class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        //find i, j i is pointing at last negative and j points at first positive;
        int j=0;
        vector<int> ans;
        for(j;j<n; j++){
            if(nums[j]>=0){
                break;
            }
        }
        int i = j-1;

        while(i>=0 && j<n){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if(a<b){
                ans.push_back(a);
                i--;
            }
            else {
                ans.push_back(b);
                j++;
            }

            
        }
        //running again if any one of i or j gets exhausted
        while(i>=0){
            int val = nums[i--];
            ans.push_back(val*val);
        }
        while(j<n){
            int val = nums[j++];
            ans.push_back(val*val);
        }

        return ans;


    }
};