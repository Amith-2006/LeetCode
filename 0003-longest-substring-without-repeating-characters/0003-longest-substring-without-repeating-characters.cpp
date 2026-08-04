class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;
        int l=0;
        int maxlen=0;
        
        for(int r=0;r<s.size();r++){

            while(st.find(s[r]) != st.end()){
                st.erase(s[l++]);
            }

            st.insert(s[r]);

            maxlen=max(maxlen,r-l+1);
        }

        return maxlen;
    }
};