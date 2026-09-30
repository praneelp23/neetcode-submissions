class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ei = nums.size() - 1;
        int si = 0;
        while(si<=ei) {
        int mid = si + (ei - si) / 2;
        if(nums[mid]==target) {
            return true;
        }

        // Duplicate values  very very important test case - ignoring the first and last element
            if (nums[si] == nums[mid] && nums[mid] == nums[ei]) {
                si++;
                ei--;
            }

        else if( nums[si] <= nums[mid]) { //line 1 case
            if(nums[si] <= target && target <= nums[mid]) {
                ei = mid - 1;
            }
            else {
                si = mid + 1;
            }
        }
        else {
            if(nums[mid] <= target && target <= nums[ei]) {
                si = mid +1;
            }
            else {
                ei = mid - 1;
            }
        }
       
     } 
 
        return false;
    }
};