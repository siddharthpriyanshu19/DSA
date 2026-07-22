#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Segment {
        int type;
        int l, r;
        int len;
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // Count total ones in original string s
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        // 1. Decompose string s into consecutive segments
        vector<Segment> segs;
        vector<int> seg_idx(n);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int type = s[i] - '0';
            int seg_id = segs.size();
            segs.push_back({type, i, j - 1, j - i});
            for (int k = i; k < j; ++k) {
                seg_idx[k] = seg_id;
            }
            i = j;
        }
        
        int m = segs.size();
        
        // 2. Precompute gain values for full segments
        vector<int> gain_val(m, 0);
        for (int i = 0; i < m; ++i) {
            if (segs[i].type == 1) {
                if (i - 1 >= 0 && i + 1 < m) {
                    gain_val[i] = segs[i - 1].len + segs[i + 1].len;
                }
            }
        }
        
        // 3. Build Sparse Table for Range Maximum Query (RMQ)
        int LOG = 0;
        while ((1 << LOG) <= m) LOG++;
        if (LOG == 0) LOG = 1;
        
        vector<vector<int>> st(LOG, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            st[0][i] = gain_val[i];
        }
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i + (1 << k) <= m; ++i) {
                st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
        
        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int k = 31 - __builtin_clz(R - L + 1);
            return max(st[k][L], st[k][R - (1 << k) + 1]);
        };
        
        // Helper function to evaluate exact gain for a candidate segment j
        auto get_exact_gain = [&](int j, int l, int r) -> int {
            if (j < 0 || j >= m || segs[j].type != 1) return 0;
            // Segment j must be fully inside [l, r]
            if (segs[j].l < l || segs[j].r > r) return 0;
            // Neighboring 0-segments must overlap with [l, r]
            if (j - 1 < 0 || segs[j - 1].r < l) return 0;
            if (j + 1 >= m || segs[j + 1].l > r) return 0;
            
            int left_gain = min(segs[j - 1].len, segs[j - 1].r - l + 1);
            int right_gain = min(segs[j + 1].len, r - segs[j + 1].l + 1);
            return left_gain + right_gain;
        };
        
        // 4. Answer each query
        vector<int> ans(queries.size());
        
        for (int q = 0; q < queries.size(); ++q) {
            int l = queries[q][0];
            int r = queries[q][1];
            
            
            int seg_l = seg_idx[l];
            int j_first = (segs[seg_l].l >= l) ? seg_l : seg_l + 1;
            
            
            int seg_r = seg_idx[r];
            int j_last = (segs[seg_r].r <= r) ? seg_r : seg_r - 1;
            
            int max_gain = 0;
            
            if (j_first <= j_last) {
                
                for (int j : {j_first, j_first + 1, j_last - 1, j_last}) {
                    if (j >= j_first && j <= j_last) {
                        max_gain = max(max_gain, get_exact_gain(j, l, r));
                    }
                }
                
                
                int int_L = j_first + 1;
                int int_R = j_last - 1;
                if (int_L <= int_R) {
                    max_gain = max(max_gain, query_st(int_L, int_R));
                }
            }
            
            ans[q] = total_ones + max_gain;
        }
        
        return ans;
    }
};