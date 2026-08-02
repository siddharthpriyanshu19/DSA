class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> rem;
        rem[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int r = sum % k;

            if (rem.count(r)) {
                if (i - rem[r] >= 2)
                    return true;
            } else {
                rem[r] = i;
            }
        }
        return false;
    }
};
