class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;

        int min_change = INT_MAX; 
        int change = 0;

        //sliding window i to j of size k
        //move j till window size is k while counting 'W' i.e. changes to be done
        for(int j=0; j<blocks.size(); j++){
            if(blocks[j]=='W'){
                change++;
            }
            //if window size is achieved then move left of window
            //if the left was at 'W' then decrease change by 1
            if(j-i+1 == k){
                min_change = min(min_change, change);
                if(blocks[i]=='W'){
                    change--;
                }
                i++;
            }
        }
        return min_change;
    }
};