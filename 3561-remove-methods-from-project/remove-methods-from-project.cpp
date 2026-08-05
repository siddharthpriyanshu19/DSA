class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> sus(n, false);

        for (auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        // BFS starting from method k
        queue<int> q;
        q.push(k);
        sus[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int ngh : adj[curr]) {
                if (!sus[ngh]) {
                    sus[ngh] = true;
                    q.push(ngh);
                }
            }
        }

        // Check if any non-suspicious node invokes a suspicious node
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];
            if (!sus[u] && sus[v]) {
                // Return all methods [0, n-1] if removal is invalid
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }

        // Collect remaining non-suspicious methods
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};