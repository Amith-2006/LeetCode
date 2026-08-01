class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> res;
        for(int n:nums ){
            mp[n]++;
        }

    vector<pair<int,int>> freq(mp.begin(), mp.end());
    
    sort(freq.begin(), freq.end(),
        [](const auto &a, const auto &b){
                return a.second > b.second;
          });    

    for(int i=0;i<k;i++){
        res.push_back(freq[i].first);
    }
    return res;
    }
};