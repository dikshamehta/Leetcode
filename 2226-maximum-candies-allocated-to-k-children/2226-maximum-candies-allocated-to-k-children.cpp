class Solution {
private:
    bool distributionPossible(vector<int>& candies, long long k, int numCandies){
        long long maxChildren = 0;
        for(int i=0; i<candies.size(); i++){
            maxChildren += candies[i]/numCandies;
        }

        return maxChildren>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandiesInPile = *max_element(candies.begin(), candies.end());

        int l = 0;
        int r = maxCandiesInPile;

        while(l<r){
            int m = (r+l+1)/2;

            if(distributionPossible(candies, k, m)){
                //means m number of candies can be distributed, therefore lets check for higher number
                l = m;
            }
            else{
                //means m number of candies can not be distributed, therefore lets check for smaller number
                r = m-1;
            }
        }

        return l;
    }
};