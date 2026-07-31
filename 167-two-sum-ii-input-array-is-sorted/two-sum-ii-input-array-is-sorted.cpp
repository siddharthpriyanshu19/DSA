class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        int left = 0;
        int right = n-1;
        int sum =0;
        while(left<right){
            sum = numbers[left]+numbers[right];
            if(sum>target){
                sum = sum-numbers[right];
                right--;
            }
            else if(sum < target){
                sum = sum-numbers[left];
                left++;
            }
            else{
                break;
            }
        }
        
            


        
        ans.push_back(left+1);
        ans.push_back(right+1);

        return ans;


    }
};