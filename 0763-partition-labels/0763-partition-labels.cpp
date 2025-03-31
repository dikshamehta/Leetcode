class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        vector<int> res;
        
        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }
        
        int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i]]);
            
            if (i == end) {  // When we reach the end of a partition
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};
