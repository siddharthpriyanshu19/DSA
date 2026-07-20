class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> firstIndex;
        firstIndex[0] = -1;

        int prefix = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefix += (nums[i] == 0 ? -1 : 1);

            if(firstIndex.count(prefix))
                ans = max(ans, i - firstIndex[prefix]);
            else
                firstIndex[prefix] = i;
        }

        return ans;
    }
};