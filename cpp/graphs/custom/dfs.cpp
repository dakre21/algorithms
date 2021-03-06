/*
 * Author: David Akre
 * Date: 3/21
 * Program: Depth First Seaerch
 */

#include "graph.h"


void Graph::search(int source) {
    bool visited[num_verticies_] = { false };
    std::list<int> queue;
    
    visited[source] = true;
    queue.push_back(source);
    std::cout << source << std::endl;

    std::list<int>::iterator it;
    while (not queue.empty()) {
        source = queue.back();

        bool forward = false;
        for (it = graph_[source].begin(); it != graph_[source].end(); ++it) {
            if (not visited[*it]) {
                visited[*it] = true;
                queue.push_back(*it);
                std::cout << *it << std::endl;
                forward = true;
                break;
            }
        }

        if (forward) {
            continue;
        }
        queue.pop_back();
    }
}


int main(int argc, char* argv[]) {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.search(2);

    return 0;    
}
