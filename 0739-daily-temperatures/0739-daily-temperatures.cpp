class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        vector<int> stack(temperatures.size());
        int top=-1;

        for(int i=0;i<temperatures.size();i++){
            while(top>=0 && temperatures[i]>temperatures[stack[top]]){
                res[stack[top]]=i-stack[top];
                top--;
            }

            stack[++top]=i;
        }

        return res;
    }
};