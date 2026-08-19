class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> pairs;
        pairs.reserve(n);

        for(int i = 0; i < n; i++)
            pairs.push_back({position[i], speed[i]});

        sort(pairs.rbegin(), pairs.rend());

        double last = 0;
        int fleets = 0;

        for(auto &p : pairs) {
            double time = (double)(target - p.first) / p.second;

            if(time > last) {
                fleets++;
                last = time;
            }
        }

        return fleets;
    }
};