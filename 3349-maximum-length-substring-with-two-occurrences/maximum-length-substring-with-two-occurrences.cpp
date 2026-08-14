class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n = s.size();
       unordered_map<char, int> freq;
       int i=0;
       int j=0;
       int maxlen = INT_MIN;
       while(j<n){
        freq[s[j]]++;
        while(freq[s[j]]>2){
            freq[s[i]]--;
            i++;

        }
        maxlen = max(maxlen, j-i+1);
        j++;

        
       }
       return maxlen;
    }
};