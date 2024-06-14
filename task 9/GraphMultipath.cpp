#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // Set to a large enough value

pair<int, vector <int> > findMinCost(vector<vector <int> > &graph, int n) {
    vector<vector <int> > node(1 << n, vector <int>(n, INF));
    vector<vector <int> > parent(1 << n, vector <int>(n, -1));
    
    for (int i = 0; i < n; ++i) {
        node[1 << i][i] = 0;
    }
    
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; ++v) {
                if (u == v || !(mask & (1 << v))) continue;

                if (node[mask ^ (1 << v)][u] != INF && node[mask ^ (1 << v)][u] + graph[u][v] < node[mask][v]) {
                    node[mask][v] = node[mask ^ (1 << v)][u] + graph[u][v];
                    parent[mask][v] = u;
                }
            }
        }
    }
    
    int minCost = INF;
    int lastNode = -1;
    
    for (int i = 0; i < n; ++i) {
        if (node[(1 << n) - 1][i] < minCost) {
            minCost = node[(1 << n) - 1][i];
            lastNode = i;
        }
    }
    
    vector<int> path;
    int mask = (1 << n) - 1;
    
    while (lastNode != -1) {
        path.push_back(lastNode + 1); // Add 1 to convert 0-indexed node to 1-indexed city
        int prevNode = parent[mask][lastNode];
        mask ^= (1 << lastNode);
        lastNode = prevNode;
    }
    
    reverse(path.begin(), path.end());
    
    return make_pair(minCost, path);
}

int main() {
    int totalCities;
    cout << "Enter total number of cities: ";
    cin >> totalCities;

    vector<vector <int> > costMatrix(totalCities, vector<int>(totalCities));

    cout << "Enter cost matrix values:\n";
    for (int i = 0; i < totalCities; ++i) {
        cout << "Cost element row " << i + 1 << ":\n";
        for (int j = 0; j < totalCities; ++j) {
            cin >> costMatrix[i][j];
        }
    }

    cout << "Cost matrix:\n";
    for (int i = 0; i < totalCities; ++i) {
        for (int j = 0; j < totalCities; ++j) {
            cout << costMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    pair<int, vector <int> > result = findMinCost(costMatrix, totalCities);


    int minimumCost = result.first;
    vector<int> shortestPath = result.second;

    cout << "\nMinimum cost: " << (minimumCost == INF ? -1 : minimumCost) << endl;
    cout << "Shortest path: ";
    for (int i = 0; i < shortestPath.size(); ++i) {
        cout << shortestPath[i];
        if (i != shortestPath.size() - 1) {
            cout << "-->";
        }
    }
    cout << endl;

    return 0;
}

