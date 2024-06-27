#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int storage[1024];
int i = 0;
int hdt_boundary;

void addLinearProbing(int n) {
    bool inserted = false;
    int hash;
    i = 0;
    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary) + i;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }
    if (i == 0) {
        cout << "Langsung " << endl;
    }
    cout << "Isi hash [ " << hash << "] dengan " << n << endl;
    cout << "========================================================" << endl;
}

void addQuadricProbing(int n) {
    bool inserted = false;
    int hash;
    int i = 0;
    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary) + (i * i);
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }
    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[ " << hash << "] dengan " << n << endl;
    cout << "========================================================" << endl;
}

int primaAtas(int n) {
    if (n % 2 == 0) {
        n = n + 1;
    } else {
        n = n + 2;
    }
    bool ketemu = false;
    while (!ketemu) {
        bool prima = true;
        if (n % 2 == 0) {
            prima = false;
        } else {
            int i = 3;
            while (prima == true && i <= sqrt(n)) {
                if (n % i == 0) {
                    prima = false;
                }
                i = i + 2;
            }
        }
        if (prima) {
            ketemu = true;
        } else {
            n = n + 2;
        }
    }
    return n;
}

int primaBawah() {
    int n = hdt_boundary;
    if (n % 2 == 0) {
        n = n - 1;
    } else {
        n = n - 2;
    }
    bool ketemu = false;
    while (!ketemu) {
        bool prima = true;
        if (n % 2 == 0) {
            prima = false;
        } else {
            int i = 3;
            while (prima == true && i <= sqrt(n)) {
                if (n % i == 0) {
                    prima = false;
                }
                i = i + 2;
            }
        }
        if (prima) {
            ketemu = true;
        } else {
            n = n - 2;
        }
    }
    return n;
}

void addDoubleHashing(int n) {
    cout << "========================================================" << endl;
    cout << "double hashing....." << endl;
    int hash;
    int hash2 = primaBawah();
    bool inserted = false;
    i = 0;
    while ((!inserted) && (i < hdt_boundary)) {
        hash = ((n % hdt_boundary) + i * ((n % hash2) + 1)) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }
    if (i == 0) {
        cout << "Langsung " << endl;
    }
    cout << "Isi hash [" << hash << "] dengan " << n << endl;
    cout << "========================================================" << endl;
}

void cetak(int n) {
    cout << endl;
    cout << "Output program: " << endl;
    for (int a = 0; a < n; ++a) {
        cout << "Hash [" << a << "] = " << storage[a] << endl;
    }
}

int randomNum(int min, int max) {
    return min + ( rand () % (max - min ) );
}

int main() {
    int n, randomNumber;
    char choice;
    string way;
    srand((unsigned)time(0));
    cout << "Enter data : ";
    cin >> n;
    cout << "Kami Menggunakan Methode Open Addressing Ada 3 Cara , Pilihan Salah Satu Dengan Memilih a,b, atau c : " << endl;
    cout << "a. linear probing " << endl;
    cout << "b. quadric probing " << endl;
    cout << "c. double hashing " << endl;
    cout << "choose : ";
    cin >> choice;
    cout << endl << endl << "Proses Pemasukan data ke hashtable: " << endl;
    hdt_boundary = primaAtas(n);
    for (int a = 0; a < n; ++a) {
        randomNumber = randomNum(0, n);
        switch (choice) {
            case 'a':
                addLinearProbing(randomNumber);
                way = "linear probing ";
                break;
            case 'b':
                addQuadricProbing(randomNumber);
                way = "Quadric Probing";
                break;
            case 'c':
                addDoubleHashing(randomNumber);
                way = "Double Hashing ";
                break;
            default:
                cout << "Invalid choice!" << endl;
                return 1;
        }
    }
    cetak(n);
    cout << "Diatas adalah hasil output hashtable dengan cara \"" << way << "\"" << endl;
    switch (choice) {
        case 'a':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i " << endl;
            break;
        case 'b':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i*i" << endl;
            break;
        case 'c':
            cout << "h1(k) = (k mod " << hdt_boundary << ")" << endl;
            cout << "h2(k) = (h1(K) + i * ( k mod " << primaBawah() << ") + i)" << endl;
            break;
    }
    return 0;
}

