#pragma once
#include <cstdint>

enum class Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,

    // Keep last.
    Count
};

struct Card
{
    Card(int card_rank, Suit card_suit);
    ~Card() = default;

    int rank;
    Suit suit;
};