class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);

        if (n == 0)
            return result;

        result[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                // Odd number
                result[i] = result[i / 2] + 1;
            } else {
                // Even number
                result[i] = result[i / 2];
            }
        }

        return result;
    }
};