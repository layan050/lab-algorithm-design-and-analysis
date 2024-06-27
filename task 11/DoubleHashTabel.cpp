#include <iostream>
using namespace std;

class DoubleHashingHashTable {
    int *hashTable;
    int tableSize;
    int currentSize;

public:
    DoubleHashingHashTable(int size) {
        tableSize = size;
        hashTable = new int[tableSize];
        currentSize = 0;
        for (int i = 0; i < tableSize; i++) {
            hashTable[i] = -1;
        }
    }

    int primaryHash(int key) {
        return key % tableSize;
    }

    int secondaryHash(int key) {
        return 5 - (key % 5);
    }

    void insert(int key) {
        if (currentSize == tableSize) {
            cout << "Hash table is full" << endl;
            return;
        }

        int index = primaryHash(key);
        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            int i = 1;
            while (true) {
                int newIndex = (index + i * secondaryHash(key)) % tableSize;
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }
        currentSize++;
    }

    bool search(int key) {
        int index = primaryHash(key);
        int i = 0;
        while (hashTable[(index + i * secondaryHash(key)) % tableSize] != -1) {
            if (hashTable[(index + i * secondaryHash(key)) % tableSize] == key) {
                return true;
            }
            i++;
            if (i == tableSize) {
                return false;
            }
        }
        return false;
    }

    void displayHashTable() {
        cout << "Hash Table Content:\n";
        for (int i = 0; i < tableSize; i++) {
            if (hashTable[i] == -1) {
                cout << i << " --> empty\n";
            } else {
                cout << i << " --> " << hashTable[i] << endl;
            }
        }
    }
};

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    DoubleHashingHashTable hashTable(tableSize);

    int numElements;
    cout << "Enter the number of elements to be inserted: ";
    cin >> numElements;

    int elements[numElements];
    cout << "Enter " << numElements << " elements:" << endl;
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    for (int i = 0; i < numElements; i++) {
        hashTable.insert(elements[i]);
    }

    hashTable.displayHashTable();

    int keyToSearch;
    cout << "\nEnter the element you want to search in the hash table: ";
    cin >> keyToSearch;

    if (hashTable.search(keyToSearch)) {
        cout << keyToSearch << " found in the hash table.\n";
    } else {
        cout << keyToSearch << " not found in the hash table.\n";
    }

    return 0;
}

