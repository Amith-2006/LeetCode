class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        findCombinations(0, target, candidates, ans, ds);

        return ans;
    }

    void findCombinations(int index, int target, vector<int>& arr,
                          vector<vector<int>>& ans, vector<int>& ds) {

        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < arr.size(); i++){

            if(arr[i] > target)
                break;

            ds.push_back(arr[i]);

            findCombinations(i, target - arr[i], arr, ans, ds);

            ds.pop_back();
        }
    }
};