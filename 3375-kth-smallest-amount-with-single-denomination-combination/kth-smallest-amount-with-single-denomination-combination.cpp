class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;

        auto count = [&](long long x) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = __builtin_popcount(mask);
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) {
                        l = lcm(l, (long long)coins[j]);
                        if (l > x) break; // avoid overflow / wasted work
                    }
                }
                if (l > x) continue;
                total += (bits % 2 ? 1 : -1) * (x / l);
            }
            return total;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};