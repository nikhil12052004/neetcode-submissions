class Solution {
public:
    string check(string &s1, string &s2){
        string ans = "";
        int m = min(s1.length(), s2.length());
        for(int i = 0; i<m; i++){
            if(s1[i] == s2[i]) ans += s1[i];
            else break;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string res = check(strs[0], strs[n-1]);
        return res;
    }
};