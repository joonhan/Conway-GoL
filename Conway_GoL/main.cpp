//  main.cpp
//  Conway_GoL

#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>
#include "Game.hpp"


int main() {
    
    try {
        Game game;
        game.run();
    }
    
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
    
}
