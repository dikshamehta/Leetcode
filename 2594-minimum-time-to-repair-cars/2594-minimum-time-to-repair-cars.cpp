class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long h = 1LL * ranks[0] * cars * cars;

        while(l<h){
            long long mid = (l+h)/2;
            long long possible_cars = 0;
            for(int i=0; i<ranks.size(); i++){
                possible_cars += sqrt(mid/ranks[i]);
            }

            if(possible_cars>=cars){
                h = mid;
            }
            else{
                l = mid+1;
            }
        }

        return l;
    }
};