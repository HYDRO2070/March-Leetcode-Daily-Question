class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& temp, int& k) {

        for (int i = 0; i < k - 1; i++)
            temp.push_back(temp[i]);
        int n = temp.size();
        int ans = 0;
        int i = 0;
        bool pass = false;
        while (i < n) {
            if (pass) {
                if (temp[i] == temp[i - 1]) {
                    pass = false;
                } else {
                    ans++;
                    i++;
                }
            } else {
                if (i > n - k)
                    break;
                int j = i;
                int last = -1;
                while (j < i + k && temp[j] != last) {
                    last = temp[j];
                    j++;
                }
                if (j == i + k) {
                    ans++;
                    pass = true;
                }
                i = j;
            }
        }
        return ans;
    }
};
