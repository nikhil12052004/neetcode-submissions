class Solution {
public:
    vector<string> ans;
    void solve(string &digits, string &str, int ind, unordered_map<char, string>&mpp){
        if(ind >= digits.length()){
            ans.push_back(str);
            return;
        }
        char ch = digits[ind];
        string temp = mpp[ch];
        for(int i = 0; i<temp.size(); i++){
            str.push_back(temp[i]);
            solve(digits, str, ind+1, mpp);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string str = "";
        solve(digits, str, 0, mpp);
        return ans;
    }
};
