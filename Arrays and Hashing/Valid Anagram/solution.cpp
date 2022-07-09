// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    
    using CharacterCounts = std::array<size_t, 26>;
    
    // Approach 1: Character counts of s & t and then walk each.
    //  - Space cost: 26 * 2 
    //  - Time: m + n + 26 
    bool isAnagram(string s, string t) {
        CharacterCounts sCounts, tCounts;
        sCounts.fill(0), tCounts.fill(0);
        getCounts(s, sCounts), getCounts(t, tCounts);
        
        for (size_t i = 0; i < sCounts.size(); ++i) {
            if (sCounts[i] != tCounts[i]) {
                return false;
            }
        }
        return true;
    }
    
    void getCounts(const string& s, CharacterCounts& counts) {
        for (auto c : s) {
            ++counts[c - 'a'];
        }   
    }
};
