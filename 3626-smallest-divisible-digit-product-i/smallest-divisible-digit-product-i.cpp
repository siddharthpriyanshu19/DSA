class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(i<=100 && i>0){
            int curr = i;
            int prod=1;
            while (curr > 0) {
                prod *= (curr % 10);
                curr /= 10;
            }
            if((prod)%t==0){
                break;
            }
            else{
                i++;
            }
        }
        return i;
    }
};