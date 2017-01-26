//
//  Grid.hpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cell.hpp"
//#include "Game.hpp"


//class Game;

class Grid {
    
public:
    Grid();
    void setCellIsAlive(bool isAlive, int x, int y);
    bool getCellIsAlive(int x, int y);
    void drawGridLines(sf::RenderWindow& window);
    void drawCells(sf::RenderWindow& window);
    
private:
    int gridWidth;
    int gridHeight;
    Cell cells[30][40];
    sf::Vertex line[2];
    
    /*sf::Vertex line[2] = {
        sf::Vertex(sf::Vector2f(20, 0), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(20, 600), sf::Color::Blue),
    };*/
};



#endif /* Grid_hpp */
