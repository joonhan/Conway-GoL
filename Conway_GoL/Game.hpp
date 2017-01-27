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
#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "Cell.hpp"
#include "Constants_GoL.hpp"

//class Grid;
using namespace Constants_GoL; 

class Game {
    
public:
    Game();
    //void setup();
    void run();
    //void draw();
    //void drawBlinker(int x, int y);
    //void drawBeacon(int x, int y);
    //void drawGlider(int x, int y);

private:
    sf::RenderWindow window;
    sf::Event event;
    Grid grid;
    bool isGameRunning;
    //sf::Texture background;
};



#endif /* Game_hpp */
