#include <iostream>
using namespace std;

class hewan {
private:
    string nama;
    string spesies;
public:
    void setnama(string n) {
        nama = n;
    }
    void setspesies(string s) {
        spesies = s;
    }
    string getnama() { // Corrected function name
        return nama;
    }
    string getspesies() {
        return spesies;
    }
};

int main() {
    hewan my_hewan; // Changed object name to avoid naming conflict
    my_hewan.setnama("Kucing");
    my_hewan.setspesies("Felis Catus");

    cout << "nama: " << my_hewan.getnama() << endl; // Corrected function call
    cout << "spesies: " << my_hewan.getspesies() << endl;
    return 0;
}

