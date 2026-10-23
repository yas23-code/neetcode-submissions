#include<cstring>
class Solution {
public:
int t[5001][2];

int solve(vector<int>& prices,int day,int n,bool buy){
    if(day>=n){
    return 0;
}
if(t[day][buy]!=-1){
    return t[day][buy];
}
int profit=0;
if(buy){
    int take=solve(prices, day+1,n,false)-prices[day];

    int not_take=solve(prices,day+1,n,true);

    profit=max({profit,take,not_take});
}else{
    int sell=prices[day]+solve(prices,day+2,n,true);

    int not_sell=0+solve(prices,day+1,n,false);

    profit=max({profit,sell,not_sell});
}
return t[day][buy]=profit;

}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        bool buy=true;
        memset(t,-1,sizeof(t));

        return solve(prices,0,n,buy);
        
    }
};
