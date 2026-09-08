class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        long long cnt = 0;
        int i = 1000;
        while(i>=1000 && i<=n){
            if(i==100000){
                cnt = cnt+1;
            }
            else{
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};