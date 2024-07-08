
class Solution {
public:
    
    int solve(int i,int buyflag,vector<int>& prices, vector<vector<vector<int>>>&dp,int limit)
    {
       if(limit==0) return 0;

       if(i==prices.size()) return 0;

      

       if(dp[i][buyflag][limit]!=-1) return dp[i][buyflag][limit];
      
       // case 1 : You can buy if buyflag is set to 1

       if(buyflag==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             dp[i][buyflag][limit]=max(-prices[i]+solve(i+1,0,prices,dp,limit) , 0+solve(i+1,1,prices,dp,limit));

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both and if we sell that means we have completed one transaction and we decrease the limit by -1
        dp[i][buyflag][limit]=max(+prices[i]+solve(i+1,1,prices,dp,limit-1),0+solve(i+1,0,prices,dp,limit));
       }

       return dp[i][buyflag][limit];


    }

  
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));   
       return solve(0,1,prices,dp,2);

       

    }
};