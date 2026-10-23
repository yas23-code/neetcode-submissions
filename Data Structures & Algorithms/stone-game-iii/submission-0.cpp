class Solution {
public:
    vector<int> t;

    int solve(vector<int>& stoneValue, int idx) {
        int n = stoneValue.size();

        if(idx >= n) {
            return 0;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        // Take 1 stone
        int result = stoneValue[idx] 
                   - solve(stoneValue, idx + 1);

        // Take 2 stones
        if(idx + 1 < n) {
            result = max(result,
                stoneValue[idx] + stoneValue[idx + 1]
                - solve(stoneValue, idx + 2));
        }

        // Take 3 stones
        if(idx + 2 < n) {
            result = max(result,
                stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2]
                - solve(stoneValue, idx + 3));
        }

        return t[idx] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        t.resize(n, -1);

        int result = solve(stoneValue, 0);

        if(result > 0) {
            return "Alice";
        }
        else if(result < 0) {
            return "Bob";
        }

        return "Tie";
    }
};