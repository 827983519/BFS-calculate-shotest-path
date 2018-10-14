#include <iostream>

#define INF 0xffff
using namespace std;

int visited[vertices_num];
void init()
{
    int i = 0;
    for(;i < vertices_num;i++)
        visited[i] = INF;
    visited[src] = 0;
}

void dfs(int src)
{
    ArcNode *a = list[src].firstnode;
    while(a != nullptr)
    {
        if(visited[a -> get_value()] != INF)
        {
            visited[a -> get_value()] = 0;
            dfs(a -> get_value());
        }
        a = a -> get_next();
    }

}
