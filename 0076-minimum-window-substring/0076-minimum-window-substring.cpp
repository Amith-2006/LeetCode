class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for(char c : t) {
            need[c]++;
        }

        int l = 0;
        int have = 0;
        int minSize = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++) {

            window[s[r]]++;

            if(window[s[r]] <= need[s[r]]) {
                have++;
            }

            while(have == t.size()) {

                if(r - l + 1 < minSize) {
                    minSize = r - l + 1;
                    start = l;
                }

                window[s[l]]--;

                if(window[s[l]] < need[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        if(minSize == INT_MAX) {
            return "";
        }

        return s.substr(start, minSize);
    }
};