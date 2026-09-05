class Solution {
public:
    vector<int> leftmax(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n);
        ans[0] = heights[0];
        for(int i = 1; i<n; i++){
            ans[i] = max(ans[i-1], heights[i]);
        }
        return ans;
    }
    vector<int> rightmax(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n);
        ans[n-1] = heights[n-1];
        for(int i = n-2; i>=0; i--){
            ans[i] = max(ans[i+1], heights[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lefty = leftmax(height);
        vector<int> righty = rightmax(height);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int width = 1;
            int h = min(lefty[i], righty[i]) - height[i];
            ans += width*h;
        }
        return ans;
    }
};
