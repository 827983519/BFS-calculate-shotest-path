#include <iostream>
#include "Graph.h"
#include <queue>
#include <stack> 
using namespace std;

/*****************The function of class ArcNode*********************/
ArcNode::ArcNode(int data, ArcNode *next):value(data),next(next)
{
}

int ArcNode::get_value() const
{
    return value;
}

ArcNode *ArcNode::get_next() const
{
    return next;
}

void ArcNode::set_next(ArcNode *n)
{
    next = n;
}

void ArcNode::set_value(int v)
{
    value = v;
}

/*****************The function of class List*********************/
List::List(int data, ArcNode *first):value(data),firstnode(first)
{
}

List::~List()
{
    ArcNode *b = firstnode;
    while(b != nullptr)
    {
        ArcNode *a = b -> get_next();
        delete b;
        b = a;
    }   
}

void List::Push(int data)
{
    ArcNode *a = new ArcNode(data,firstnode);
    firstnode = a;
}

ArcNode *List::Pop()
{
    if(firstnode == nullptr)
        return nullptr;
    ArcNode *a = firstnode;
    firstnode = firstnode -> get_next();
    return a;
}

int List::get_value() const 
{
    return value;
}

ArcNode *List::get_firstnode() const
{
    return firstnode;
}

void List::set_value(int v)
{
    value = v;
}

void List::set_firstnode(ArcNode *f)
{
    firstnode = f;
}

void List::print() const
{
    ArcNode *a = firstnode;
    while(a != nullptr)
    {
        cout << a -> get_value() << " ";
        a = a -> get_next();
    }
}

int List::is_exist(int item) const
{
    ArcNode *a = firstnode;
    while(a != nullptr)
    {
        if(a -> get_value() == item)
            return 1;
        a = a -> get_next();
    }
    return -1;
}

/*************************************************/
Graph::Graph(int v_num,int e_num,int edge[])
{
    vertices_num = v_num;
    edge_num = e_num;
    for(int i = 0;i < v_num;i++)
    {
        list[i].set_value(i);
        for(int j = 0;j < e_num;j += 2)
        {
            if(edge[j] == i)
                list[i].Push(edge[j+1]);
            else if(edge[j + 1] == i)
                list[i].Push(edge[j]);
        }   
    }
}

Graph::~Graph()
{

}

int Graph::get_vertices_num() const
{
    return vertices_num;
}

int Graph::get_edge_num() const
{
    return edge_num;
}


void Graph::print() const
{
    for(int i = 0; i < vertices_num; i++)
    {
        cout << "List " << i << ": ";
        list[i].print();
        cout << endl;
    }
}

int Graph::find_shortest_path(int src,int dst) const
{
    queue<int> myQ;
    int value[vertices_num];
    int head = 0;
    int output[10];
    for(int i = 0;i < vertices_num;i++)
    {
        value[i] = -1;
    }

    value[src] = 0;
    myQ.push(src);

    while(myQ.size())
    {
        head = myQ.front();
        myQ.pop();
        if(head == dst)
        {
            int find = dst;
            stack<int> myS;
            myS.push(dst);
            while(find != src)
            {   
                for(int j = 0; j < vertices_num; j++)
                {
                    if((list[j].is_exist(find) == 1) && (value[find] == value[j] + 1))
                    {
                        myS.push(j);
                        find = j;
                        break;
                    }
                }
            }

            int count = myS.size();
            for(int j = 0;j < count;j++)
            {
                if(j == count - 1)
                    cout << myS.top() << endl;
                else
                {
                    cout << myS.top() << "-";
                    myS.pop();
                }
            }
        
            return FIND;
        }
        ArcNode *a = list[head].get_firstnode();

        while( a != nullptr)
        {
            if(value[a -> get_value()] == -1)
            {
                value[a -> get_value()] = value[head] + 1;
                myQ.push(a -> get_value());
            }
            a = a -> get_next();
        }
    }
    cout << "Error: no path between " << src << " and " << dst << endl;
    return ERROR;
}