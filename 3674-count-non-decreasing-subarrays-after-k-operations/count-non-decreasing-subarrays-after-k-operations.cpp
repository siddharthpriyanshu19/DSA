#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        int r = n - 1;
        
        // {ceiling_value, element_count}
        deque<pair<long long, long long>> dq;

        for (int l = n - 1; l >= 0; --l) {
            long long val = nums[l];
            long long cnt = 1;

            // 1. Absorb blocks on the left whose ceiling <= nums[l]
            while (!dq.empty() && dq.front().first <= val) {
                auto [old_val, old_cnt] = dq.front();
                dq.pop_front();
                ops += (val - old_val) * old_cnt;
                cnt += old_cnt;
            }
            dq.push_front({val, cnt});

            // 2. Shrink window from the right until ops <= k
            while (ops > k) {
                ops -= (dq.back().first - nums[r]);
                dq.back().second--;
                if (dq.back().second == 0) {
                    dq.pop_back();
                }
                r--;
            }

            // 3. Add all valid subarrays starting at index l
            ans += (r - l + 1);
        }

        return ans;
    }
};