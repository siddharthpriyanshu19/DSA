class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<vector<bool>> pal;

    bool isPalindrome(string &s, int i, int j) {
        return pal[i][j];
    }

    int solve(string &s, int k, int i, int j) {
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (isPalindrome(s, i, j)) {

            int take = 1 + solve(s, k, j + 1, j + k);

            int grow = solve(s, k, i, j + 1);

            int slide = solve(s, k, i + 1, j + 1);

            return dp[i][j] = max({take, grow, slide});
        }
        else {

            int grow = solve(s, k, i, j + 1);

            int slide = solve(s, k, i + 1, j + 1);

            return dp[i][j] = max(grow, slide);
        }
    }

    int maxPalindromes(string s, int k) {
        n = s.size();

        // Precompute palindrome substrings
        pal.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // Memoization table
        dp.assign(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1);
    }
};