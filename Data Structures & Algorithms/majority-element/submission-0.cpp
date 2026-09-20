class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0; i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(nums[j]>nums[i]) {
                    count++;
                }
            }
        }
        return count;
    }
};