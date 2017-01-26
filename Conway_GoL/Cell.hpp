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

class Cell {

public:
    Cell();
    Cell(int xPosition, int yPosition, bool isLiving);
    bool getIsAlive() { return isAlive; };
    void setIsAlive(bool isLiving);
    
    
    sf::RectangleShape& getCellShape() { return cellShape; };
    
private:
    int cellWidth;
    int cellHeight;
    bool isAlive;
    sf::RectangleShape cellShape;
    
    
};
#endif /* Cell_hpp */
