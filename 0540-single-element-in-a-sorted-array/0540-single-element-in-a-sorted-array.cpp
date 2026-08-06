class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;

        while(high>low){
            int mid=(high+low)/2;

            if(mid%2!=0){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                low=mid+2;
            }
            else
                high=mid;
        }
        return nums[low];
    }
};