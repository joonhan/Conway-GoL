//
//  Cell.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell() {
    //isAlive = false;
    //cellShape = sf::RectangleShape(sf::Vector2f(cellWidth, cellHeight));
}


Cell::Cell(int rowIndex, int colIndex, bool isLiving) {
    
    cellShape = sf::RectangleShape(sf::Vector2f(kCellSize, kCellSize));
    
    cellShape.setPosition(colIndex * kCellSize, rowIndex * kCellSize);

    isAlive = isLiving;
    
    if (isAlive == true) {
        cellShape.setFillColor(sf::Color::Green);
    }
    else {
        cellShape.setFillColor(sf::Color::White);
    }
    
}


void Cell::setIsAlive(bool isLiving) {
    
    isAlive = isLiving;
    
    if (isAlive == true) {
        cellShape.setFillColor(sf::Color::Green);
    } else {
        cellShape.setFillColor(sf::Color::White);
    }
    
}
