class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mapend;

        for (int i = 0; i < s.size(); i++) {
            mapend[s[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            int next = mapend[s[i]];

            int k = i + 1;
            while (k < next) {
                next = max(next, mapend[s[k++]]);
            }

            ans.push_back(next - i + 1);
            i = next;
        }

        return ans;
    }
};
