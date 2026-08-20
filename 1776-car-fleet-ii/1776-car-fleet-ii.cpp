class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1);
        vector<int> st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty()){
                int j = st.back();

                if(cars[i][1]<=cars[j][1]){
                    st.pop_back();
                    continue;
                }

                double t = (double)((cars[j][0]-cars[i][0]))/
                                    (cars[i][1]-cars[j][1]);

                if(res[j]==-1 || t<res[j]){
                    res[i]=t;
                    break;
                }

                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};