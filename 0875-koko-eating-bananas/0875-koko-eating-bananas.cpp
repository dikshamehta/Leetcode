class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int res = r; 

        while(l<=r){
            int m = (l+r)/2;

            long totaltime = 0;

            for(int p : piles){
                
                //totaltime += ceil(p/(double) m); //converting one of them to double to have floating division

                // (pile + mid - 1) / mid is a clever way to round up the division to the nearest integer.
                totaltime += (p + m - 1) / m; // Equivalent to Math.ceil((double)pile / mid). Calculates how many hours it takes for one pile.

            }

            if(totaltime <= h){
                res = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return res;
    }
};