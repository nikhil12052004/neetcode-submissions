class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s, int i, int j){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(s, i+1, j-1);
        return dp[i][j] = false;

    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int sp;
        dp.resize(n, vector<int>(n, -1));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(solve(s, i, j) == true){
                    if(maxlen < j-i+1){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};
