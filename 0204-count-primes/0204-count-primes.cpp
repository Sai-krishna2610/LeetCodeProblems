class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2) {
            return 0;
        }

        vector<bool> isPrime(n / 2, true);

        int primeCount = 1; 

        for (int number = 3; number < n; number += 2) {

            if (isPrime[number / 2]) {

                primeCount++;

                if (number <= (n - 1) / number) {

                    for (int multiple = number * number;
                         multiple < n;
                         multiple += 2 * number) {

                        isPrime[multiple / 2] = false;
                    }
                }
            }
        }

        return primeCount;
    }
};