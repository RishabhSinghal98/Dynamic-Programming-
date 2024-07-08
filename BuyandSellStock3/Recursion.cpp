class Solution {
public:
    
    int solve(int idx,int buyflag,vector<int>& prices,int limit)
    {

       if(limit==0) return 0; // we have done two times buying and selling 
       if(idx==prices.size()) return 0;

       int profit=0;


       // case 1 : You can buy if buyflag is set to 1

       if(buyflag==1)
       {
          // two cases either you will buy or not therfore we will take maximum of both
             profit=max(-prices[idx]+solve(idx+1,0,prices,limit) , 0+solve(idx+1,1,prices,limit));

       }

       // case 2 : If buy flag is 0 i.e we cannot buy the stock but we can sell as flag is 0 that means we have previously bought the share.

       else{
          // two cases either you will sell or not therfore we will take maximum of both , if we sell then we decrease the limit by -1
        profit=max(+prices[idx]+solve(idx+1,1,prices,limit-1),0+solve(idx+1,0,prices,limit));
       }

       return profit;


    }

  
    int maxProfit(vector<int>& prices) {
       
       
       return solve(0,1,prices,2);

       

    }
};