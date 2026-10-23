class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high) {
            int mid = low + (high - low) / 2;

            int d = 1;
            int currentWeight = 0;

            for(int w : weights) {
                if(currentWeight + w > mid) {
                    d++;
                    currentWeight = 0;
                }

                currentWeight += w;
            }

            if(d > days) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};