class Solution {
public:

    void generate(int openN, int closeN, int n, string& paran, vector<string>& sol){
        // Base case
        if(openN == n && closeN == openN){
            sol.push_back(paran);
            return;
        }

        if(openN<n){
            paran.push_back('(');
            generate(openN+1, closeN, n, paran, sol);
            paran.pop_back();
        }

        if(closeN<openN){
            paran.push_back(')');
            generate(openN, closeN+1, n, paran, sol);
            paran.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string paran = "";

        generate(0, 0, n, paran, sol);

        return sol;  
    }
};