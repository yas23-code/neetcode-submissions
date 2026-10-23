#include<cstring>;
class Solution {
public:
int t[301][301];
int solve(int i,int j,vector<int>& nums){
    if(i>j){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int maxi=INT_MIN;
    for(int idx=i;idx<=j;idx++){
        int cost=nums[i-1]*nums[idx]*nums[j+1]+solve(i,idx-1,nums)+solve(idx+1,j,nums);

        maxi=max(maxi,cost);
    }
    return t[i][j]= maxi;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return  solve(1,n,nums);
        
    }
};
