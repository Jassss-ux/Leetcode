class MinStack {
public:
    stack<pair<int, int>> s; // val , minval ka pair contain krta hai
    MinStack() {

    }

    void push(int val) {
        if (s.empty()) { // stack khali hai toh jonse first ayega element vohi // min hoga and vohi elemnt add hoga
            s.push({val, val});
        } else { // ab hume min find bhi krna pdega second val push knre ke badh
            int minval = min(val  , s.top().second);
            s.push({val, minval});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;  // humko value return knri and voh pair mein first pe hai
    }

    int getMin() {
        return s.top().second; //humne minvalue deni hai jo pair ke second pe haih 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */