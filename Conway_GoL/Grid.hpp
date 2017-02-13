//  Grid.hpp
//  Conway_GoL

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
    Cell currGenCells[kCellsPerRow][kCellsPerCol];  //save current generation of cells
    Cell nextGenCells[kCellsPerRow][kCellsPerCol];  //save next generation of cells
    sf::Vertex line[2];                             //used to draw grid
};



#endif
