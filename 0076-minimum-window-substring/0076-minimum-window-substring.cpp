class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        unordered_map<char,int> window;

        for(char c : t) {
            mp[c]++;
        }

        int l = 0;
        int r = 0;

        int have = 0;
        int min_size = INT_MAX;
        int start = 0;

        while(r < s.size()) {

            window[s[r]]++;

            if(mp.count(s[r]) && window[s[r]] <= mp[s[r]]) {
                have++;
            }

            while(have == t.size()) {

                if(r - l + 1 < min_size) {
                    min_size = r - l + 1;
                    start = l;
                }

                window[s[l]]--;

                if(mp.count(s[l]) && window[s[l]] < mp[s[l]]) {
                    have--;
                }

                l++;
            }

            r++;
        }

        if(min_size == INT_MAX)
            return "";

        return s.substr(start, min_size);
    }
};