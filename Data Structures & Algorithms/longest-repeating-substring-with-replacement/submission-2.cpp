class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;

        int maxlen = 0;
        int maxfreq = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            mpp[s[right]]++;
            maxfreq = max(maxfreq, mpp[s[right]]);
            // shrinking - jab currlen - maxfreq > k
            while( right - left + 1 - maxfreq > k){
                mpp[s[left]]--;
                // reinitialize maxfreq
                maxfreq = 0;
                for(auto it : mpp){
                    maxfreq = max(maxfreq, it.second);
                }
                left++;
            }
            if(right - left + 1 - maxfreq <= k){
                maxlen = max(maxlen, right - left + 1);
            }
        }
        return maxlen;
    }
};
