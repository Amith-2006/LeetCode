class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int flag=0;
         
         for(int i = s.length()-1;i>=0;i--){
            if(s[i]==' ' && flag == 0)
                continue;
                
            else if(s[i]!=' '){
                flag=1;
            }
            else if(s[i]==' ')
                break;
            
            len++;

         }

         return len;
    }
};