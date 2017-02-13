//  Constants_GoL.hpp
//  Conway_GoL
//  Collection of constants used across classes

#ifndef Constants_GoL_hpp
#define Constants_GoL_hpp

namespace Constants_GoL {
    
    //size of program window
    const int kWindowWidth = 1600;
    const int kWindowHeight = 1200;
    
    //size of grid drawn inside window
    const int kGridWidth = 1280;
    const int kGridHeight = 880;
    
    //size of each cell (i.e. rectangle shape)
    const int kCellSize = 20;

    //number of cells in the columns and rows
    //by using 'kWindow', actual cell matrix will be > visible grid
    const int kCellsPerCol = kWindowWidth / kCellSize;
    const int kCellsPerRow = kWindowHeight / kCellSize;
    
    //margin space between window and grid boundaries
    const int kGridLeftBound = (kWindowWidth - kGridWidth) / 2;
    const int kGridRightBound = kWindowWidth - kGridLeftBound;
    const int kGridTopBound = (kWindowHeight - kGridHeight) / 2;
    const int kGridBottomBound = kWindowHeight - kGridTopBound;
    
    //index of first cell; used to refer to the first visible cell in the grid
    const int kFirstCellColIndex = kGridLeftBound / kCellSize;
    const int kFirstCellRowIndex = kGridTopBound / kCellSize;
}



#endif /* Constants_GoL_hpp */
