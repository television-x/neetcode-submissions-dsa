class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int val1, val2;
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        vector<int> result;

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums1[left] + nums1[right] == target) {
                val1 = nums1[left];
                val2 = nums1[right];
                break;
            } else if (nums1[left] + nums1[right] < target) {
                left++;
            } else {
                right--;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val1 || nums[i] == val2) {
                result.push_back(i);
            }
            if (val1 == val2 && result.size() == 2) break;
            if (val1 != val2 && result.size() == 2) break;
        }
        
        return result;
    }
};
