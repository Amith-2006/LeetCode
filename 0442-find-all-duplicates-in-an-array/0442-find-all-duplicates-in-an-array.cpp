class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int>res;
        
        for(int i=0;i<nums.size();i++){

            if(!mp.count(nums[i])){
                mp[nums[i]]==1;
            }
            else{
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};