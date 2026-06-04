class MinStack {
private:
    stack <int> Min;
    stack <int> values;

public:
    MinStack() {
        Min.push(INT_MAX);
    }
    
    void push(int val) {
        values.push(val);
        Min.push(min(Min.top(), val));
    }
    
    void pop() {
        values.pop();
        Min.pop();
    }
    
    int top() {
        return values.top();
    } 
    
    int getMin() {
        return Min.top();
    }
};
