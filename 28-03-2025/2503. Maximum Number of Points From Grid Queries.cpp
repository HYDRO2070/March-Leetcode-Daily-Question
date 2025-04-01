class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> arr;

        auto findBest = [&](int x) {
            return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        };

        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            heap;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        heap.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;

        while (!heap.empty()) {
            auto [cellVal, pos] = heap.top();
            heap.pop();
            arr.push_back(cellVal);

            for (auto& dir : directions) {
                int r = pos.first + dir.first, c = pos.second + dir.second;

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != -1) {
                    heap.push({grid[r][c], {r, c}});
                    grid[r][c] = -1;
                }
            }
        }

        int prev = 0;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = max(arr[i], prev);
            prev = arr[i];
        }

        vector<int> result;
        for (int q : queries) {
            result.push_back(findBest(q));
        }

        return result;
    }
};
