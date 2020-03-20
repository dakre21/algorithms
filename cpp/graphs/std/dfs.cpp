#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void search(const vector<vector<int> >& graph, int source) {
    vector<bool> visited(graph.size(), false);
    stack<int> current;

    current.push(source);
    while (not current.empty()) {
        int visit = current.top();
        current.pop();
        visited[visit] = true;

        cout << visit << endl;

        for (auto node : graph[visit]) {
            if (not visited[node]) {
                current.push(node);
                break;    
            }
        }
    }
}

/* Total Nodes: 0, 1, 2, 3, 4
 *
 * Directed Graph
 * 0 -> 1
 * 0 -> 3
 * 0 -> 4
 * 1 -> 2
 * 2 -> 3
 * 2 -> 0
 * 3 -> 4
 * Undirected Graph
 * 0 - 1
 * 0 - 3
 * 0 - 4
 * 1 - 2
 * 2 - 3
 * 3 - 4
 */
int main(int argc, char* argv[]) {
    vector<vector<int> > directed;
    directed.push_back(vector<int>{ 1, 3, 4 });
    directed.push_back(vector<int>{ 2 });
    directed.push_back(vector<int>{ 3 });
    directed.push_back(vector<int>{ 4 });
    directed.push_back(vector<int>{ });

    cout << "Searching directed graph (from 0)" << endl;
    search(directed, 0);
    cout << "Searching directed graph (from 2)" << endl;
    search(directed, 2);

    vector<vector<int> > undirected;
    undirected.push_back(vector<int>{ 1, 3, 4 });
    undirected.push_back(vector<int>{ 0, 2 });
    undirected.push_back(vector<int>{ 1, 3 });
    undirected.push_back(vector<int>{ 0, 4 });
    undirected.push_back(vector<int>{ 0 });

    cout << "Searching undirected graph (from 0)" << endl;
    search(undirected, 0);
    cout << "Searching undirected graph (from 2)" << endl;
    search(undirected, 2);

    return 0;
}
