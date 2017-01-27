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
    
    const int kWindowWidth = 1600;
    const int kWindowHeight = 1200;
    const int kGridWidth = 1280;
    const int kGridHeight = 880;
    const int kCellSize = 40;

    const int kCellsPerCol = kGridWidth / kCellSize;
    const int kCellsPerRow = kGridHeight / kCellSize;
    
    const int kLeftMargin = (kWindowWidth - kGridWidth) / 2;
    const int kRightMargin = kWindowWidth - kLeftMargin;
    const int kTopMargin = (kWindowHeight - kGridHeight) / 2;
    const int kBottomMargin = kWindowHeight - kTopMargin;
    
}



#endif /* Constants_GoL_hpp */
