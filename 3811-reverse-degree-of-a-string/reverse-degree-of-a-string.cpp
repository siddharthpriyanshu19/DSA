class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int pos = 1;

        for (char ch : s) {
            int rev = 26 - (ch - 'a');

            sum += pos * rev;
            pos++;
        }

        return sum;
    }
};