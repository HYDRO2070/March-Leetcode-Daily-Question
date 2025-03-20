class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> flip(nums.size(), 0);
        int result = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if ((nums[i] ^ flip[i]) == 1)
                continue; 

            flip[i + 1] ^= 1;
            flip[i + 2] ^= 1;
            result++;
        }

        if ((nums[nums.size() - 1] ^ flip[nums.size() - 1]) != 1 ||
            (nums[nums.size() - 2] ^ flip[nums.size() - 2]) != 1) {
            return -1;
        }

        return result;
    }
};
