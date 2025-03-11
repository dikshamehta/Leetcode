class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int count = 0;

        vector<int> freq(3,0);

        while(right<n){
            freq[s[right]-'a'] += 1;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                count += n - right;
                freq[s[left]-'a'] -= 1;
                left++;
            }
            right++;
        }
        return count;
    }
};