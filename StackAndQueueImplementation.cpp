#include<bits/stdc++.h>
using namespace std;
#define el cout<<endl;

class stk{
    vector<int> v;
    int top=-1;
    public:
    stk(int n)
    {
        v.resize(n);
    }
    void push(int num)
    {
        if (top==v.size()-1)
        {
            cout<<"stack id full";
            el
            return;
        }
        top++;
        v[top]=num;
        cout<<"item pushed into stack";
        el
    }
    void pop()
    {
        if (top==-1)
        {
            cout<<"stack is empty";
            el
            return;
        }
        top--;
        cout<<"item poped";
        el
    }
    int Size()
    {
        return top+1;
    }
    int Top()
    {
        return v[top];
    }
};




class iqueue
{
    vector<int> v;
    int start, end;
    int n;

public:
    iqueue(int size)
    {
        n = size;
        v.resize(size);
        start = -1;
        end = 0;
    }

    void push(int num)
    {
        if (start !=-1 &&  (start+1 == end || (start == n-1 && end == 0)) )
        {
            cout<<"queue is full\n";
            return;
        }
        if (start == n-1 ) start = 0;
        else start++;
        v[start] = num;
        cout<<"pushed to queue\n";
    }

    void pop()
    {
        if (start == -1 ) 
        {
            cout<<"queue is empty\n";
            return;
        }
        if (end == start ) start = -1;
        end = (end + 1) % n;
        cout<<"item poped\n";

    }

    int top()
    {
        if (start == -1 ) return -1;
        return v[end];
    }
    int size()
    {
        if (start == -1 ) return 0;
        if (start >= end) return start - end + 1;
        else return start + n - end + 1;
    }


};


class llnode {
    public: 
    int data;
    llnode* next;
    llnode(int val)
    {
        data = val;
        next = NULL;
    }
    llnode(int val, llnode *nextNode)
    {
        data = val;
        next = nextNode;
    }
};


class lstack{
    llnode* head;
    int size;

    public:
    lstack()
    {
        head = NULL;
        size=0;
    }

    void push(int num)
    {
        llnode* newnode = new llnode(num, head);
        head = newnode;
        size++;
    }

    void pop()
    {
        llnode* temp = head;
        if (head == NULL)
        {
            cout<<"stack is empty\n";
            return;
        }
        head = head->next;
        delete temp;
        size--;

    }
    int top()
    {
        if (head == NULL)
        {
            cout << "stack is empty\n";
            return -1;
        }
        return head->data;
    }
    int Size()
    {
        return size;
    }
};



class lqueue{
    llnode start , end;
    int size;
    public:
    lqueue()
    {
        start = NULL;
        end = NULL;
        size = 0;
    }


    void push(int num)
    {
        llnode* newnode = new llnode(num);
        if (start == NULL)
        {
            start = newnode;
            end = newnode;
        }
        else {
            end->next = newnode;
            end = newnode;
        }
        size++;
    }
    void pop()
    {
        if (start == NULL )
        {
            cout<<"queue is empty\n";
            return;
        }
        llnode* temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    int top()
    {
        if (start == NULL)
        {
            cout<<"queue is empty\n";
            return -1;
        }
        return start->data;
    }
    int Size()
    {
        return size;
    }


}

int main()
{  
    // stk s1(5);
    // s1.push(3);
    // cout<<s1.Size();
    // el
    // s1.pop();
    // cout<<s1.Size();
    // el
    // s1.push(12);
    // cout<<s1.Top();
    // el


    iqueue q(5);
    q.push(1);
    q.push(2);
    cout<<q.size();
    el
    q.pop();
    cout<<q.size();
    el
    q.push(3);
    cout<<q.top();
    el
    q.push(4);
    cout<<q.size();
    el
    q.pop();
    cout<<q.size();
    el
    q.push(5);
    cout<<q.top();
    el
    q.pop();


}