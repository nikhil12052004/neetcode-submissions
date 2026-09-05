class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];

            if (auto it = mpp.find(rem); it != mpp.end())
                return {it->second, i};

            mpp[nums[i]] = i;
        }

        return {};
    }
};