#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "card.hh"
#include "deck.hh"

int main()
{
    Deck deck{};

    while (true)
    {
        int action = 0;
        int rank = 0;
        int suit = 0;
        int amount = 0;

        std::cout << "Select action" << std::endl;
        std::cout << "0: Add card" << std::endl;
        std::cout << "1: Draw a card" << std::endl;
        std::cout << "2: Take x many cards" << std::endl;
        std::cout << "3: Shuffle deck" << std::endl;
        std::cout << "4: Print amount of cards"
                  << std::endl;
        std::cout << "5: Reveal cards" << std::endl;
        std::cout << "6: Reveal topmost card" << std::endl;

        std::cin >> action;

        switch (action)
        {
        case 0:
            std::cout << "Input card to be added"
                      << std::endl;
            std::cout << "Ranks 1-13, suit 0-3 (Clubs, "
                         "Diamonds, Hearts, Spades)"
                      << std::endl;
            std::cin >> rank >> suit;
            if (rank < 1 || rank > 13 || suit < 0 ||
                suit >= static_cast<int>(Suit::Count))
            {
                std::cerr
                    << "Invalid rank or suit input.\n";
                continue;
            }
            deck.add(rank, static_cast<Suit>(suit));
            break;
        case 1:
            deck.draw();
            break;
        case 2:
            std::cout << "Input amount of cards to draw: ";
            std::cin >> amount;
            deck.take(amount);
            break;
        case 3:
            deck.shuffle();
            break;
        case 4:
            std::cout << deck.size()
                      << " cards in the deck." << std::endl;
            break;
        case 5:
            deck.reveal();
            break;
        case 6:
            deck.reveal_top();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    system("pause");
    return 0;
}