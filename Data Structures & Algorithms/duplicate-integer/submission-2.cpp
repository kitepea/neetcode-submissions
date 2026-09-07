class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> temp;

        for (int i : nums) {
            if (temp.find(i) != temp.end()) {
                return true;
            }
            temp.insert(i);
        }

        return false;
    }
};