//
//  Game.hpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Constants_GoL.hpp"
#include "Grid.hpp"
#include "Cell.hpp"
#include "Button.hpp"

class Button; 

//class Grid;
using namespace Constants_GoL; 

class Game {
    
public:
    Game();
    //void setup();
    void run();
    //void drawButtons();
    void drawBlinker();
    void drawGlider();
    void drawGoblinGun(); 

private:
    sf::RenderWindow window;
    sf::Event event;
    Grid grid;
    bool isGameRunning;
    //Button& button;
    //sf::Texture background;
};



#endif /* Game_hpp */
