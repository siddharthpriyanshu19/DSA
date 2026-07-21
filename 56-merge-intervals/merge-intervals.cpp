class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> prefix(20005,0);
        int n = intervals.size();
        for(auto &it : intervals){
            int l = 2*it[0];
            int r = 2*it[1];
            prefix[l]++;
            prefix[r+1]--;

        }
        for(int i =1; i<20005; i++){
            prefix[i] = prefix[i-1] + prefix[i];
        }

        vector<vector<int>> ans;
        int lastzero = -1;
        for(int i =0; i<20005; i++){
           if(prefix[i]>0){
            int start = i;
            int j=i;
            while(i<20005 && prefix[i]>0){
                i++;
            }
            int end = i-1;
            ans.push_back({start/2,end/2});
           }
        }
        return ans;

    }
};