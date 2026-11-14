
class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {

            if (nums[i] + nums[j] < target) {
                i++;
            }
            else if (nums[i] + nums[j] > target) {
                j--;
            }
            else {
                result.push_back({-target, nums[i], nums[j]});

                i++;
                j--;

                // Skip duplicate elements
                while (i < j && nums[i] == nums[i - 1]) {
                    i++;
                }

                while (i < j && nums[j] == nums[j + 1]) {
                    j--;
                }
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];

            twoSum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};
