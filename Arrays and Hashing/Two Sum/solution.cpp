// https://leetcode.com/problems/two-sum

class Solution {
public:
    // Approach 1: Use a hashtable and search for complements
    //  - Space linear with respect to nums
    //  - Time n * 1 = n
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> numberIndices;
        for (int i = 0; i < nums.size(); ++i) {
            auto num = nums[i];
            numberIndices[num].push_back(i);
            
            auto complement = target - num;
            auto complementIndicesIt = numberIndices.find(complement);
            if (complementIndicesIt == numberIndices.end()) 
                continue;
            
            if (complement != num) {
                return vector<int>{ i, complementIndicesIt->second.front() };
            } else if (complement == num && complementIndicesIt->second.size() == 2) {
                return complementIndicesIt->second;
            }
        }
        
        return {-1, -1};
    }
};
