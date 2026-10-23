class Solution {
public:
    int findMid(vector<int>& nums, int n) {
        int l = 0, r = n - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;  // index of smallest element
    }

    int searchIdx(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findMid(nums, n);

        int idx = searchIdx(nums, target, 0, pivot - 1);

        if(idx != -1) {
            return idx;
        }

        return searchIdx(nums, target, pivot, n - 1);
    }
};