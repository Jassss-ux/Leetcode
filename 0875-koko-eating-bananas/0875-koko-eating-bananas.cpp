class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // ----------------------------------------------------------
        // piles[i] = ith pile me kitne bananas hain.
        // h = Total hours jinke andar saare bananas finish karne hain.
        //
        // Har hour:
        // -> Koko sirf EK pile choose kar sakti hai.
        // -> Maximum 'k' bananas kha sakti hai.
        //
        // Hume minimum eating speed (k) find karni hai.
        //
        // Observation:
        // Speed ↑  => Required Hours ↓
        //
        // Isliye Binary Search on Answer use karenge.
        // ----------------------------------------------------------

        // Minimum possible speed
        int start = 1;

        // Maximum possible speed = Largest pile
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while (start <= end) {

            // Assume current eating speed = mid
            int mid = start + (end - start) / 2;

            // Total hours required at speed = mid
            long long totalHours = 0;

            // Calculate hours for every pile
            for (int bananas : piles) {

                // Example:
                // bananas = 11
                // speed = 4
                //
                // 11 / 4 = 2.75
                // ceil(2.75) = 3 hours
                // ceil is a fucntion which converts the value of a number into the nearest posiible ggreater number as seen in above example : 2.7 = 3
                // (double) is necessary because
                // integer division would make 11/4 = 2

                totalHours += ceil((double)bananas / mid);
            }

            // If Koko can finish within h hours,
            // current speed is valid.
            if (totalHours <= h) {

                ans = mid;

                // Try to find an even smaller valid speed
                end = mid - 1;
            }
            else {

                // Speed is too slow.
                // Increase the eating speed.
                start = mid + 1;
            }
        }

        return ans;
    }
};