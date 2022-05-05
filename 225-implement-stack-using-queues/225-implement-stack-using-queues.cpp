class MyStack {
public:
    queue<int>Q1;
    queue<int>Q2;
    MyStack() {
        // Q1.clear();
        // Q2.clear();
    }
    
    void push(int x) {
        if(Q1.empty() && Q2.empty())
        {
            Q1.push(x);
        }
        else if(Q1.empty())
        {
            Q1.push(x);
            while(!Q2.empty())
            {
                Q1.push(Q2.front());
                Q2.pop();
            }
        }
        else if(Q2.empty())
        {
            Q2.push(x);
            while(!Q1.empty())
            {
                Q2.push(Q1.front());
                Q1.pop();
            }
        }
    }
    
    int pop() {
        int t;
        if(!Q1.empty())
        {
            t=Q1.front();
            Q1.pop();
        }
        else if(!Q2.empty())
        {
            t=Q2.front();
            Q2.pop();
        }
        return t;
    }
    
    int top() {
        int t;
        if(!Q1.empty())
        {
            t=Q1.front();
        }
        else if(!Q2.empty())
        {
            t=Q2.front();
        }
        return t;
    }
    
    bool empty() {
        if(Q1.empty() && Q2.empty())
            return true;
        else
            return false;
        }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */