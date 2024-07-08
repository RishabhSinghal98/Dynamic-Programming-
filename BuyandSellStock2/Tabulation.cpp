
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       
       vector<vector<int>> dp(n+1,vector<int>(2,0));   // since prices can go upto n and flag value can go upto 2 either 1 or 0
       
       
       dp[n][0]=dp[n][1]=0 ; // since base case says if index==n do it zero 

       // filling the table

       for(int i=n-1;i>=0;i--)
       {
        for(int buyflag=0;buyflag<=1;buyflag++)
        {


       if(buyflag==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             dp[i][buyflag]=max(-prices[i]+dp[i+1][0] , dp[i+1][1]);

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both
        dp[i][buyflag]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
       }



        }
       }
       
      return dp[0][1];
    }
};