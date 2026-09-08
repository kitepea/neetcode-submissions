class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        for (int i = 0; i < nums.size(); i++) {
            int match = target - nums[i];
            if(temp.contains(match)) {
                return {temp[match], i};
            }

            temp[nums[i]] = i;
        }
        return {0, 0};
    }
};
