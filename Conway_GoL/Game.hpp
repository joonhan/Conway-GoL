//  Game.hpp
//  Conway_GoL


#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Constants_GoL.hpp"
#include "Grid.hpp"
#include "Cell.hpp"
#include "Button.hpp"

//class Button;
using namespace Constants_GoL;


class Game {
    
public:
    Game();
    void run();
    void drawButton(Button& btn);
    void drawBlinker();
    void drawGlider();
    void drawGoblinGun(); 

private:
    sf::RenderWindow window;
    sf::Event event;
    Grid grid;
    bool isGameRunning;
};



#endif
