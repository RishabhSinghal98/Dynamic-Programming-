class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       
       int aheadbuy=0 ,aheadnotbuy=0 , currbuy ,currnotbuy;
       
       
       

       

       for(int i=n-1;i>=0;i--)
       {
        

       
          
             currbuy=max(-prices[i]+aheadnotbuy , aheadbuy);

             currnotbuy=max(prices[i]+aheadbuy,aheadnotbuy);


             aheadbuy=currbuy;
             aheadnotbuy=currnotbuy;
       



      
       }
       
      return aheadbuy;
    }
};