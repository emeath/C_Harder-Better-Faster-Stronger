#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> products = {"mouse", "keyboard", "monitor", "headset", "switch", "hub", "ethernet cable"};

	cout << "Elements of products: " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~ " << endl;
	for(vector<string>::iterator ite = products.begin(); ite != products.end(); ite++) {
                cout << "index [" << ite - products.begin() << "] -- value: " << *ite << endl;
        }
	cout << ".................... " << endl;

	vector<string>::iterator it;

	// address of first element of collection (products)
	it = products.begin();
	
	cout << "Acessing element (first) of collection (products): " << endl;
	cout << *it << endl;

	cout << "Acessing vector by index: " << endl;
	cout << products[0] << endl;
	
	// .end() returns simillar to array.size() or array.lenght() 
	it = products.end() - 1;
	cout << "Last element of products by iterator: " << endl;
	cout << *it << endl;	

	// navigate into iterator:
	// go to begin
	it = products.begin();
	// go to index 2
	advance(it, 2);
	cout << "Go to index 2 - iterator: " << endl;	
	cout << *it << endl;

	// next element based on current position
	cout << "Now im on index 3 - iterator: " << endl; 
	cout << *next(it, 1) << endl;

	// go to the 3rd previous element
	cout << "Now im on index 0 - iterator: " << endl;
	cout << *prev(it, 2) << endl;
}

