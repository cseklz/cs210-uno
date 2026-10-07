#pragma once

#include <ostream>
#include <string>

class Card {
public:
    Card(const std::string& color, const std::string& rank)
        : color_(color), rank_(rank) {}

    bool operator==(const Card& c) const {
        return color_ == c.color_ && rank_ == c.rank_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
        return out << c.color_ << c.rank_;
    }

private:
    std::string color_;
    std::string rank_;
};