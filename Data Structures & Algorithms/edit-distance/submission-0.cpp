class Solution {
public:
    vector<vector<int>> dp;
    int solve(string word1, string word2, int i, int j){
        int n = word1.length();
        int m = word2.length();
        //word 1 khatam ho gya, yaani word 2 ke last char delete kro
        if(i == n) return m-j;
        // word 2 khatam yaani, word 1 ke last mei char add kro
        if(j == m) return n-i;

        if(word1[i] == word2[j]) return solve(word1, word2, i+1, j+1);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int insert = 1 + solve(word1, word2, i, j+1);
        int del = 1 + solve(word1, word2, i+1, j);
        int rep = 1 + solve(word1, word2, i+1, j+1);

        return dp[i][j] = min(insert, min(del, rep));

    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0);
    }
};
