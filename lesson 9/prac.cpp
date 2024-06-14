#include<iostream>
#include<vector>
using namespace std;

class Graph {
private:
    int TotalSimpul;
    vector<vector <int> > matrix;

public:
    Graph(int simpul) {
        TotalSimpul = simpul;
        for(int i = 0; i < simpul; ++i) {
            vector<int> baris(simpul, 0);
            matrix.push_back(baris);
        }
    }

    void tambahSisi(int u , int v) {
        if (u >= 0 && u < TotalSimpul && v >= 0 && v < TotalSimpul) {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        } else {
            cout << "Sisi tidak Valid!" << endl;
        }
    }

    void hapusSisi(int u, int v) {
        if (u >= 0 && u < TotalSimpul && v >= 0 && v < TotalSimpul) {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        } else {
            cout << "Sisi tidak valid!" << endl;
        }
    }

    void tampilkan() {
        for(int i = 0; i < TotalSimpul; i++) {
            for(int j = 0; j < TotalSimpul; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int simpul = 5;
    Graph g(simpul);
    g.tambahSisi(0, 1);
    g.tambahSisi(0, 4);
    g.tambahSisi(1, 2);
    g.tambahSisi(1,3);
    g.tambahSisi(1, 4);
    g.tambahSisi(2, 3);
    g.tambahSisi(3, 4);

    cout << "Matrix ketetanggan: " << endl;
    g.tampilkan();

    cout << "Matrix ketetanggan setelah menghapus sisi antara 1 dan 3: " << endl;
    g.hapusSisi(1, 3);
    g.tampilkan();

    return 0;
}

