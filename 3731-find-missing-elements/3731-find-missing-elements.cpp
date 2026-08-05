class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    vector<int> st(mx - mn + 1, 0);
    vector<int>res;

    for (int x : nums)
        st[x - mn]++;

    for (int i = 0; i < st.size(); i++){
        if (st[i] == 0)
            res.push_back(i + mn);
    }

        return res;

    }
};