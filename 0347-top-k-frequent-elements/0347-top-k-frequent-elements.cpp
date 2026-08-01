class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(int n:nums ){
            mp[n]++;
        }

    vector<vector<int>>bucket(nums.size()+1);

    for(auto p: mp)
        bucket[p.second].push_back(p.first);

        vector<int>res;

    for(int i=bucket.size()-1;i>=0&&res.size()<k;i--){
       
       for(auto num:bucket[i])
        res.push_back(num);

        if(res.size()==k)
            break;
    }
    return res;
    }
};