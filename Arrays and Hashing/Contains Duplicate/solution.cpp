// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    
#if 0    
    // Approach 3: Le classique brute force
    bool containsDuplicate(vector<int>& nums) {
        for (size_t i = 0 ; i < nums.size(); ++i) {
            for (size_t j = 0; j < nums.size(); ++j) {
                if (i != j && nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
    

    // Approach 2: Sort
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
 #endif   

    // Approach 1: Hashset 
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for (auto num : nums) {
            if (numbers.count(num) == 0) {
                numbers.insert(num);
            } else {
                return true;
            }
        }
        
        return false;
    }

};
