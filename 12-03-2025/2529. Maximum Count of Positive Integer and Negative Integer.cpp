class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(),nums.end(),0) - nums.begin()-1;
        int pos = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        if(neg < 0) neg = 0;
        else neg++;
        pos = nums.size() - pos;
        return max(neg,pos);
        
    }
};
