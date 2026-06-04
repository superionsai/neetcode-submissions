class MinStack {
private:
    long Min = 0;
    stack <long> values;

public:
    MinStack() {}
    
    void push(int val) {
        if (values.empty()) {
            values.push(0);
            Min = val;
        }
        else {
            values.push(val - Min);
            if (val < Min) Min = val;
        }
    }
    
    void pop() {
        if (values.empty()) return;
        long pop = values.top();
        values.pop();

        if (pop < 0) Min = Min - pop;
    }
    
    int top() {
        long top = values.top();
        return (top > 0) ? (top + Min) : (int)Min;
    } 
    
    int getMin() {
        return (int)Min;
    }
};
