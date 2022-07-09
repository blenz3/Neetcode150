// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    

    uint64_t calculateHash(const std::array<size_t, 26>& values) {
         std::hash<size_t> hasher;
        uint64_t result = 0;
        for (uint64_t i = 0; i < values.size(); ++i) {
            result = result * 31 + hasher(values[i]);
        }
        return result;
    }
    
    template<class T, size_t N>
    void countCharacters(const std::string& s, std::array<T, N>& counts) {
        counts.fill(0);
        for (auto c : s) {
            ++counts[c - 'a'];
        }
    }
    
    // Approach 2: Fancy hash the counts of each character to avoid having to copy and sort all the time
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint64_t, vector<string>> groups;
        array<size_t, 26> counts;
        for (size_t i = 0; i < strs.size(); ++i) {
            auto& str = strs[i];
            countCharacters(str, counts);
            groups[calculateHash(counts)].emplace_back(std::move(str));
        }
        
        vector<vector<string>> out;
        for (auto& kvp : groups) {
            out.push_back(kvp.second);
        }
        
        return out;
    }
#if 0
    // Approach 1: Sort each string and use that as indirection into a collection of unsorted strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (auto& str : strs) {
            auto copy(str);
            std::sort(copy.begin(), copy.end());
            groups[copy].push_back(str);
        }
        
        vector<vector<string>> out;
        for (auto& kvp : groups) {
            out.push_back(kvp.second);
        }
        
        return out;
    }
#endif 
};
