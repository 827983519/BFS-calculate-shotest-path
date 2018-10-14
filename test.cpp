#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int* test(int i)
{
    static int j[10] = {1,2,3,4,5,6,7,8,9,10};  
    return j;
}

class A
{
    private:
        int a;
        int b;
    public:
    A(int = 1,int = 2);
    void print();
};

A::A(int aa,int bb):a(aa),b(bb)
{}

void A::print()
{
    cout << a << " " << b << endl;
}

void print(stack<int> &a)
{
    cout << "check";
}

int main()
{   
    stack<int> st;
    st.push(10);
    st.push(12);
    st.push(13);
    st.push(4);
    int i = 0;
    int st_num = 0;
    int tem[100];

     while(st.empty() != true)
    {
        st.top() = tem[st_num];
        st.pop();
        st_num++;

    }
    cout << "st_num:" << st_num;
    for(i = st_num - 1;i >= 0;i--)
    {
        cout << "i: " << i << endl;
        cout << tem[i];
        if(i != 0)
        cout << " -> ";
        st.push(tem[i]);
    }
        
    return 0;
}
