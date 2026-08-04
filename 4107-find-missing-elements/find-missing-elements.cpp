class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        vector<int> ans;
        int i = nums[0];
        int j = 0;
        while(i<=nums[n-1] && j<n){
            if(i != nums[j]){
                ans.push_back(i);
                i++;
            }
            else{
                i++;
                j++;
            }
        }
       return ans;
        
    }
};