class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int j = 1;
        int maxi = 0;
        while(j<n){
            if(prices[j] < prices[i]){
                i = j;
            }
            else if(prices[j] - prices[i] > maxi){
                maxi = prices[j] - prices[i];
            }
            j++;
        }
        return maxi;
    }
};
