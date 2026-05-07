class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j = 1, k = 2;
        vector<vector<int>> result;

        while (i + 2 < nums.size()) {

            if (nums[i] + nums[j] + nums[k] == 0) {

                vector<int> v1 = {nums[i], nums[j], nums[k]};
                sort(v1.begin(), v1.end());

                if (find(result.begin(), result.end(), v1) == result.end()) {
                    result.push_back(v1);
                }

                // move safely
                if (k + 1 < nums.size()) {
                    k++;
                }
                else if (j + 2 < nums.size()) {
                    j++;
                    k = j + 1;
                }
                else {
                    i++;
                    j = i + 1;
                    k = j + 1;
                }
            }

            else if (k + 1 < nums.size()) {
                k++;
            }

            else if (j + 2 < nums.size()) {
                j++;
                k = j + 1;
            }

            else {
                i++;
                j = i + 1;
                k = j + 1;
            }
        }

        return result;
    }
};