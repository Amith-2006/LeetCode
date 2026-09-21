class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<=nums[(i+1)%n]){
                continue;
            }
            else if(flag==0){
                flag =1;
            }
            else if(flag==1){
                return false;
            }
        }

        return true;
    }
};