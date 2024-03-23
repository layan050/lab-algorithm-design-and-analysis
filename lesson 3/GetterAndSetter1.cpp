#include <iostream>
using namespace std;

class silsilah {
protected:
    string orangtua = "albert widjya dan jenny lim";
    string anakanak = "agatha widjya dan jonathan widjya";
public:
    string ceksilsilah() {
        // Extracting father and mother names
        string father = orangtua.substr(0, orangtua.find(" "));
        string mother = orangtua.substr(orangtua.find(" ") + 1);

        return "Ayah bernama " + father + " dan ibu bernama " + mother;
    }
};

class cucu : public silsilah {
protected:
    string cucu_str = "wilbert tan dan rayanza widjya";
public:
    string cekanak() {
        // Extracting first child's name
        string first_child = anakanak.substr(0, anakanak.find(" "));

        return "Anak pertama keluarga widjya adalah " + first_child;
    }
};

class anak : public cucu {
public:
    string lihantsilsilahnya() {
        return "Silsilah keluarga widjya";
    }
    string cekcucu() {
        // Extracting first and second grandchild's names
        string first_grandchild = cucu_str.substr(0, cucu_str.find(" "));
        string second_grandchild = cucu_str.substr(cucu_str.find(" ") + 1);

        return "Cucu pertama bernama " + first_grandchild + " dan cucu kedua bernama " + second_grandchild;
    }
};

int main() {
    anak silsilahwidjya;
    cout << silsilahwidjya.lihantsilsilahnya() << endl;
    cout << silsilahwidjya.ceksilsilah() << endl;
    cout << silsilahwidjya.cekanak() << endl;
    cout << silsilahwidjya.cekcucu() << endl;
    return 0;
}

