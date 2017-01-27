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
#include "Constants_GoL.hpp"
#include "Cell.hpp"

using namespace Constants_GoL;

class Grid {
    
public:
    Grid();
    void setCellIsAlive(bool isAlive, int x, int y);
    bool getCellIsAlive(int x, int y);
    void clearGrid(); 
    void drawGridLines(sf::RenderWindow& window);
    void drawCells(sf::RenderWindow& window);
    void update(sf::RenderWindow& window); 
    
private:
    //int gridWidth;
    //int gridHeight;
    
    //the ACTUAL cell matrix is larger than the visible grid. So we can click
    //outside the grid lines
    
    Cell currGenCells[kCellsPerRow][kCellsPerCol];
    //Cell currGenCells[Constants_GoL::kCellsPerRow][Constants_GoL::kCellsPerRow];
    Cell nextGenCells[kCellsPerRow][kCellsPerCol];
    //Cell nextGenCells[Constants_GoL::kCellsPerRow][Constants_GoL::kCellsPerCol];
    
    sf::Vertex line[2];
    
    /*sf::Vertex line[2] = {
        sf::Vertex(sf::Vector2f(20, 0), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(20, 600), sf::Color::Blue),
    };*/
};



#endif /* Grid_hpp */
