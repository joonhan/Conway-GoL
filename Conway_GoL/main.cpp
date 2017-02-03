//
//  main.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

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
    
} //end main()
