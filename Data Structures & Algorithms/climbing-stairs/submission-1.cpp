class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];
        
        int one = solve(n-1);
        int two = solve(n-2);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(n);
    }
};
