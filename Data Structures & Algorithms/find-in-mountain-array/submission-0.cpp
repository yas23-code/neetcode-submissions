/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    // Ascending half: normal binary search
    int binarySearch(MountainArray &mountainArr, int st, int end, int target) {
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }

    // Descending half: comparisons flipped
    int reverseBinarySearch(MountainArray &mountainArr, int st, int end, int target) {
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    // Find peak index by comparing arr[mid] with arr[mid+1]
    int findPeakIdx(MountainArray &mountainArr) {
        int st = 0, end = mountainArr.length() - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                st = mid + 1;   // still climbing, peak is to the right
            } else {
                end = mid;      // peak is here or to the left
            }
        }
        return st;  // st == end == peak index
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = findPeakIdx(mountainArr);

        int resultIdx = binarySearch(mountainArr, 0, idx, target);
        if (resultIdx != -1) {
            return resultIdx;
        }

        resultIdx = reverseBinarySearch(mountainArr, idx + 1, n - 1, target);
        return resultIdx;
    }
};