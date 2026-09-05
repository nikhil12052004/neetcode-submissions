class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n+1, 0);
        // taking 0 index
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<=n-1; i++){
            int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }
        int res1 = dp[n-1];
        dp.clear();
        dp.assign(n + 1, 0);
        // skipping 0 index
        dp[0] = 0;
        dp[1] = 0; // skipping this 
        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }
        int res2 = dp[n];
        return max(res1, res2);
    }
};
