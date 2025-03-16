class Solution {
public:
    bool newFun(vector<int>& nums, int cap, int k) {
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= cap) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1, mini = 1e9;
        for (auto x : nums) {
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        int l = mini, r = maxi, result = maxi;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (newFun(nums, mid, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
