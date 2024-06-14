#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector <int> > adjList;
    int numVertices;

public:

    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }
    
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void defineSinglePathGraph() {
        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(2, 3);
        addEdge(3, 4);
        addEdge(4, 5);
        addEdge(5, 6);
        addEdge(6, 7);
        addEdge(7, 8);
    }

    
    vector<int> calculateDistances(int source) const {
        vector<int> distances(numVertices, -1);
        queue<int> q;

        distances[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < adjList[current].size(); ++i) {
                int neighbor = adjList[current][i];
                if (distances[neighbor] == -1) { // If not visited
                    distances[neighbor] = distances[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distances;
    }

    void printDistances(const vector<int>& distances) const {
        cout << "Vertex\tDistance from source\n";
        for (int i = 0; i < distances.size(); ++i) {
            cout << i << "\t" << distances[i] << endl;
        }
    }
};

int main() {
    int numVertices = 9;

    Graph graph(numVertices);

    graph.defineSinglePathGraph();

    int source = 0;

    vector<int> distances = graph.calculateDistances(source);
    
    graph.printDistances(distances);

    return 0;
}

