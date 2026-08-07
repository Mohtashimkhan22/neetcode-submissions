class Solution {
    bool solver(string &s, unordered_set<string> &st, int i, vector<int> &dp) {
        int n = s.size();
        if (i == n)
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int j = i; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if (st.count(str) && solver(s, st, j + 1, dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solver(s, st, 0, dp);
    }
};