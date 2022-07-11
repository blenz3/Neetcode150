class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1; 
        while (start < end) {
            auto sum = numbers[start] + numbers[end];
            if (sum == target) {
                return vector<int>{ start + 1, end + 1 };
            }
            
            
            if (sum < target) {
                ++start;
            } else if (sum > target) {
                --end;
            }
        }
        
        return vector<int>{-1, -1};
    }
};
