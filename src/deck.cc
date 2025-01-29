#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "deck.hh"

std::string get_suit(Suit suit)
{
    switch (suit)
    {
    case Suit::Clubs:
        return "Clubs";
    case Suit::Diamonds:
        return "Diamonds";
    case Suit::Hearts:
        return "Hearts";
    case Suit::Spades:
        return "Spades";
    }
    return "INVALID SUIT";
}

Card *get_card(Deck &deck, int const rank, Suit const suit)
{
    for (auto &card : deck.cards)
    {
        if (card.rank == rank && card.suit == suit)
        {
            return &card;
        }
    }
    return nullptr;
}

Deck::Deck()
{
    for (int i = 0; i < static_cast<int>(Suit::Count); ++i)
    {
        for (int j = 1; j < 14; ++j)
        {
            Card card{j, static_cast<Suit>(i)};
            cards.push_back(card);
        }
    }
}

void Deck::add(int const rank, Suit const suit)
{
    auto it = std::find_if(
        cards.begin(), cards.end(), [=](Card const &card) {
            return card.rank == rank && card.suit == suit;
        });

    if (it != cards.end())
    {
        std::cout << "Duplicate card (" << rank << " of "
                  << get_suit(suit)
                  << ") already in the deck." << std::endl;
        return;
    }
    cards.push_back(Card{rank, suit});
}

std::optional<Card> Deck::draw()
{
    if (cards.empty())
    {
        std::cout << "No cards to draw" << std::endl;
        return std::nullopt;
    }

    Card top_card = cards.back();
    cards.pop_back();

    return top_card;
}

void Deck::take(int const amount)
{
    if (amount <= 0)
    {
        std::cout << "Must take at least 1 card from deck."
                  << std::endl;
        return;
    }

    if (amount > size())
    {
        std::cout << "Not enough cards to take from deck."
                  << std::endl;
        return;
    }

    std::vector<Card> taken;
    taken.reserve(amount);

    for (int i = 0; i < amount; ++i)
    {
        auto candidate = this->draw();
        if (candidate.has_value())
        {
            taken.push_back(*candidate);
        }
        else
        {
            std::cout
                << "Not enough cards to take from deck."
                << std::endl;
            break;
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::default_random_engine rng{rd()};
    std::shuffle(cards.begin(), cards.end(), rng);
}

int Deck::size() const
{
    return cards.size();
}

void Deck::reveal() const
{
    for (auto const card : cards)
    {
        std::cout << card.rank << " of "
                  << get_suit(card.suit) << std::endl;
    }
}

void Deck::reveal_top() const
{
    if (cards.empty())
    {
        std::cout << "No cards in the deck" << std::endl;
        return;
    }
    Card const &card = cards.back();
    std::cout << "Topmost card is " << card.rank << " of "
              << get_suit(card.suit) << std::endl;
}