class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> pair;
        pair.reserve(n);

        for(int i=0;i<n;i++){
            pair.push_back({position[i],speed[i]});
        }

        sort(pair.rbegin(),pair.rend());

        vector<double> st;  // we use this vector as stack
        st.reserve(n);      
        // reserves n spaces which avoids repeated reallocations while inserting pairs

        for(auto p : pair){
            double time = (double)(target-p.first)/p.second;
            st.push_back(time);

            if(st.size()>=2 && st.back()<=st[st.size()-2]){  
                //since u cant access 2nd element from top using stack , we used a vector
                st.pop_back();
            }
        }

        return st.size();
    }
};