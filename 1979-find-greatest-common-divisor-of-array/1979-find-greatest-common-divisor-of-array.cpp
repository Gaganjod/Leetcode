class Solution {
public:
    int findGCD(vector<int>& nums) {
        int large=0;
        int small=INT_MAX;

        for(int i=0;i<nums.size();i++){
            large=max(large,nums[i]);
            small=min(small,nums[i]);
        }
        return __gcd(large,small);
    }
};