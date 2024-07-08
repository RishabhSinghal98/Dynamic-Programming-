
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));


       for(int i=n-1;i>=0;i--)
       {
        for(int buy=0;buy<=1;buy++)
        {
            for(int limit=1;limit<=2;limit++)
            {
                
            if(buy==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             dp[i][buy][limit]=max(-prices[i]+dp[i+1][0][limit] , dp[i+1][1][limit]);

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both and if we sell that means we have completed one transaction and we decrease the limit by -1
        
        dp[i][buy][limit] = max(prices[i] + dp[i+1][1][limit-1],dp[i+1][0][limit]);
       }


            }
        
        }

       }

       

       return dp[0][1][2];

    }
};