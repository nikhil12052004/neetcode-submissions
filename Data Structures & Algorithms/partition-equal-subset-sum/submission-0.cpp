class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int> &nums, int idx, int rem){
        int n = nums.size();
        if(idx == n) return false;
        if(rem == 0) return true; 
        if(dp[idx][rem] != -1) return dp[idx][rem];
        
        bool take = false;
        if(nums[idx] <= rem){
            take = solve(nums, idx+1, rem-nums[idx]);
        }
        bool not_take = solve(nums, idx+1, rem);
        return dp[idx][rem] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if((sum%2) != 0) return false;
        int rem = sum/2;
        dp.resize(n+1, vector<int>(rem+1, -1));
        return solve(nums, 0, rem);
    }
};
