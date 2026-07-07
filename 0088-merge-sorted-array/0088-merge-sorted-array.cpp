class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int>temp;

        for(int i=0;i<m;i++){
            if(nums1[i]!=0||nums1.size()!=0){
                temp.push_back(nums1[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(nums2[i]!=0||nums2.size()!=0){
                temp.push_back(nums2[i]);
            }
        }

        sort(temp.begin(),temp.end());

        for(int i=0;i<m+n;i++){
            nums1[i]=temp[i];
        }

        

    }
};