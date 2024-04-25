#include <iostream>
#include <string>
using namespace std;

class item {
	public:
		string name;
		int price;
	item(string name, int price){
		this->name = name;
		this->price = price;
	}
};

int main() {
	string searchitem;
	item itemlist[5]={
		{"book", 5000},
		{"pencil", 1000},
		{"pen", 2000},
		{"eraser", 500},
		{"ruler", 1500}
	};
	
	
	cout << "Enter the name of the item you want to search for: ";
	getline(cin, searchitem);
	bool found = false;
	
	for (int i = 0; i < 5; i++) {
		if (itemlist[i].name == searchitem) {
			found = true;
			cout << "\nItem " << itemlist[i].name << " found for the IDR " << itemlist[i].price << endl;
			break;
		}
	}
	
	if (!found) {
		cout << "\nSorry, " << searchitem << " item was not found in the list" << endl;
	}
	
	return 0;
}

