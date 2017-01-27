//
//  Cell.hpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants_GoL.hpp"

using namespace Constants_GoL;

class Cell {

public:
    Cell();
    Cell(int rowIndex, int colIndex, bool isLiving);
    bool getIsAlive() { return isAlive; };
    void setIsAlive(bool isLiving);
    
    
    sf::RectangleShape& getCellShape() { return cellShape; };
    
private:
    //int cellWidth;
    //int cellHeight;
    bool isAlive;
    sf::RectangleShape cellShape;
    
    
};
#endif /* Cell_hpp */
