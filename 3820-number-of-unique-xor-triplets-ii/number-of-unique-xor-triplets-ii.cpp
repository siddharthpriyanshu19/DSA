class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> has_pair(2048, false);
        vector<bool> has_triplet(2048, false);

        for (int k = 0; k < n; ++k) {
            // 1. Add all pairs ending at index k: nums[i] ^ nums[k] for 0 <= i <= k
            for (int i = 0; i <= k; ++i) {
                has_pair[nums[i] ^ nums[k]] = true;
            }

            // 2. Combine all existing pair XORs with nums[k]
            for (int v = 0; v < 2048; ++v) {
                if (has_pair[v]) {
                    has_triplet[v ^ nums[k]] = true;
                }
            }
        }

        int count = 0;
        for (int v = 0; v < 2048; ++v) {
            if (has_triplet[v]) count++;
        }

        return count;
    }
};