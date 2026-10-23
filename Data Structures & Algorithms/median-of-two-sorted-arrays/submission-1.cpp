class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int size = n + m;

        int idx1 = (size / 2) - 1;
        int idx2 = size / 2;

        int elem1 = -1;
        int elem2 = -1;

        int i = 0, j = 0, k = 0;

        while(i < n && j < m) {
            int val;

            if(nums1[i] < nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if(k == idx1) elem1 = val;
            if(k == idx2) elem2 = val;

            k++;
        }

        while(i < n) {
            int val = nums1[i++];

            if(k == idx1) elem1 = val;
            if(k == idx2) elem2 = val;

            k++;
        }

        while(j < m) {
            int val = nums2[j++];

            if(k == idx1) elem1 = val;
            if(k == idx2) elem2 = val;

            k++;
        }

        if(size % 2 == 1) {
            return elem2;
        }

        return ((double)elem1 + elem2) / 2.0;
    }
};