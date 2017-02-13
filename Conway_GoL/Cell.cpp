//  Cell.cpp
//  Conway_GoL


#include "Cell.hpp"


//Cell class default constructor
Cell::Cell() {
    isAlive = false;
    cellShape = sf::RectangleShape(sf::Vector2f(kCellSize, kCellSize));
}

//Cell class overloaded constructor
Cell::Cell(bool isLiving, int rowIndex, int colIndex) {
    
    //assign rectangle size
    cellShape = sf::RectangleShape(sf::Vector2f(kCellSize, kCellSize));
    
    //set starting position of cell
    cellShape.setPosition(colIndex * kCellSize, rowIndex * kCellSize);
    
    isAlive = isLiving;
    
    //set cell color depending on its status
    if (isAlive == true) {
        cellShape.setFillColor(sf::Color::Green);
    }
    else {
        cellShape.setFillColor(sf::Color::White);
    }
}

//set cell's status
void Cell::setIsAlive(bool isLiving) {
    
    isAlive = isLiving;
    
    if (isAlive == true) {
        cellShape.setFillColor(sf::Color::Green);
    } else {
        cellShape.setFillColor(sf::Color::White);
    }
}
