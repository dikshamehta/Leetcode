class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;

        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            temp += s[i];
            if (temp.size() == k) {
                res.push_back(temp);
                temp = "";
            }
        }

        if (!temp.empty()) {
            while (temp.size() < k) {
                temp += fill;
            }
            res.push_back(temp);
        }


        return res;
        
    }
};