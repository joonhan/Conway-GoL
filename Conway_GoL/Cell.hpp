//  Cell.hpp
//  Conway_GoL


#ifndef Cell_hpp
#define Cell_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants_GoL.hpp"

using namespace Constants_GoL;

class Cell {

public:
    Cell();
    Cell(bool isLiving, int rowIndex, int colIndex);
    bool getIsAlive() { return isAlive; };
    void setIsAlive(bool isLiving);
    sf::RectangleShape& getCellShape() { return cellShape; };
    
private:
    bool isAlive;
    sf::RectangleShape cellShape;
    
    
};
#endif
