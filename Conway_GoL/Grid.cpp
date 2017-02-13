//  Grid.cpp
//  Conway_GoL

#include "Grid.hpp"

using namespace Constants_GoL;

//default constructor for Grid class
Grid::Grid() {
    
    //set colors for the 2 vertices used to create a line
    line[0].color = sf::Color::Black;
    line[1].color = sf::Color::Black;
    
    //initialize cell matrix with dead cells
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++)
            currGenCells[row][col] = Cell(false, row, col);
    }
    //same for the next generation matrix
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++)
            nextGenCells[row][col] = Cell(false, row, col);
    }
    
}

//maps the mouse cursor position to cell array
//parameters xPos and yPos refer to the mouse cursor position on screen
void Grid::setCellIsAlive(bool isAlive, int xPos, int yPos) {
    
    //calculate the matrix indices of the cell pointed to on screen
    //if xPos of mouse is at 160 and each cell is of size 40, that refers to 4th
    //cell array element
    int row = yPos / kCellSize;
    int col = xPos / kCellSize;
    
    //set cell as alive or dead
    currGenCells[row][col].setIsAlive(isAlive);
    
    //nextGenCells[row][col].setIsAlive(isAlive);
}

//returns cell's status
bool Grid::getCellIsAlive(int x, int y) {
    
    //calculate index of cell being pointed to on screen then return its status
    int row = y / kCellSize;
    int col = x / kCellSize;
    
    return currGenCells[row][col].getIsAlive();
    
}

//set all cells as dead
void Grid::clearGrid() {
    
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++) {
            currGenCells[row][col].setIsAlive(false);
            nextGenCells[row][col].setIsAlive(false);
        }
    }
}

//draw lines that represent the grid
void Grid::drawGridLines(sf::RenderWindow &window){
 
    //draw column lines
    for (int x = kGridLeftBound/kCellSize; x <= kGridRightBound/kCellSize; x += 1) {
        
        //set the top and bottom vertices of the vertical lines then draw line
        line[0].position = sf::Vector2f(kCellSize * x, kGridTopBound);
        line[1].position = sf::Vector2f(kCellSize * x, kGridBottomBound);
        window.draw(line, 2, sf::Lines);
    }
    
    //draw row lines
    for (int y = kGridTopBound/kCellSize; y <= kGridBottomBound/kCellSize; y += 1) {
        
        //set the left and right vertices of the horizontal lines then draw line
        line[0].position = sf::Vector2f(kGridLeftBound, kCellSize * y);
        line[1].position = sf::Vector2f(kGridRightBound, kCellSize * y);
        window.draw(line, 2, sf::Lines);
    }
}

//draw all the cells in the matrix
void Grid::drawCells(sf::RenderWindow& window){
    
    //draw cells within the visible grid boundary
    for (int row = kFirstCellRowIndex; row < kCellsPerRow - kFirstCellRowIndex; row++){
        for (int col = kFirstCellColIndex; col < kCellsPerCol - kFirstCellColIndex; col++) {
            window.draw(currGenCells[row][col].getCellShape());
        }
    }
}

//runs logic rules - each cell checks its neighbors and saves result to separate matrix
void Grid::update(sf::RenderWindow &window) {
    
    //traverse the cell matrix and check each cell's # of neighbors
    for (int row = 0; row < kCellsPerRow; row++) {
        for (int col = 0; col < kCellsPerCol; col++) {

            //counter to keep track # neighbors that are alive; resets per loop
            int neighborsAlive = 0;

            //set boundaries... if row > 0 then do row-1
            //if(row > 0 && col > 0) {
            
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
                
            //living cell
            if (currGenCells[row][col].getIsAlive() == true) {
                
                //if < 2 or > 3 neighbors are alive, cell dies
                if (neighborsAlive < 2 || neighborsAlive > 3) {
                    nextGenCells[row][col].setIsAlive(false);
                }
                //if cell has 2 or 3 neighbors, cell keeps living
                else if (neighborsAlive == 2 || neighborsAlive == 3) {
                    nextGenCells[row][col].setIsAlive(true);
                }
            }
            //dead cell
            else {
                //if cell has 3 neighbors, it comes back alive
                if (neighborsAlive == 3) {
                    nextGenCells[row][col].setIsAlive(true);
                }
            }
        }
    }
    //copy the changes to the next gen matrix
    for (int row = 0; row < kCellsPerRow; row++){
        for (int col = 0; col < kCellsPerCol; col++){
            currGenCells[row][col] = nextGenCells[row][col];
        }
    }
    
}//update()
