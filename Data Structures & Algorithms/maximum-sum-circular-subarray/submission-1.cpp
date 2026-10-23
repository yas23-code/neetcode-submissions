class Solution {
public:

    int maxSum(vector<int>& nums) {

        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            sum = max(nums[i], sum + nums[i]);

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int minSum(vector<int>& nums) {

        int sum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            sum = min(nums[i], sum + nums[i]);

            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int maxSub = maxSum(nums);
        int minSub = minSum(nums);

        // Circular maximum
        int circularMax = totalSum - minSub;

        // All numbers are negative
        if (maxSub < 0) {
            return maxSub;
        }

        return max(maxSub, circularMax);
    }
};