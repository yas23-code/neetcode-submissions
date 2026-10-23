class Solution {
public:

    long long func(vector<int>& arr, int hourly) {
        long long totalhrs = 0;

        for (int i = 0; i < arr.size(); i++) {
            totalhrs += (arr[i] + hourly - 1) / hourly;
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalhrs = func(arr, mid);

            if (totalhrs <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};