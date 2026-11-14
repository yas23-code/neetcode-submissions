class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {     // ✅ correct bounds check
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {                     // ✅ else handles both < and == cases
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {                // ✅ correct bounds check
            nums1[k] = nums2[j];
            j--;
            k--;                          // ✅ now decrements k
        }

        // No leftover loop needed for `i` — see explanation below
        // (function is void, no return needed)
    }
};