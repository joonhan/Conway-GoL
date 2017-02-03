//
//  Button.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/27/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Button.hpp"
#include <ResourcePath.hpp>

Button::Button() {
/*
    if (!(buttonFont.loadFromFile(resourcePath() + "Arial.ttf"))) {
        std::cout << "Error: could not load text file" << std::endl;
        return EXIT_FAILURE;
    }
    
    buttonText.setFont(buttonFont);
    text.setString("Clear");
    text.setCharacterSize(50);
    text.setPosition(100, 1000);
    text.setFillColor(sf::Color::Black);
    
    std::string myString = text.getString();
 
    textBox.setFillColor(sf::Color::White);
    textBox.setOutlineColor(sf::Color::Black);
    textBox.setOutlineThickness(2);
    textBox.setSize(sf::Vector2f(50 * myString.length(), 100));
    textBox.setPosition(100, 1000);

     */
    
    
    
    
}


Button::Button(std::string input, sf::Color color, int xPosition, int yPosition) {
 
    if (!(buttonFont.loadFromFile(resourcePath() + "Menlo.ttc"))) {
        std::cout << "Error: could not load text file" << std::endl;
        return EXIT_FAILURE;
    }
    
    buttonText.setFont(buttonFont);
    buttonText.setString(input);
    //buttonText.setCharacterSize(40);
    //buttonText.setOrigin(xPosition/2, yPosition/2);
    buttonText.setPosition(xPosition+5, yPosition);
    buttonText.setFillColor(sf::Color::Black);
    
    //std::cout << buttonText.getScale() << std::endl;
    
    sf::FloatRect textRect = buttonText.getLocalBounds();
    std::cout << textRect.width << std::endl;
    
    sf::String myString = buttonText.getString();
    
    //sf::Color gray(230, 230, 230);
    buttonBox.setFillColor(color);
    //buttonBox.setOrigin(xPosition/2, yPosition/2);
    buttonBox.setOutlineColor(sf::Color::Black);
    buttonBox.setOutlineThickness(1);
    buttonBox.setPosition(xPosition, yPosition);
    buttonBox.setSize(sf::Vector2f(textRect.width+13, 40));
    

}

int Button::getLeftBound() {
    return buttonBox.getPosition().x;
}
int Button::getRightBound() {
    return buttonBox.getPosition().x + buttonBox.getLocalBounds().width;
}
int Button::getTopBound() {
    return buttonBox.getPosition().y;
}
int Button::getBottomBound() {
    return buttonBox.getPosition().y + buttonBox.getLocalBounds().height;
}

