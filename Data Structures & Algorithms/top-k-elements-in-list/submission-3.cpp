
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(n + 1);

        // Index = frequency, Value = elements
        for (auto &it : mp) {
            int elem = it.first;
            int freq = it.second;

            bucket[freq].push_back(elem);
        }

        vector<int> result;

        for (int i = n; i >= 0; i--) {
            if (bucket[i].empty()) {
                continue;
            }

            while (!bucket[i].empty() && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }

            if (k == 0) {
                break;
            }
        }

        return result;
    }
};
