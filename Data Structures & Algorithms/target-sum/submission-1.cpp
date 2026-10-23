#include <cstring>
#include <unordered_map>
#include <string>

class Solution {
public:
    int solve(int i, int currSum, int target,
              vector<int>& nums,
              unordered_map<string, int>& mp) {

        if(i == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            return 0;
        }

        // State = index + current sum
        string key = to_string(i) + "_" + to_string(currSum);

        if(mp.count(key)) {
            return mp[key];
        }

        int sum = solve(i + 1, currSum + nums[i], target, nums, mp);

        int minus = solve(i + 1, currSum - nums[i], target, nums, mp);

        return mp[key] = sum + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;

        return solve(0, 0, target, nums, mp);
    }
};