class Solution {
private:
    // Helper function to calculate multinomial permutations capped at (target_k + 1)
    long long countPermutations(const vector<int>& cnt, int target_k) {
        int n = 0;
        int max_idx = 0;
        for (int i = 0; i < 26; ++i) {
            n += cnt[i];
            if (cnt[i] > cnt[max_idx]) {
                max_idx = i;
            }
        }
        
        long long y = 1;
        for (int i = 0; i < 26; ++i) {
            if (i == max_idx || cnt[i] == 0) continue;
            for (int j = 1; j <= cnt[i]; ++j) {
                y = (y * n) / j;
                n--;
                if (y > target_k) return target_k + 1;
            }
        }
        return y;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> total_cnt(26, 0);
        for (char c : s) {
            total_cnt[c - 'a']++;
        }
        
        vector<int> cnt(26, 0);
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            cnt[i] = total_cnt[i] / 2;
            if (total_cnt[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
        }
        
        // If the total distinct arrangements are fewer than k, return empty string
        long long total = countPermutations(cnt, k);
        if (total < k) {
            return "";
        }
        
        int m = n / 2;
        string first_half = "";
        first_half.reserve(m);
        
        // Build the first half character by character
        for (int pos = 0; pos < m; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) continue;
                
                cnt[c]--;
                long long ways = countPermutations(cnt, k);
                
                if (ways >= k) {
                    first_half.push_back('a' + c);
                    break;
                } else {
                    k -= ways;
                    cnt[c]++; // Backtrack and try next character
                }
            }
        }
        
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        if (n % 2 == 1) {
            return first_half + mid_char + second_half;
        } else {
            return first_half + second_half;
        }
    }
};