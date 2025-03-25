class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> v;
        for (int i = 0; i < meetings.size(); i++) {
            pair<int, int> p = {meetings[i][0], meetings[i][1]};
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        int ans = v[0].first - 1, secondValue = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first <= secondValue) {
                if (v[i].second < secondValue) {
                    continue;
                }
                secondValue = v[i].second;
                continue;
            }
            ans += v[i].first - secondValue - 1;
            secondValue = v[i].second;
        }
        ans += days - secondValue;
        return ans;
    }
};
