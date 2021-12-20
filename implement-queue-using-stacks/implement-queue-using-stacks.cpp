class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) transfer();
        if(s2.empty()) return -1;
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    
    int peek() {
        if(s2.empty()) transfer();
        return (s2.empty())? -1:s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
    void transfer() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */