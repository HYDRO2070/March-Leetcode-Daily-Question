class Solution {
public:
    int numberOfSubstrings(string& s) {
        int ans = 0;
        int n = s.size();

        // Brute Force
        // for(int i = 0;i <= n-2;i++){
        //     bool a = false,b = false,c = false;
        //     for(int j = i;j < n;j++){
        //         if(!a && s[j] == 'a') a = true;
        //         else if(!b && s[j] == 'b') b = true;
        //         else if(!c && s[j] == 'c') c = true;
        //         if(a && b && c) ans++;
        //     }
        // }
        // return ans;
        vector<int> cnt(3, 0);
        int left = 0, right = 0;
        while (right < n) {
            cnt[s[right] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2]) {
                ans += (n - right);
                cnt[s[left] - 'a']--;
                left++;
            }
            // cout<<ans<<endl;
            right++;
        }
        return ans;
    }
};
