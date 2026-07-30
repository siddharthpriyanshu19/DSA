class Solution {
public:
    using ll = long long;
    vector<ll>dp;
    ll solve(int idx , auto &nums){
        if(idx >= nums.size() - 1){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        ll ans = INT_MAX;

        for(int j = 1 ; j <= nums[idx] ; j ++){
            if(idx + j < nums.size()){
                ll got = solve(idx + j , nums);

                if(got != INT_MAX){
                    ans = min(ans , 1 + got);
                }
            }
        }

        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size() + 1 , -1);
        return solve(0 , nums);
    }
};