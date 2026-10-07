#pragma once

#include <string>
#include <utility>

class Card {
public:
    Card(std::string color, std::string rank)
        : color_(std::move(color)), rank_(std::move(rank)) {}

    bool operator==(const Card &c) const {
        return color_ == c.color_ && rank_ == c.rank_;
    }

    friend std::ostream &operator<<(std::ostream &out, const Card &c) {
        return out << c.color_ << c.rank_;
    }

private:
    std::string color_;
    std::string rank_;
};
