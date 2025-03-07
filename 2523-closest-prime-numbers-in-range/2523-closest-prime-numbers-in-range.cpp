class Solution {
public:
    bool isPrime(int number) {
        if (number <= 1) {
            return false; // Numbers less than or equal to 1 are not prime
        } else if (number < 4) {
            return true; // 2 and 3 are prime
        } else if (number % 2 == 0) {
            return false; // Only even prime number is 2
        } else if (number < 9) {
            return true; // As we excluded 4, 6, and 8, only 5 and 7 remain.
        } else if (number % 3 == 0) {
            return false;
        } else {
            // All primes greater than 3 can be written in the form 6k +/- 1
            for (int divisor = 5; divisor * divisor <= number; divisor += 6) {
                if (number % divisor == 0 || number % (divisor + 2) == 0) {
                    return false; // Number is divisible by divisor or divisor + 2
                }
            }
        }
        return true; // Number is prime
    }

    vector<int> closestPrimes(int lowerBound, int upperBound) {
        int previousPrime = 0, currentPrime = 0;
        int minimumDifference = INT_MAX;
        vector<int> closestPair(2, 0);

        for (int number = lowerBound; number <= upperBound; number++) {
            if (isPrime(number)) {
                if (previousPrime == 0) {
                    previousPrime = number;
                } else {
                    currentPrime = number;
                    int difference = currentPrime - previousPrime;
                    
                    if (minimumDifference > difference) {
                        closestPair[0] = previousPrime;
                        closestPair[1] = currentPrime;
                        minimumDifference = difference;
                    }
                    
                    if (difference == 2 || difference == 1) {
                        // The closest prime pair must have a difference of at least 1 or 2
                        return {previousPrime, currentPrime};
                    }
                    
                    previousPrime = currentPrime;
                }
            }
        }

        if (previousPrime == 0 || currentPrime == 0) {
            return {-1, -1};
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