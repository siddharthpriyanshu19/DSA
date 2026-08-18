class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j=i+k-1;
        vector<int> vis(51,0);
        unordered_map<int, int> mp;
        while(j<n){
            vector<int> vis(51, 0);
            for(int x = i; x<=j; x++){
                if(vis[nums[x]]==0){
                    vis[nums[x]]=1;
                    mp[nums[x]]++;
                }
                else{
                    continue;
                }
            }
            i++;
            j++;

        }
        int maxele = -1;
        for(int x : nums){
            if(mp[x]==1){
                maxele = max(maxele, x);
            }

        }
        return maxele;

    }
};