class Solution {
public:
    vector<int> prime;
    Solution() { seive(); }
    void seive() {
        int N = 1e6 + 2;
        prime.resize(N, 1);
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i < N; i++) {
            if (prime[i]) {
                for (int j = i * i; j < N; j += i) {
                    prime[j] = 0;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int prev = -1, diff = 1e9;
        vector<int> ans = {-1, -1};

        for (int i = left; i <= right; i++) {
            if (prime[i] == 1) {
                if (prev != -1) {
                    if (i - prev < diff) {
                        ans = {prev, i};
                        diff = i - prev;
                    }
                }

                prev = i;
            }
        }
        return ans;
    }
};
