class Solution {
public:

    bool isPalindrom(int x, int y, string s){
        while(y>x){
            if(s[x]!=s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void generate(int ind, string s, vector<vector<string>>& ans, vector<string>& sub){
        if(ind == s.size()){
            ans.push_back(sub);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalindrom(ind, i, s)){ // check orange string is valid
                sub.push_back(s.substr(ind, i-ind+1)); 
                generate(i+1, s, ans, sub); // calculate for blue string
                sub.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;

        generate(0, s, ans, sub);

        return ans;
    }
};