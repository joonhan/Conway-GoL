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
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    /*
    sf::RenderWindow window;
    window.create(sf::VideoMode(1920,1080), "Game of Life");
    
    while(window.isOpen()){
        sf::Event windowOpen;
        while(window.pollEvent(windowOpen)){
            switch(windowOpen.type){
            
                case(windowOpen.Closed):
                    window.close();
                    break;
                    
                default:
                    break;
                    
            }
        }
    
    
    
    }*/
} //end main()
