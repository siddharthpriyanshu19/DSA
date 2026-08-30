class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        pair<int,int> minele = {INT_MAX, -1};
        pair<int,int> maxele = {INT_MIN, -1};

        for (int i = 0; i < n; i++) {
            minele = min(minele, {nums[i], i});
            maxele = max(maxele, {nums[i], i});
        }

        int minIdx = minele.second;
        int maxIdx = maxele.second;

        int left = max(minIdx, maxIdx) + 1;

        int right = n - min(minIdx, maxIdx);

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        int both = (l + 1) + (n - r);

        return min({left, right, both});
    }
};