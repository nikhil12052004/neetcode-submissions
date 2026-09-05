class Solution {
public:
    vector<vector<int>> dp;
    int solve(string word1, string word2, int n, int m){
        
        //word 1 khatam ho gya, yaani word 2 ke last char delete kro
        if(n == 0) return m;
        // word 2 khatam yaani, word 1 ke last mei char add kro
        if(m == 0) return n;

        if(dp[n][m] != -1) return dp[n][m];

        if(word1[n-1] == word2[m-1]) return solve(word1, word2, n-1, m-1);
        
        int insert = 1 + solve(word1, word2, n, m-1);
        int del = 1 + solve(word1, word2, n-1, m);
        int rep = 1 + solve(word1, word2, n-1, m-1);

        return dp[n][m] = min(insert, min(del, rep));

    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, n, m);
    }
};
