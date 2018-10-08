#include <iostream>
#include <string>
#include <queue>
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

int main()
{   
    
/*
    A a;
    a.a = 12;
    a.print();
    A b(3);
    b.print();
    A c(4,5);
    c.print();*/
    /*queue<int> myQ;
    myQ.push(10);
    int i;
    myQ.pop();*/
    string a;
    getline(cin,a);
    cout << a[2];
    return 0;
}
