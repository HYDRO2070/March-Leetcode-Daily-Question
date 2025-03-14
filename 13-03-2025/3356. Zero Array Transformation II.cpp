class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        int prefSum = 0;
        for (int i = 0; i < n; i++) {
            prefSum += diff[i];
            if (prefSum < nums[i])
                return 0;
        }
        return 1;
    }
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = queries.size();

    int low = 0, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(nums, queries, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low == n + 1 ? -1 : low;
}
}
;
