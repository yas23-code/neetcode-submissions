class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxSum=INT_MIN;
        for(int no:nums){
            currSum=max(no,currSum+no);
            maxSum=max(maxSum,currSum);
        }
        return maxSum;

    }
};
