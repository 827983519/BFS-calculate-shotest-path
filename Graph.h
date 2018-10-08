#ifndef _GRAPH_H
#define _GRAPH_H

#define ERROR      -1
#define V_E_INFO    1
#define FIND        1
#define PATH        2
#define MAX         100

class ArcNode
{
    private:
        int value;
        ArcNode *next;
    
    public:
        ArcNode(int , ArcNode * = nullptr);
        void set_next(ArcNode *);
        ArcNode *get_next() const;
        int get_value() const;
        void set_value(int);
};



class List
{   
    private:
        int value;
        ArcNode *firstnode;
    public:
        List(int = 0,ArcNode * = nullptr);
        ~List();
        ArcNode *Pop();
        void Push(int);
        int get_value() const;
        int is_exist(int) const;
        ArcNode *get_firstnode() const;
        void set_value(int);
        void set_firstnode(ArcNode *);
        void print() const;
};



class Graph
{       
    private:
        List list[MAX];
        int vertices_num;
        int edge_num;
   
    public:
        Graph(int,int,int []);
        ~Graph();
        int get_vertices_num() const;
        int get_edge_num() const;
        void print() const;
        int find_shortest_path(int,int) const;
};

#endif