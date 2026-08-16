class Solution {
public:
    bool solve(vector<int>& stones){
        int n = stones.size();
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int x : stones){
            if(x%3==0) c0++;
            else if(x%3==1) c1++;
            else c2++;

        }

        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }

        return abs(c1 - c2) > 2;

    }
    bool stoneGameIX(vector<int>& stones) {
      return solve(stones);  
    }
};