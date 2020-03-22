#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <utility>

using namespace std;

template<typename T>
class Graph
{
public:
    Graph(const vector<string>& nodes) {
        for (auto node : nodes) {
            graph_[node] = vector<string>{};
        }
    }

    void addEdge(T source, T sink) {
        graph_[source].push_back(sink);
    }

    map<string, vector<string> > getGraph() const {
        return graph_;
    }

private:
    map<string, vector<string> > graph_;
};

template<typename T>
void buildGraph(const vector<pair<string, string> >& dependencies, Graph<T>& graph) {
    for (auto dependency : dependencies) {
        graph.addEdge(dependency.first, dependency.second);
    }
}

template<typename T>
vector<string> orderProjects(const Graph<T>& graph) {
    stack<string> current;

    auto curr = graph.getGraph();
    map<string, bool> visited;
    for (auto it : curr) {
        visited[it.first] = false;
    }

    stack<string> ordered;
    auto it = curr.begin();
    for (; it != curr.end(); it++) {
        current.push(it->first);
        stack<string> tmp;
        if (not visited[current.top()]) {
            while (not current.empty()) {
                string visit = current.top();
                current.pop();
                visited[visit] = true;
           
                for (auto node : it->second) {
                    if (not visited[node]) {
                        current.push(node);
                        tmp.push(node);
                    }
                }
            }
            while (not tmp.empty()) {
                ordered.push(tmp.top());
                tmp.pop();
            }
            ordered.push(it->first);
        }
    }

    vector<string> result;
    while (not ordered.empty()) {
        result.push_back(ordered.top());
        ordered.pop();
    }
    return result;
}

void printProjects(const vector<string>& projects) {
    for (auto project : projects) {
        cout << project << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    vector<string> projects{ "a", "b", "c", "d", "e", "f", "g" , "h" };
    Graph<string> graph(projects);

    vector<pair<string, string> > dependencies{
        make_pair("a", "e"), make_pair("b", "e"), make_pair("b", "h"), 
        make_pair("c", "a"), make_pair("d", "g"), make_pair("f", "c"), 
        make_pair("f", "b"), make_pair("f", "a")
    };
    buildGraph(dependencies, graph);

    cout << "Original projects (unordered)" << endl;
    printProjects(projects);

    cout << "Ordered projects" << endl;
    vector<string> ordered = orderProjects(graph);
    printProjects(ordered);

    return 0;
}
