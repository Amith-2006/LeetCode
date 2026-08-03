class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
             return 0;

        int l=0;
        int r=height.size()-1;
        int leftmax=height[l],rightmax=height[r];
        int res=0;
        while(l<r){
            if(leftmax<rightmax){
                l++;
                leftmax=max(leftmax,height[l]);
                res+=leftmax-height[l]; 
                /* Since we are checking every index individually we consider it as unit width*/
            }
            else{
                r--;
                rightmax=max(rightmax,height[r]);
                res+=rightmax-height[r];
            }
        }
        return res;
    }
};  