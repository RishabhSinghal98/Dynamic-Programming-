class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int buy_price=prices[0];
        int profit=0,max_profit=0;
        for(int i=1;i<len;i++)
        {
            
            
                profit=prices[i]-buy_price;
                max_profit=max(profit,max_profit);

                buy_price=min(buy_price,prices[i]);
            
            
        }
        return max_profit;
       
    }
};