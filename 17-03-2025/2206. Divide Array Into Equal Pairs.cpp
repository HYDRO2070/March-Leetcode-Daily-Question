class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto& n : nums) m[n]++;
        int ans = 0;
        int n = nums.size() / 2;

        for(auto& temp : m){
            if(temp.second % 2 != 0) return false;
            else ans += temp.second /2;
            
        }
        return ans == n;
    }
};
