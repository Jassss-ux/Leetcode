class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Example:
        // nums = [1,1,2,2,3]
        //
        // i = Last unique element
        // j = Traverses the array
        //
        // Initially
        // i = 0
        //
        // Index : 0 1 2 3 4
        // Value : 1 1 2 2 3
        //         ↑
        //         i
        int n = nums.size();
        if (n == 0)
            return 0;

        int i = 0;

        // j starts from index 1 because first element is always unique
        for (int j = 1; j < n; j++) {

            // If current element is different from the last unique element
            if (nums[i] != nums[j]) {

                // Example:
                //
                // nums = [1,1,2,2,3]
                //
                // j = 2
                //
                // nums[i] = 1
                // nums[j] = 2
                //
                // New unique element found.

                i++;                // Move i to next position
                nums[i] = nums[j];  // Place new unique element

                // Array becomes
                //
                // 1 2 2 2 3
                //   ↑
                //   i
            }

            // Duplicate elements are simply ignored.
            //
            // Example:
            //
            // nums = [1,2,2,2,3]
            //            ↑
            //            j
            //
            // nums[i] == nums[j]
            //
            // Do nothing.
        }

        // Final Example:
        //
        // nums = [1,2,3,2,3]
        //
        // Only first (i+1) elements matter.
        //
        // Valid part:
        // [1,2,3]
        //
        // Remaining values can be anything.
        return i + 1;
    }
};