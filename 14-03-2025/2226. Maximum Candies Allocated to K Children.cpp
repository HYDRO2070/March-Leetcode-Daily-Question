class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        const int n = c.size();
        int left = 1,right = *max_element(c.begin(),c.end());
        int mid = -1;
        int ans = 0;
        long long temp = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            bool flag = false;
            temp = 0;
            for(int i = 0 ;i < n;i++){
                temp += c[i] / mid;
                if(temp >= k){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans = mid;
                left = mid + 1;

            }
            else right = mid -1;
        }
        return ans;
    }
};
