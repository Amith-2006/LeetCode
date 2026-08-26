class Solution {
public:
    string reverseWords(string s) {
        
        int index = 0;
        string rev = "";

        for(int i = 0; i <= s.size(); i++) {
            
            if(i == s.size() || s[i] == ' ') {
                
                string subs = s.substr(index, i - index);

                for(int j = 0; j < subs.size() / 2; j++) {
                    char temp = subs[j];
                    subs[j] = subs[subs.size() - j - 1];
                    subs[subs.size() - j - 1] = temp;
                }

                rev += subs;

                if(i != s.size())
                    rev += " ";

                index = i + 1;
            }
        }

        return rev;
    }
};