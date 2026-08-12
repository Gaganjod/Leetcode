class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int value) {
        st1.push(value);
        if(st2.empty() || value<=st2.top()){
            st2.push(value);
        }
    }
    
    void pop() {
        if(st1.empty()) return;
        if(st1.top()==st2.top()){
            st2.pop();
        }
        st1.pop();
    }
    
    int top() {
       return st1.top();
    }
    
    int getMin() {
        return st2.top();
        
    }
};

