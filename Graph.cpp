#include "Graph.h"

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
    cout << "Constructing!" << endl;
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
    cout << "Destructing!" << endl;
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

List *Graph::get_list(int num) 
{
    return &(list[num]);
}

void Graph::dfs_non_recursive() const
{
    stack<int> st;
    int visited[vertices_num];

    for(int i = 0;i < vertices_num;i++)
    visited[i] = 0;
    visited[0] = 1;
    st.push(0);

    while(!st.empty())
    {
        ArcNode *a = list[st.top()].get_firstnode();
        while(a != nullptr)
        {
            if(visited[a -> get_value()] != 1)
            {
                st.push(a -> get_value());
                visited[a -> get_value()] = 1;
                cout << a -> get_value() << " ";
                break;
            }
            else
                a = a -> get_next();
        }
        if(a == nullptr)
        st.pop();
    }
}

void Graph::dfs(int src,int visited[],int &count) const
{
    ArcNode *a = list[src].get_firstnode();
    while(a != nullptr)
    {
        count++;
        if(visited[a -> get_value()] != 1)
        {
            visited[a -> get_value()] = 1;
            cout << a -> get_value() << "  ";
            dfs(a -> get_value(),visited,count);
        }
        a = a -> get_next();
    }
}

void Graph::dfs_print(int src) const
{
    int visited[vertices_num];
    int i = 0;
    int count = 0;;
    for(;i < vertices_num;i++)
        visited[i] = 0;
    visited[src] = 1;
    dfs(src,visited,count);
    cout << "c" << count << endl;
}


void Graph::dfs_print_path(int src,int dst) const
{
    int in_stack[vertices_num];
    int count = 0;
    int i = 0;
    stack<int> st;
    for(;i < vertices_num;i++)
        in_stack[i] = 0;
    in_stack[src] = 1;
    st.push(src);
    dfs_find_path(src,dst,in_stack,st,count);
    cout << "count:" << count << endl;
}

void Graph::dfs_find_path(int src,int dst,int in_stack[],stack<int> &st,int &count) const
{
    ArcNode *a = list[src].get_firstnode();
    while(a != nullptr)
    {
        count++;
        if(a -> get_value() == dst)
        {
            
            cout << st.size() << endl;
            /*int i = 0;
            int st_num = 0;
            int tem[100];
            st.push(a -> get_value());
            while(st.empty() != true)
            {
                tem[st_num] = st.top();
                st.pop();
                st_num++;
            }
            for(i = st_num - 1;i >= 0;i--)
            {
                cout << tem[i];
                if(i != 0)
                cout << " -> ";
                st.push(tem[i]);
            }
            st.pop()；*/   

        }
        else if(in_stack[a -> get_value()] == 0)
            {
                in_stack[a -> get_value()] = 1;
                st.push(a -> get_value());
                dfs_find_path(a -> get_value(),dst,in_stack,st,count);           
            }
        a = a -> get_next();
    }
    in_stack[st.top()] = 0;
    st.pop();
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
/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Graph example")
{
    int vertices_num = 5;
    int edge_num = 8;
    int edge[8] = {0,1,2,3,4,2,1,5};

    Graph gr(vertices_num,edge_num,edge);
    gr.print();
    List *a = gr.get_list(3);

    CHECK(gr.get_vertices_num() == 5);
    CHECK(gr.get_edge_num() == 8);
    CHECK(a -> get_value() == 3);
}*/
