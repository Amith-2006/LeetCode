class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty())
            return 0;
        
        int l=0;
        int r=0;
        int maxlen=1;
        string substring="";

        while(r<s.size()){
           
             if (substring.find(s[r]) == string::npos) {
                substring+=s[r];
            } else {
                int len=substring.size();
                maxlen=max(maxlen,len);
                while (substring.find(s[r]) != string::npos){
                    substring.erase(0,1);
                }
                substring+=s[r];
            }
            r++;
        }

        int len=substring.size();
                maxlen=max(maxlen,len);

        return maxlen;
    }
};