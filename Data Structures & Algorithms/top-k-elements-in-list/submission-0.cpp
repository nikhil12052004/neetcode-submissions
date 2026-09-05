class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // map - value, freq
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it : mpp){
            v.push_back(it);
        }
        sort(v.begin(), v.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
