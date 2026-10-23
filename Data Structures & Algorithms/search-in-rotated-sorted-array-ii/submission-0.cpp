class Solution {
public:
    bool search(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == tar)
                return true;

            if (A[st] == A[mid] && A[mid] == A[end]) {
                st++;
                end--;
                continue;
            }

            if (A[st] <= A[mid]) {   // left sorted
                if (A[st] <= tar && tar < A[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else {   // right sorted
                if (A[mid] < tar && tar <= A[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};