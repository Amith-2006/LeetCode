class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int m;
        while(l<r){
            m=(l+r)/2;

            if(nums[m]>nums[r]){
                l=m+1;
            }
            else
                r=m;
        }
        int pivot=l;

        int result = binarysearch(nums,target,0,pivot-1);
        if(result!=-1){
            return result;
        }
        else{
            return binarysearch(nums,target,pivot,nums.size()-1);
        }
    }

    int binarysearch(vector<int> &arr,int target,int left,int right){
        if(arr.empty()) return 0;

        while(left<=right){
            int mid=(left+right)/2;

            if(arr[mid]==target){
                return mid;
            }
            else if(target>arr[mid]){
                left=mid+1;
            }
            else
                right=mid-1;
        }

        return -1;
    }
};