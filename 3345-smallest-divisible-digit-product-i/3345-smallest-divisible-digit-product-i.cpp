class Solution {
public:

    // Function to calculate the product of all digits
    // Example:
    // num = 234
    // product = 1
    // 1 × 4 = 4
    // 4 × 3 = 12
    // 12 × 2 = 24
    // Returns 24
    int digitproduct(int num) {
        int product = 1;

        while (num > 0) {
            product *= (num % 10);   // Multiply by the last digit
            num /= 10;               // Remove the last digit
        }

        return product;
    }

    int smallestNumber(int n, int t) {

        // Keep checking numbers one by one until we find the answer.
        // Example:
        // n = 15, t = 3
        //
        // 15 → digit product = 1×5 = 5 → 5 % 3 != 0 ❌
        // n++ → 16
        //
        // 16 → digit product = 1×6 = 6 → 6 % 3 == 0 ✅
        // Return 16
        while (true) {

            // If the current number's digit product is divisible by t,
            // this is the smallest valid number because we started from n
            // and checked every number in increasing order.
            if (digitproduct(n) % t == 0) {
                return n;
            }

            // Current number is not valid, so check the next number.
            n++;
        }
    }
};