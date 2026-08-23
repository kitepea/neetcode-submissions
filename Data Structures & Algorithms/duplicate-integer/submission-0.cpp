class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i : nums) {
            if (seen.count(i) > 0)
                return true;
            else seen.insert(i);
        }
        return false;
    }
};