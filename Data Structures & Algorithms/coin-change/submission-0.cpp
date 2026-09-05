class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(int coin : coins){

            int temp = solve(coins, amount - coin);

            if(temp != INT_MAX){
                ans = min(ans, 1 + temp);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);

        int ans = solve(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
