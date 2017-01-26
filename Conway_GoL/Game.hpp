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


//const unsigned int kScreenWidth = 800;
//const unsigned int kScreenHeight = 600;
//class Grid;

class Game {
    
public:
    Game();
    //void setup();
    void run();
    //void draw();
    void drawBlinker(int x, int y);
    void drawBeacon(int x, int y);
    void drawGlider(int x, int y);
    
    const unsigned int kScreenWidth = 800;
    const unsigned int kScreenHeight = 600;
    
    
private:
    sf::RenderWindow window;
    sf::Event event;
    Grid grid;
    //sf::Texture background;
};



#endif /* Game_hpp */
