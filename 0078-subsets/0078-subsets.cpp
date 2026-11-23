
class Solution {
public:
    void printSubsets(vector<int>& arr, vector<int>& ans,
                      vector<vector<int>>& result, int i) {

        if (i == arr.size()) {
            result.push_back(ans);
            return;
        }

        // Include
        ans.push_back(arr[i]);
        printSubsets(arr, ans, result, i + 1);

        // Backtrack
        ans.pop_back();

        // Exclude
        printSubsets(arr, ans, result, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;

        printSubsets(nums, ans, result, 0);

        return result;
    }
};
