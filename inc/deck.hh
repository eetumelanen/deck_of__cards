#pragma once

#include <vector>
#include <optional>
#include "card.hh"

class Deck {
    public:
    Deck();

    void add(int rank, Suit suit);
    std::optional<Card> draw();
    void take(int amount);
    void shuffle();
    int size() const;
    void reveal() const;
    void reveal_top() const;

    std::vector<Card> cards;
};