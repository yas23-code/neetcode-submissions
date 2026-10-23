class Solution {
public:

    int maxSum(vector<int>& nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int minSum(vector<int>& nums, int n) {
        int sum = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < n; i++) {
            sum = min(nums[i], sum + nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        int maximum = maxSum(nums, n);
        int minimum = minSum(nums, n);

        // If all numbers are negative
        if(maximum < 0) {
            return maximum;
        }

        int circularSum = total - minimum;

        return max(maximum, circularSum);
    }
};