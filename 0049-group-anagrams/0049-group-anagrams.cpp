class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string, vector<string>> anagram;

        for(int i=0; i<strs.size(); i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            anagram[sorted].push_back(strs[i]); 
        }

        for(pair<string, vector<string>> p : anagram){
            v.push_back(p.second);
        }

        return v;
    
    }
        
};