class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<k){
                v.push_back(nums[i]);
                mp[nums[i]]++;
            }
        }
        return v;
    }
};