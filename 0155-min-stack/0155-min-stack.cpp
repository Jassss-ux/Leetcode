class MinStack {
public:
    stack<long long int> s;
    long long int minval; // Current minimum element ko store karega

    MinStack() {

    }

    void push(int val) {

        // Agar stack khali hai to jo pehla element aayega wahi minimum hoga
        if (s.empty()) {
            s.push(val);
            minval = val;
        }
        else {

            // Agar naya element current minimum se chhota hai
            if (val < minval) {

                // Actual value push nahi karte,
                // ek encoded value push karte hain:
                // encoded = 2*val - oldMin
                // Isse future me old minimum recover kar sakte hain.
                s.push((long long)2 * val - minval);

                // Ab current minimum update ho jayega
                minval = val;
            }
            else {

                // Agar new value minimum se badi ya equal hai
                // to usse normally push kar do
                s.push(val);
            }
        }

    }

    void pop() {

        // Agar top encoded value hai
        // (encoded value hamesha current minimum se chhoti hoti hai)
        if (s.top() < minval) {

            // Previous minimum recover karo
            // oldMin = 2*currentMin - encodedValue
            minval = 2 * minval - s.top();
        }

        // Top remove kar do
        s.pop();
    }

    int top() {

        // Agar top encoded value hai
        // to actual top current minimum hi hoga
        if (s.top() < minval) {
            return minval;
        }
        else {

            // Normal value stored hai
            return s.top();
        }

    }

    int getMin() {

        // Current minimum hamesha minval me stored rehta hai
        return minval;

    }
};