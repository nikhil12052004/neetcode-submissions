class Solution {
public:
    vector<vector<int>> dp;
    int solve(string text1, string text2, int id1, int id2){
        if(id1 >= text1.size() || id2 >= text2.size()) return 0;
        if(text1[id1] == text2[id2]) return 1 + solve(text1, text2, id1+1, id2+1);
        if(dp[id1][id2] != -1) return dp[id1][id2];
        int left = solve(text1, text2, id1+1, id2);
        int right = solve(text1, text2, id1, id2+1);
        return dp[id1][id2] = max(left, right);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        dp.resize(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(text1, text2, 0, 0);
    }
};
