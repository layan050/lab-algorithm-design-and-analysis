#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    struct Edge {
        int to;
        int weight;
    };

    vector<vector <Edge> > adjacency_list;
    int num_vertices;

public:
    Graph(int n) : num_vertices(n), adjacency_list(n + 1) {}

    void addEdge(int from, int to, int weight) {
        adjacency_list[from].push_back({to, weight});
    }

    vector<int> dijkstra(int source) {
        vector<int> dist(num_vertices + 1, INF);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int current_dist = pq.top().first;
            pq.pop();

            if (current_dist > dist[u]) continue;

   			for (int i = 0; i < adjacency_list[u].size(); ++i) {
            	int v = adjacency_list[u][i].to;
            	int weight = adjacency_list[u][i].weight;
            	int new_dist = dist[u] + weight;
            	if (new_dist < dist[v]) {
               	 dist[v] = new_dist;
                	pq.push({new_dist, v});
            	}
        	}
    	}

        return dist;
    }
};

int main() {
    int n = 6;
    Graph graph(n);

    graph.addEdge(1, 2, 7);
    graph.addEdge(1, 3, 9);
    graph.addEdge(1, 6, 14);
    graph.addEdge(2, 1, 7);
    graph.addEdge(2, 3, 10);
    graph.addEdge(2, 4, 15);
    graph.addEdge(3, 1, 9);
    graph.addEdge(3, 2, 10);
    graph.addEdge(3, 4, 11);
    graph.addEdge(3, 6, 2);
    graph.addEdge(4, 2, 15);
    graph.addEdge(4, 3, 11);
    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 4, 6);
    graph.addEdge(5, 6, 9);
    graph.addEdge(6, 1, 14);
    graph.addEdge(6, 3, 2);

    int source_node = 1;

    vector<int> shortest_distances = graph.dijkstra(source_node);

    cout << "Shortest distances from node " << source_node << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "To node " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}

