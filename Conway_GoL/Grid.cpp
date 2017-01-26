//
//  Grid.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Grid.hpp"

Grid::Grid() : gridWidth(800), gridHeight(600) {

    //set the colors for the line vertices
    line[0].color = sf::Color::Black;
    line[1].color = sf::Color::Black;
    
    //set all the cells in the grid as dead
    for (int row = 0; row < 30; row++) {
        for (int col = 0; col < 40; col++)
            cells[row][col] = Cell(row, col, false);
    }
    
    cells[10][10].setIsAlive(true);
    
    /*line = {
        sf::Vertex(sf::Vector2f(10,10)),
        sf::Vertex(sf::Vector2f(150,150))
    };*/
    //width = kScreenWidth;
}

void Grid::setCellIsAlive(bool isAlive, int x, int y) {
    
    std::cout << "setting cell" << std::endl;
    int col = x / 20;
    int row = y / 20;
    
    cells[row][col].setIsAlive(isAlive);
}

bool Grid::getCellIsAlive(int x, int y) {
    
    int row = y/20;
    int col = x/20;
    
    return cells[row][col].getIsAlive(); 
    
}

void Grid::drawGridLines(sf::RenderWindow &window){
    //draw grid lines
    for (int x = 1; x < (gridWidth/20); x+= 1) {
        line[0].position = sf::Vector2f(20*x, 0);
        line[1].position = sf::Vector2f(20*x, gridHeight);
        window.draw(line, 2, sf::Lines);
    }
    for (int y = 1; y < (gridHeight/20); y+= 1) {
        line[0].position = sf::Vector2f(0, 20*y);
        line[1].position = sf::Vector2f(gridWidth, 20*y);
        window.draw(line, 2, sf::Lines);
    }
}


void Grid::drawCells(sf::RenderWindow& window){
    //sf::Vertex line[2];
    
    //line[0].color = sf::Color::Black;
    //line[1].color = sf::Color::Black;
    
    //draw cells
    for (int row = 0; row < 30; row++){
        for (int col = 0; col < 40; col++){
            //cells[row][col].draw(window);
            window.draw(cells[row][col].getCellShape());
        }
    }
    
    
    
    /*sf::VertexArray lines(sf::LinesStrip, 4);
    
    lines[0].position = sf::Vector2f(10, 10);
    lines[0].color = sf::Color::Blue;
    lines[1].position = sf::Vector2f(20, 10);
      lines[1].color = sf::Color::Blue;
    lines[2].position = sf::Vector2f(30, 5);
      lines[2].color = sf::Color::Blue;
    lines[3].position = sf::Vector2f(40, 2);
      lines[3].color = sf::Color::Blue;
    
    window.draw(lines);
     */
    /*window.draw(line, 2, sf::Lines);
    
    line[0].position = sf::Vector2f(40, 0);
    line[1].position = sf::Vector2f(40, 600);
    window.draw(line, 2, sf::Lines);*/
}
