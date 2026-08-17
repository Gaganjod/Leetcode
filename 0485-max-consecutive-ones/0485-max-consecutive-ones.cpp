class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(nums[right] == 1) {
                count++;
            }
            else {
                count = 0;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};