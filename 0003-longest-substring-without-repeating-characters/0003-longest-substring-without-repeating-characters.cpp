class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> freq(128, 0);
        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < s.size(); r++) {

            while (freq[s[r]] > 0) {
                freq[s[l]]--;
                l++;
            }

            freq[s[r]]++;
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};