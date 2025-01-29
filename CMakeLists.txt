cmake_minimum_required(VERSION 3.10)
project(Deck_of_cards)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(main src/main.cc src/deck.cc src/card.cc)