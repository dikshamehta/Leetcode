class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        int i = 0;
        int j = filtered.size() - 1;

        while(j>i){
            if(filtered[i] == filtered[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};