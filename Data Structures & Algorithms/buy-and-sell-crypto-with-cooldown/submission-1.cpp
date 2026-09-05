class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int n, int day, bool buy){
        int profit = 0;
        if(day >= n) return 0;
        if(dp[day][buy] != -1) return dp[day][buy];
        if(buy){ // we can buy
            int take = solve(prices, n, day+1, false) - prices[day];
            int not_take = solve(prices, n, day+1, true);
            profit = max({profit, take, not_take});
        }
        else{ // we can sell
            int sell = solve(prices, n , day+2, true) + prices[day];
            int not_sell = solve(prices, n, day+1, false);
            profit = max({profit, sell, not_sell});
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(2, -1));
        int buy = true;
        return solve(prices, n, 0, buy);
    }
};
