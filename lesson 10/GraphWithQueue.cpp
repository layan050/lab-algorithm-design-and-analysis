#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define M 1000
using namespace std;

const int N = 5;

void dijkstra(int graph[N][N], int source, int des) {
    vector<pair <int, int> > adj[N];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] != M) {
                adj[i].push_back(make_pair(j, graph[i][j]));
            }
        }
    }
    
    int dist[N], prev[N];
    for(int i = 0; i < N; i++) {
        dist[i] = M;
        prev[i] = -1;
    }
    
    priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair <int, int> > > pq;
    pq.push(make_pair(0, source - 1));
    dist[source - 1] = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for(int i = 0 ; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    cout << "Beban = ";
    for(int i = 0; i < N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    cout << "Rute = ";
    for(int i = 0; i < N; i++) {
        cout << prev[i] << " ";
    }
    cout << endl;
}

int main() {
    int graph[N][N] = {
        {0, 1, 3, M, M},
        {M, 0, 1, M, 5},
        {3, M, 0, 2, M},
        {M, M, M, 0, 3},
        {M, M, M, M, 0}
    };
    
    int source, des;
    cout << "Masukkan node asal: ";
    cin >> source;
    cout << "Masukkan node tujuan: ";
    cin >> des;
    
    dijkstra(graph, source, des);
    
    return 0;
}

