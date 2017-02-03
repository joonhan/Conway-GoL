//
//  Button.hpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/27/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


class Button {
    
public:
    Button();
    Button(std::string text, sf::Color color, int xPosition, int yPosition);
    
    sf::Text& getText() { return buttonText; };
    sf::RectangleShape& getShape() { return buttonBox; };
    int getLeftBound();
    int getRightBound();
    int getTopBound();
    int getBottomBound(); 
    
private:
    sf::Font buttonFont;
    sf::Text buttonText;
    sf::RectangleShape buttonBox;
    
};


#endif /* Button_hpp */
