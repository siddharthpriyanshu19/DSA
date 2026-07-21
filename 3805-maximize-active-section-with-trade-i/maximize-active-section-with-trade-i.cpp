class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        vector<pair<char, int>> segments;
        for (char c : t) {
            if (!segments.empty() && segments.back().first == c) {
                segments.back().second++;
            } else {
                segments.push_back({c, 1});
            }
        }
        
        
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        
        int maxDelta = 0;
        int m = segments.size();
        
        for (int i = 1; i < m - 1; ++i) {
            if (segments[i].first == '1' && segments[i - 1].first == '0' && segments[i + 1].first == '0') {
                int leftZeros = segments[i - 1].second;
                int rightZeros = segments[i + 1].second;
                maxDelta = max(maxDelta, leftZeros + rightZeros);
            }
        }
        
        return totalOnes + maxDelta;
    }
};