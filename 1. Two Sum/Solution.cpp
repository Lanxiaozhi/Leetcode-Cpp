//
// Created by 懒小植 on 2018/10/2.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int len = nums.size();
        for (int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
    }
};