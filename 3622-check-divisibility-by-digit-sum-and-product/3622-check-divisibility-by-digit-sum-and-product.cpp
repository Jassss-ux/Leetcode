class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int num = n;
        int product = 1;

        while (n > 0) {
            int rem = n % 10;

            sum = sum + rem;
            product = product * rem;

            n = n / 10;
        }


        if (num % (sum + product) == 0)  {
            return true;
        }

        return false;
    }
};