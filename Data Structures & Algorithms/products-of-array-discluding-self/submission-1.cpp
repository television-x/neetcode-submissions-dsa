class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        vector<int> result;
        int zeroCount = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0) zeroCount++;
        }

        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0) continue;
            else    product*=nums[i];
        }

        if(zeroCount == 0){
            for(int i=0; i<nums.size(); i++){
                result.push_back(product/nums[i]);
            }
        }else{
            for(int i=0; i<nums.size(); i++){
                if (nums[i]!=0 || zeroCount > 1) result.push_back(0);
                else{
                    result.push_back(product);
                }
            }
        }
        return result;
    }
};
