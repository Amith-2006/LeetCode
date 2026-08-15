class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        long long hours;
        int ans;
        
        while(left<=right){
            int mid = (left+right)/2;
            hours=0;
            for(int pile : piles){
                hours += ceil((double)pile/mid); // even a partially eaten pile takes a full hour
            }

            if(hours>h) left=mid+1;
            else{
                right=mid-1;
                ans =mid;
            }
        }

        return ans;
    }
};