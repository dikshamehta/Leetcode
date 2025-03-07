class Solution {
public:
    vector<int> sieve(int limit){
        vector<int> sieve(limit+1, 1);
        sieve[0] = 0;
        sieve[1] = 0;

        // i: 2->sqrt(limit)
        for(int i=2; i*i<=limit; i++){
            if(sieve[i] == 1){
                for(int j=i*i; j<=limit; j+=i){
                    sieve[j] = 0;
                }
            }
        }
        return sieve;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primeArray = sieve(right);

        vector<int> primeinRange;

        for(int i=left; i<=right; i++){
            if(primeArray[i]==1){
                primeinRange.push_back(i);
            }
        }

        if(primeinRange.size()<2){
            return {-1, -1};
        }

        int minDiff = INT_MAX;
        vector<int> closestPair(2, -1);

        for(int i=1; i<primeinRange.size(); i++){
            int diff = primeinRange[i] - primeinRange[i-1];
            if(diff<minDiff){
                minDiff = diff;
                closestPair[0] = primeinRange[i-1];
                closestPair[1] = primeinRange[i];
            }
        }
        return closestPair;
    }
};

// Sieve of Eratosthenes
// class Solution {
// public:
//     vector<int> sieve(int limit){
//         vector<int> sieve(limit+1, 1);
//         sieve[0] = 0;
//         sieve[1] = 0;

//         // i: 2->sqrt(limit)
//         for(int i=2; i*i<=limit; i++){
//             if(sieve[i] == 1){
//                 for(int j=i*i; j<=limit; j+=i){
//                     sieve[j] = 0;
//                 }
//             }
//         }
//         return sieve;
//     }
//     vector<int> closestPrimes(int left, int right) {
//         vector<int> primeArray = sieve(right);

//         vector<int> primeinRange;

//         for(int i=left; i<=right; i++){
//             if(primeArray[i]==1){
//                 primeinRange.push_back(i);
//             }
//         }

//         if(primeinRange.size()<2){
//             return {-1, -1};
//         }

//         int minDiff = INT_MAX;
//         vector<int> closestPair(2, -1);

//         for(int i=1; i<primeinRange.size(); i++){
//             int diff = primeinRange[i] - primeinRange[i-1];
//             if(diff<minDiff){
//                 minDiff = diff;
//                 closestPair[0] = primeinRange[i-1];
//                 closestPair[1] = primeinRange[i];
//             }
//         }
//         return closestPair;
//     }
// };