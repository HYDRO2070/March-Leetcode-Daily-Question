class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom_num = -1;
        int n = nums.size();
        unordered_map<int, int> freq;
        int dom_cnt = 0;
        for (int i : nums) {
            freq[i] += 1;
        }
        // now travere the map find ele of freq >n/2
        for (auto& i : freq) {
            if (i.second > n / 2) {
                dom_num = i.first;
                dom_cnt = i.second;
            }
        }

        // now we have maj ele no check it its avlaid split
        int cur_cnt = 0; // maj ele freq before i inclusive
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dom_num) {
                cur_cnt += 1;
                if ((cur_cnt > (i + 1) / 2) &&
                    ((dom_cnt - cur_cnt) > (n - i - 1) / 2)) {
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};
