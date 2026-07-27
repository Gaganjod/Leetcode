class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = (nums[i] - 1) * (nums[j] - 1);
                max1 = max(max1, val);
            }
        }
        return max1;
    }
};