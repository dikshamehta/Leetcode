class Solution {
public:
    void solve(string sol, int i, string& digits, map<char, string>& mapping, vector<string>& res){
        if(sol.size()==digits.size()){
            res.push_back(sol);
            return;
        }

        for(char c : mapping[digits[i]]){
            sol.push_back(c);
            solve(sol, i+1, digits, mapping, res);
            sol.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res;

        if(!digits.empty()){
            solve("", 0, digits, mapping, res);
        }
        
        return res;
    }
};