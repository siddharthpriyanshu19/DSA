class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> prefix(1002,0);
        int n = trips.size();
        for(auto &it : trips){
           int l = it[1];
           int r = it[2];
           prefix[l] +=it[0];
           prefix[r]+= -it[0];

        }
        for(int i=1; i<1002; i++){
            prefix[i] = prefix[i-1]+prefix[i];
        }
        int tp = 0;

        for(int i=0; i<1002; i++){
            if(prefix[i]>capacity) return false;
            else continue;
        }
        return true;
    }
};