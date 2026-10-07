#pragma once

#include <ostream>
#include <string>
#include <utility>

class Data {
public:
    Data(const int numID, std::string name)
        : numID_(numID), name_(std::move(name)) {}

    bool operator==(const Data &other) const {
        return numID_ == other.numID_;
    }

    friend std::ostream &operator<<(std::ostream &out, const Data &d) {
        return out << d.numID_ << " " << d.name_;
    }

private:
    int numID_;
    std::string name_;
};