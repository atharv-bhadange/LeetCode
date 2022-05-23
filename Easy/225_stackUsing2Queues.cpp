class MyStack
{
public:
    queue<int> q1, q2;
    int sz;
    MyStack()
    {
        sz = 0;
    }

    void push(int x)
    {
        q1.push(x);
        sz++;
    }

    int pop()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        sz--;
        return k;
    }

    int top()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q2.push(q1.front());
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return k;
    }

    bool empty()
    {
        if (sz == 0)
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