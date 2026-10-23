#include<cstring>
class Solution {
public:
int t[201][1001];
int solve(vector<int>& nums,int target,int i){
    if(target==0){
        return 1;
    }
    if(i>=nums.size() || target<0){
        return 0;
    }
     if(t[i][target]!=-1){
        return t[i][target];
    }
    int take=solve(nums,target-nums[i],0);
    int leave=solve(nums,target,i+1);

    return t[i][target]= take+leave;
}
   

    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,target,0);
    }
};