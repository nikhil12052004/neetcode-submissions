class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto it : wordList){
            st.insert(it);
        }
        if(st.find(endWord) == st.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            for(int i = 0; i<word.length(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    if(ch == original) continue;
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, level+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
