class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merged;

        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        int n = merged.size();

        if(n % 2 == 0) {
            int mid = n / 2;
            return (merged[mid] + merged[mid - 1]) / 2.0;
        }
        else {
            return merged[n / 2];
        }
    }
};
