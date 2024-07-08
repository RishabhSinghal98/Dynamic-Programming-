
class Solution {
public:
    
    int solve(int i,int buyflag,vector<int>& prices, vector<vector<int>>&dp)
    {

       if(i==prices.size()) return 0;

       int profit=0;

       if(dp[i][buyflag]!=-1) return dp[i][buyflag];
      
       // case 1 : You can buy if buyflag is set to 1

       if(buyflag==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             dp[i][buyflag]=max(-prices[i]+solve(i+1,0,prices,dp) , 0+solve(i+1,1,prices,dp));

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both
        dp[i][buyflag]=max(+prices[i]+solve(i+1,1,prices,dp),0+solve(i+1,0,prices,dp));
       }

       return dp[i][buyflag];


    }

  
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       
       vector<vector<int>> dp(n,vector<int>(2,-1));   // since prices can go upto n and flag value can go upto 2 either 1 or 0
       return solve(0,1,prices,dp);

       

    }
};