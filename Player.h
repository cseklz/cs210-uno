#pragma once

#include <string>
#include <utility>
#include "Card.h"
#include "StackList.h"

class Player {
public:
    Player(const int id, std::string name) : id_(id), name_(std::move(name)), hand_(new StackList<Card>()) {}

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    void dealCard(Card* card) const {
        hand_->push(card);
    }

    [[nodiscard]] StackList<Card>* getHand() const {
        return hand_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    ~Player() {
        delete hand_;
    }

private:
    int id_;
    std::string name_;
    StackList<Card>* hand_;
};