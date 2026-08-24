class Solution {
    bool solver(int i,string s,vector<vector<int>> &dp,int open){
        int n = s.size();
        if(open<0) return false;
        if(i==n) return open == 0;
        if(dp[i][open]!=-1) return dp[i][open];
        if(s[i]=='('){
            return dp[i][open]=solver(i+1,s,dp,open+1);
        }
        else if(s[i]==')'){
            return dp[i][open]=solver(i+1,s,dp,open-1);
        }
        else if(s[i]=='*'){
            bool left = solver(i+1,s,dp,open+1);
            bool right = solver(i+1,s,dp,open-1);
            bool non = solver(i+1,s,dp,open);
            return dp[i][open] = (left || right || non);
        }
        return dp[i][open]=false;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solver(0,s,dp,0);
    }
};
