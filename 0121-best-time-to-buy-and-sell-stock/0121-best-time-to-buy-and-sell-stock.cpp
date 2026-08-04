class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty()){
            return 0;
        }

        int maxprofit=0;
        int minprice=INT_MAX;

        for(int i=0;i<prices.size();i++){
            minprice=min(prices[i],minprice);
            maxprofit=max(maxprofit,prices[i]-minprice);

        }

        return maxprofit;
    }
};