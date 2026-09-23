#import <iostream>
#import <ostream>
using namespace std;

class Data {
public:
	int numID;
	std::string name;

	Data(int numID, string name) {
		this->numID = numID;
		this->name = name;
	}

	void print() {
		cout << numID << " " << name << endl;
	}
};