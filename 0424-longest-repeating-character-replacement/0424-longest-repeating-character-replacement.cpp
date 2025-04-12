class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        int n = s.size();

        for(int c='A'; c<='Z'; c++){
            int i=0; 
            int j=0;
            int remaining_k = k;

            while(j<n){
                if(s[j] == c){
                    j++;
                }
                else if(remaining_k>0){
                    j++; remaining_k--;
                }
                // Now in our above condition we know k is finished, we can not move further
                // replacing elements because, k<0 and s[j]!=c
                // So, now we have to move to left side of window and shrink it
                // so now checking if, we did use a k for ith position
                else if(s[i] == c){
                    // if ith element is already c then we did not use k
                    // then just move forward
                    i++;
                }
                else{
                    //but if it was not c then we used k for it
                    //now we are leaving that position so restore k
                    i++; remaining_k++;
                }

                max_len = max(max_len, j-i);
            }
        }
        return max_len;  
    }
};