class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>char_count(26,0);
        int res=0;

        int l=0;
        int r=0;
        
        while(r<s.size()){
            char_count[s[r]-'A']++;

            if((r-l+1)-*max_element(char_count.begin(),char_count.end())>k){
                char_count[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};