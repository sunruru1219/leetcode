class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;

    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);
        if (minstk.empty()) minstk.push(value);
        else minstk.push(min(minstk.top(), value));
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
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