#pragma once

#import <string>

class Card {
public:
    Card(std::string& color, std::string& rank)
        : color_(std::move(color)), rank_(std::move(rank)) {}

    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
        return out << c.color_ << c.rank_;
    }
};