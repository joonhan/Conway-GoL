//
//  Button.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/27/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Button.hpp"
#include <ResourcePath.hpp>

//Button class constructor
Button::Button() {}

//Button class overloaded constructor
Button::Button(std::string input, sf::Color color, int xPosition, int yPosition) {
 
    if (!(buttonFont.loadFromFile(resourcePath() + "Menlo.ttc"))) {
        std::cout << "Error: could not load text file" << std::endl;
        return EXIT_FAILURE;
    }
    
    buttonText.setFont(buttonFont);
    buttonText.setString(input);
    buttonText.setPosition(xPosition+5, yPosition);
    buttonText.setFillColor(sf::Color::Black);
    
    sf::FloatRect textRect = buttonText.getLocalBounds();
    sf::String myString = buttonText.getString();
    
    buttonBox.setFillColor(color);
    buttonBox.setOutlineColor(sf::Color::Black);
    buttonBox.setOutlineThickness(1);
    buttonBox.setPosition(xPosition, yPosition);
    buttonBox.setSize(sf::Vector2f(textRect.width+13, 40));
    

}

//get Button boundary values
int Button::getBound(Bound pos) {
    //return left bound
    if (pos == 0) {
        return buttonBox.getPosition().x;
    }
    //return right bound
    else if (pos == 1) {
        return buttonBox.getPosition().x + buttonBox.getLocalBounds().width;
    }
    //return top bound
    else if (pos == 2) {
        return buttonBox.getPosition().y;
    }
    //return bottom bound
    else if (pos == 3) {
        return buttonBox.getPosition().y + buttonBox.getLocalBounds().height;
    }
}
