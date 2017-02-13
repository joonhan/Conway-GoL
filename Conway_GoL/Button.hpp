//  Button.hpp
//  Conway_GoL

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


class Button {
    
public:
    enum Bound {left, right, top, bottom};
    
    Button();
    Button(std::string text, sf::Color color, int xPosition, int yPosition);
    sf::Text& getText() { return buttonText; };
    sf::RectangleShape& getShape() { return buttonBox; };
    int getBound(Bound position);
    
private:
    sf::Font buttonFont;
    sf::Text buttonText;
    sf::RectangleShape buttonBox;
    
};


#endif
