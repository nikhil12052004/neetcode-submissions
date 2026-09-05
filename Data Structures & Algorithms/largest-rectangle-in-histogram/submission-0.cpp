class Solution {
public:
    vector<int> lse(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> rse(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lefty = lse(heights);
        vector<int> righty = rse(heights);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            int width = righty[i] - lefty[i] - 1;
            int curr = heights[i] * width;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
