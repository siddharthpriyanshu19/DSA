class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && (j - i + 1) <= r; j++) {
                sum += nums[j];
                if ((j - i + 1) >= l && sum > 0) {
                    minsum = min(minsum, sum);
                }
            }
        }

        return (minsum == INT_MAX) ? -1 : minsum;
    }
};