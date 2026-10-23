class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int freq = 1;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == nums[i + 1]) {
                freq++;
            } else {
                freq = 1;
            }

            if (freq > n / 2)
                return nums[i];
        }

        return nums[n - 1];
    }
};