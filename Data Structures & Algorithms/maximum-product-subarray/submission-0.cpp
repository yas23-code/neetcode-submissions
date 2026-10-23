class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxPro = nums[0];
        int prefix = 1;
        int suffix = 1;

        for(int i = 0; i < n; i++) {

            if(prefix == 0)
                prefix = 1;

            if(suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - 1 - i];

            maxPro = max(maxPro, max(prefix, suffix));
        }

        return maxPro;
    }
};