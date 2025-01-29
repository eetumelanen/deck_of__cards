#include <iostream>
#include <stdexcept>
#include "card.hh"

Card::Card(int const card_rank, Suit const card_suit)
    : rank(card_rank)
    , suit(card_suit)
{
    try
    {
        if (rank > 13 || rank < 1)
        {
            throw std::runtime_error(
                "Illegal card initialization!");
        }
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}