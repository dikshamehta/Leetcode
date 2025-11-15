class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        if(slen!=tlen){
            return false;
        }
        
        map<char, int> anagram;
        for(int i=0; i<slen; i++){
            anagram[s[i]]++;
            anagram[t[i]]--;
        }

        for(auto p : anagram){
            //count is pair iterating over anagram, pair is (first,second) where first represent each key and second  represent each value 
            // basically here auto means pair<char, int>
            if(p.second){
                return false;
            }
        }
        return true;

    }
};