class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for (auto it : grid) {
            for (auto ir : it) {
                arr.push_back(ir);
            }
        }

        sort(arr.begin(), arr.end());
        int midIdx = arr.size() / 2;
        int midNum = arr[midIdx];
        int minStep = 0;
        for (auto& it : arr) {
            int diff = abs(it - midNum);
            if (diff % x != 0) {
                return -1;
            }
            minStep += diff / x;
        }

        return minStep;
    }
};
