// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    // Approach 1: Traverse entire array and get a count of each number. Put in pq and then pop first k     
    struct Compare {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second <= rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (auto num : nums) {
            ++counts[num];
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto& kvp : counts) {
            pq.push(kvp);
        }
        
        vector<int> topElements;
        for (size_t i = 0; i < k; ++i) {
            auto top = pq.top();
            topElements.push_back(top.first);
            pq.pop();
        }
        
        return topElements;
    }
};
