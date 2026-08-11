class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int res;
         for(int i =0;i<tokens.size();i++){
            if(tokens[i]=="+"|| tokens[i]=="-"|| tokens[i]=="*"|| tokens[i]=="/"){
                
                int operand1=st.top();
                st.pop();

                int operand2=st.top();
                st.pop();

                switch(tokens[i][0]){
                    case '+':   res = operand2+operand1; break;
                    case '-':   res = operand2-operand1; break;
                    case '*':   res = operand2*operand1; break;
                    case '/':   res = operand2/operand1; break;
                }

                st.push(res);     
            }
            else st.push(stoi(tokens[i])); //converts strinf to integer
         }

         return st.top();
    }
};