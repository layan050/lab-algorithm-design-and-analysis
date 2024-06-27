#include <iostream>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

void insert(int hashTable[], int tableSize, int key) {
    int index = hashFunction(key, tableSize);
    while (hashTable[index] != -1) {
        index = (index + 1) % tableSize;
    }
    hashTable[index] = key;
}

bool search(int hashTable[], int tableSize, int key) {
    int index = hashFunction(key, tableSize);
    int start = index;
    while (hashTable[index] != key) {
        index = (index + 1) % tableSize;
        if (index == start || hashTable[index] == -1) {
            return false;
        }
    }
    return true;
}

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;  // Initialize hash table with -1 indicating empty slots
    }

    int numElements;
    cout << "Enter the number of elements to be inserted: ";
    cin >> numElements;

    int elements[numElements];
    cout << "Enter " << numElements << " elements:" << endl;
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    for (int i = 0; i < numElements; i++) {
        insert(hashTable, tableSize, elements[i]);
    }

    // Print the hash table
    cout << "Hash Table Content:\n";
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] == -1) {
            cout << i << " --> empty\n";
        } else {
            cout << i << " --> " << hashTable[i] << endl;
        }
    }

    int keyToSearch;
    cout << "\nEnter the element you want to search in the hash table: ";
    cin >> keyToSearch;

    if (search(hashTable, tableSize, keyToSearch)) {
        cout << keyToSearch << " found in the hash table.\n";
    } else {
        cout << keyToSearch << " not found in the hash table.\n";
    }

    return 0;
}

