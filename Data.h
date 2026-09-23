#pragma once

#include <ostream>
#include <string>
using namespace std;

class Data {
public:
	Data(int numID, const string& name)
		: numID_(numID), name_(name) {}

	bool operator==(const Data& other) const {
		return numID_ == other.numID_;
	}

	friend ostream& operator<<(ostream& out, const Data& d) {
		return out << d.numID_ << " " << d.name_;
	}

private:
	int numID_;
	string name_;
};