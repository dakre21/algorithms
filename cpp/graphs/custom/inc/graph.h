/*
 * Author: David Akre
 * Date: 3/21
 * Program: Breadth First Seaerch
 */

#include <iostream>
#include <memory>
#include <list>

class Graph
{
public:
    Graph(int num_vertices) : num_verticies_(num_vertices) {
        graph_ = new std::list<int>[num_vertices];
    }

    void addEdge(int vertex, int edge) {
        graph_[vertex].push_back(edge);
    }

    void search(int source);

private:
    int num_verticies_;
    std::list<int>* graph_;
};


