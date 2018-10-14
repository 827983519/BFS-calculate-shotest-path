#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <regex>
#include "Graph.h"

using namespace std;

void clear_data(int &vertices_num,int &edge_num,int edge[])
{
    memset(edge,0,MAX);
    vertices_num = 0;
    edge_num = 0;
}


int check_input(int vertices_num,int edge_num,int edge[])
{
    
    for(int i = 0;i < edge_num; i++)
    {
        
        if(edge[i] >= vertices_num)
        {   
            cout << "Error: ask for a shortest path to a vertex that does not exist" << endl;
            return ERROR;
        }
    }
    return V_E_INFO;
}

/***
*  
*/
int get_input(int &vertices_num,int &edge_num,int edge[],int src_dst[])
{
    string vertices_info;
    string edge_info;
    
    getline(cin,vertices_info);

    if(vertices_info[0] == 'V')
    {
        clear_data(vertices_num,edge_num,edge);

        getline(cin,edge_info);
        vertices_num = atoi(&vertices_info[2]);
        regex reg1("\\d+");
        sregex_iterator it(edge_info.begin(), edge_info.end(), reg1);
        sregex_iterator end;
        for(; it != end; ++it)
        {
            edge[edge_num] = stoi(it-> str());
            edge_num++;
        }

        return check_input(vertices_num,edge_num,edge);
    }

    else if(vertices_info[0] == 's')
    {  
        int j = 0;
        regex reg1("\\d+");
        sregex_iterator it(vertices_info.begin(), vertices_info.end(), reg1);
        sregex_iterator end;

        for(; it != end; ++it)
        {
            src_dst[j] = stoi(it-> str());
            j++;
        }

        if(src_dst[0] == src_dst[1])
        {
            cout << "Error: The starting vertex is the same as the ending vertex" << endl;
            return ERROR;
        }
        return PATH;
    }
        
}


/*int main()
{
    int vertices_num = 0,edge_num = 0;
    int edge[MAX];
    int ret = 1;
    int src_dst[2];

    memset(edge,0,MAX);
    
    while(ret != ERROR)
    {
        ret = get_input(vertices_num,edge_num,edge,src_dst);
    
        if(ret == PATH)
        {
            Graph Adjacency_table(vertices_num,edge_num,edge);
            //Adjacency_table.print();
            ret = Adjacency_table.find_shortest_path(src_dst[0],src_dst[1]);
        }
        
    }
    return 0;
}*/
int main()
{
    int vertices_num = 0,edge_num = 0;
    int edge[MAX];
    int ret = 1;
    int src_dst[2];

    memset(edge,0,MAX);
    
    while(ret != ERROR)
    {
        ret = get_input(vertices_num,edge_num,edge,src_dst);
    
        if(ret == PATH)
        {
            Graph Adjacency_table(vertices_num,edge_num,edge);
            Adjacency_table.print();
            Adjacency_table.dfs_print_path(src_dst[0],src_dst[1]);
            Adjacency_table.dfs_print(src_dst[0]);
            //Adjacency_table.dfs_non_recursive();
        }
        
    }
    return 0;
}