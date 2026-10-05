#pragma once

#include <ostream>
#include <string>
#include <utility>

class Player {
public:
    Player(int id, std::string  name) : id_(id), name_(std::move(name)) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    std::string name_;
};