class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixSum(n + 1);
        vector<int> suffixSum(n + 1);
        vector<int> result(n);

        prefixSum[0] = 1;

        for(int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i-1] * nums[i-1];
        }

        suffixSum[n] = 1;

        for(int i = n-1; i >= 0; i--){
            suffixSum[i] = suffixSum[i+1] * nums[i];
        }

        for(int i = 0; i < n; i++){
            result[i] = prefixSum[i] * suffixSum[i+1];
        }

        return result;
    }
};