class Solution {
public:
// O( n * 2^n) - TIME COMPLEXITY
void getAllSubsets(vector<int>&nums, vector<int>&ans, int i, vector<vector<int>> &    allsubsets) {
    if(i==nums.size()) {
        allsubsets.push_back(ans);
        return;
    }
    //yes choice
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allsubsets);

    ans.pop_back();

    //no choice
    getAllSubsets(nums, ans, i+1, allsubsets);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> allsubsets;
        getAllSubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};