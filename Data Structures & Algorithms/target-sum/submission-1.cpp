class Solution {
public:
    vector<vector<int>> dp;
    int s = 0;
    int solve(vector<int>& nums, int target, int curr, int idx){
        int n = nums.size();
        if(idx == n){
            return curr == target;
        }
        if(dp[idx][curr + s] != -1) return dp[idx][curr + s];
        int plus = solve(nums, target, curr + nums[idx], idx+1);
        int minus = solve(nums, target, curr - nums[idx], idx+1);
        return dp[idx][curr + s] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            s += nums[i];
        }
        dp.resize(n+1, vector<int>((2*s) + 1, -1));
        return solve(nums, target, 0, 0);
    }
};
