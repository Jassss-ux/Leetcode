
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //logic floypid cycle detection

        int slow = nums[0];
        // slow pointer ko starting element se initialize kar diya.


        int fast = nums[0];
        // fast pointer ko bhi starting element se initialize kar diya.


        do {

            slow = nums[slow];
            // slow ek step move karega.


            fast = nums[nums[fast]];
            // fast ek time mein do step move karega.


        } while(slow != fast);
        // jab tak slow aur fast ek dusre se equal nahi hote
        // tab tak dono pointers ko move karte rahenge.
        // Jab dono same point pe aa jayenge toh cycle detect ho gayi.


        slow = nums[0];
        // Ab slow ko dobara starting point pe le aayenge.
        // Fast wahi rahega jahan cycle ke andar dono mile the.


        while(slow != fast) {

            slow = nums[slow];
            // slow ek step move karega.


            fast = nums[fast];
            // fast bhi ab ek step move karega.


            // Ab dono same speed se move karenge.
            // Jahan dono milenge wahi duplicate number hoga.
        }


        return slow;
        // slow aur fast jahan mile hain,
        // wahi duplicate number hai, isliye usko return kar denge.
    }
};

