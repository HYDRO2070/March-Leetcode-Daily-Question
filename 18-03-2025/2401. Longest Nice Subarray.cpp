class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0,right = 0;
        int n = nums.size();
        int bitmask = 0;
        int ans = 1;
        while(right < n){
            while((bitmask & nums[right]) != 0){
                bitmask ^= nums[left];
                left++;
            }
            
            bitmask |= nums[right];
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
