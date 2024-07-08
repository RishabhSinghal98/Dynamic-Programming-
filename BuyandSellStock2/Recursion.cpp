class Solution {
public:
    
    int solve(int idx,int buyflag,vector<int>& prices)
    {

       if(idx==prices.size()) return 0;

       int profit=0;


       // case 1 : You can buy if buyflag is set to 1

       if(buyflag==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             profit=max(-prices[idx]+solve(idx+1,0,prices) , 0+solve(idx+1,1,prices));

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both
        profit=max(+prices[idx]+solve(idx+1,1,prices),0+solve(idx+1,0,prices));
       }

       return profit;


    }

  
    int maxProfit(vector<int>& prices) {
       
       
       return solve(0,1,prices);

       

    }
};