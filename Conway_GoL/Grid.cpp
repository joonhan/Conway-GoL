//
//  Grid.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Grid.hpp"

using namespace Constants_GoL;

Grid::Grid() {
    
    //set the colors for the line vertices
    line[0].color = sf::Color::Black;
    line[1].color = sf::Color::Black;
    
    //set all the cells in the grid as dead
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++)
            currGenCells[row][col] = Cell(row, col, false);
    }

    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++)
            nextGenCells[row][col] = Cell(row, col, false);
    }
    
   /* currGenCells[9][10].setIsAlive(true);
    currGenCells[10][11].setIsAlive(true);
    currGenCells[11][11].setIsAlive(true);
    currGenCells[11][10].setIsAlive(true);
    currGenCells[11][9].setIsAlive(true);*/
    /*line = {
        sf::Vertex(sf::Vector2f(10,10)),
        sf::Vertex(sf::Vector2f(150,150))
    };*/
    //width = kScreenWidth;
}

//this links mouse cursor position to cell array
void Grid::setCellIsAlive(bool isAlive, int x, int y) {
    
    //if the x position of my cursor is at 160, I want that to be the 0th col index
    //also need to make sure that the cell is being positioned with 160 offset (in Cell.hpp)
    
    //std::cout << "setting cell" << std::endl;
    int row = y / kCellSize;
    //int row = y / kTopMargin;
    //int row = (y - 160) / 40;
    
    int col = x / kCellSize;
    //int col = x / kLeftMargin;
    //int col = (x - 160) / 40;
    
    currGenCells[row][col].setIsAlive(isAlive);
    nextGenCells[row][col].setIsAlive(isAlive); //this allows you to pause game, remove cells and keep them hidden
}

bool Grid::getCellIsAlive(int x, int y) {
    
    int row = y / kCellSize;
    //int row = (y - 160) / 40;
    
    int col = x / kCellSize;
    //int col = x / kLeftMargin*2;
    //int col = (x - 160) / 40;
    
    
    return currGenCells[row][col].getIsAlive();
    
}

void Grid::clearGrid() {
    
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++) {
            currGenCells[row][col].setIsAlive(false);
            nextGenCells[row][col].setIsAlive(false);
        }
    }
}

void Grid::drawGridLines(sf::RenderWindow &window){
    
    /* Code to center the smaller grid inside the larger window */
    
    //calculate horizontal space between the window and grid (1600 - 1280 = 320)
    int horizontalMargin = (kWindowWidth - kGridWidth);
    
    //divide horizontal margin in half (320 / 2 = 160)
    int leftMargin = horizontalMargin / 2;
    int rightMargin = kWindowWidth - leftMargin;
    int topMargin = (kWindowHeight - kGridHeight) / 2;
    int bottomMargin = kWindowHeight - topMargin;
    
    //draw column lines; starting from leftMargin (160) and end at (1440)
    for (int x = leftMargin/kCellSize; x <= rightMargin/kCellSize; x += 1) {
        
        //set the top and bottom vertices of the vertical lines
        line[0].position = sf::Vector2f(kCellSize * x, topMargin);
        line[1].position = sf::Vector2f(kCellSize * x, bottomMargin);
        window.draw(line, 2, sf::Lines);
    }
    
    //draw row lines
    for (int y = topMargin/kCellSize; y <= bottomMargin/kCellSize; y += 1) {
        
        //set the left and right vertices of the horizontal lines
        line[0].position = sf::Vector2f(leftMargin, kCellSize * y);
        line[1].position = sf::Vector2f(rightMargin, kCellSize * y);
        window.draw(line, 2, sf::Lines);
    }
}


void Grid::drawCells(sf::RenderWindow& window){
    //sf::Vertex line[2];
    
    //line[0].color = sf::Color::Black;
    //line[1].color = sf::Color::Black;
    
    //draw cells within the grid boundary
    for (int row = kFirstCellRowIndex; row < kCellsPerRow - kFirstCellRowIndex; row++){
        for (int col = kFirstCellColIndex; col < kCellsPerCol - kFirstCellColIndex; col++) {
            //currGenCells[row][col].draw(window);
            window.draw(currGenCells[row][col].getCellShape());
        }
    }
    
    
    
    
    
    //working
    /*
    for (int row = 4; row < kCellsPerRow-4; row++){
        for (int col = 4; col < kCellsPerCol-4; col++){
            //currGenCells[row][col].draw(window);
            window.draw(currGenCells[row][col].getCellShape());
        }
    }*/
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

void Grid::update(sf::RenderWindow &window) {
    //go through the cell matrix and check the neighbors of each cell
  /*  Cell nextGenCells[30][40];
    for (int row = 0; row < 30; row++) {
        for (int col = 0; col < 40; col++)
            nextGenCells[row][col] = Cell(row, col, false);
    }*/
    
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++) {
            int neighborsAlive = 0;
            //if cell is alive
            if (currGenCells[row][col].getIsAlive() == true) {
               //check neighbors
                
                //set boundaries... if row > 0 then do row-1
                
                if (currGenCells[row-1][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row-1][col].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row-1][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (neighborsAlive < 2) {
                    nextGenCells[row][col].setIsAlive(false);
                }
                else if (neighborsAlive == 2 || neighborsAlive == 3) {
                    nextGenCells[row][col].setIsAlive(true);
                }
                else if (neighborsAlive > 3) {
                    nextGenCells[row][col].setIsAlive(false);
                }
            }
            //if cell is dead
            else {
                //check neighbors
                if (currGenCells[row-1][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row-1][col].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row-1][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col-1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (currGenCells[row+1][col+1].getIsAlive() == true) {
                    neighborsAlive++;
                }
                if (neighborsAlive == 3) {
                    nextGenCells[row][col].setIsAlive(true);
                }
            }
        }
    }
    for (int row = 0; row < kCellsPerRow; row++){
        for (int col = 0; col < kCellsPerCol; col++){
            //currGenCells[row][col].draw(window);
            
            //copy new generation cells to current generation
            currGenCells[row][col] = nextGenCells[row][col];
            
           /* //draw cells only if its within the grid boundaries
            if (row >= kFirstCellRowIndex && row < (kCellsPerRow - kFirstCellRowIndex) &&
                col >= kFirstCellColIndex && col < (kCellsPerCol - kFirstCellColIndex)) {
                window.draw(nextGenCells[row][col].getCellShape());
            }*/
        }
    }
    
    
}//update()
