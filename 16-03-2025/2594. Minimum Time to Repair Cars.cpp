class Solution {
    private:
    bool check(vector<int> &arr,long long mid,int cars){
        long long cnt = 0;
        for(auto& r : arr){
            cnt += sqrt(mid/r);
            if(cnt >= cars) return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1ll * (*max_element(ranks.begin(),ranks.end())) * cars * cars;
        long long ans = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(check(ranks,mid,cars)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
