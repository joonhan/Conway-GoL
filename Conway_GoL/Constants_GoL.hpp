//
//  Constants_GoL.hpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/26/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#ifndef Constants_GoL_hpp
#define Constants_GoL_hpp

namespace Constants_GoL {
    
    //size of window
    const int kWindowWidth = 1600;
    const int kWindowHeight = 1200;
    
    //size of grid drawn inside window
    const int kGridWidth = 1280;
    const int kGridHeight = 880;
    
    //size of each cell (i.e. rectangle shape)
    const int kCellSize = 20;

    //number of cells in the columns and rows
    //using kWindow instead of kGrid means actual cell matrix is > visible grid
    const int kCellsPerCol = kWindowWidth / kCellSize;
    const int kCellsPerRow = kWindowHeight / kCellSize;
    
    //margin space between window and grid boundaries
    const int kLeftMargin = (kWindowWidth - kGridWidth) / 2;
    const int kRightMargin = kWindowWidth - kLeftMargin;
    const int kTopMargin = (kWindowHeight - kGridHeight) / 2;
    const int kBottomMargin = kWindowHeight - kTopMargin;
    
    //index of first cell; used to refer to the first visible cell in the matrix
    const int kFirstCellColIndex = kLeftMargin / kCellSize;
    const int kFirstCellRowIndex = kTopMargin / kCellSize;
}



#endif /* Constants_GoL_hpp */
