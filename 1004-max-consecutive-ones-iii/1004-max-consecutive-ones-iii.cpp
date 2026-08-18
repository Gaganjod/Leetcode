class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zero=0;
        int ans=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                    left++;
                
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};