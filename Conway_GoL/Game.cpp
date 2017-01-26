//
//  Game.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Game.hpp"
#include "ResourcePath.hpp"

//const unsigned int kScreenWidth = 800;
//const unsigned int kScreenHeight = 600;

Game::Game() : window(sf::VideoMode(kScreenWidth, kScreenHeight), "Game of Life") {
    

}

/*void Game::setup() {

    if (!(background.loadFromFile(resourcePath() + "white_800x600.png"))) {
        std::cout << "Error: could not load image" << std::endl;
        return EXIT_FAILURE;
    }
}*/
/*void Game::drawGrid() {
    grid.drawGrid(window);
    grid.draw(window);
    grid.drawGrid(window);
}*/

void Game::run() {
    
    sf::Texture background;
    if (!(background.loadFromFile(resourcePath() + "white_800x600.png"))) {
        std::cout << "Error: could not load image" << std::endl;
        return EXIT_FAILURE;
    }
    
    sf::Sprite start_menu(background);
    
    sf::Font font;
    if (!(font.loadFromFile(resourcePath() + "Arial.ttf"))) {
        std::cout << "Error: could not load text file" << std::endl;
            return EXIT_FAILURE;
    }
    
    //sf::Text text("Welcome to the Game of Life", font, 50);
    sf::Text text;
    text.setFont(font);
    text.setString("Welcome to the Game of Life");
    text.setCharacterSize(kScreenWidth/20);
    text.setFillColor(sf::Color::Black);

    //retrieve the dimensions of the text box
    sf::FloatRect textRect = text.getLocalBounds();
    
    //set the origin of the text box (aka its center of gravity)
    text.setOrigin(textRect.width/2, 0);
    
    //using the origin, set it on the screen
    text.setPosition(kScreenWidth/2.0f,0);
    
/*    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(10,10), sf::Color::Red),
        sf::Vertex(sf::Vector2f(150,150), sf::Color::Red)
    };
  */  
    while (window.isOpen()) {
        
        while (window.pollEvent(event)) {
            
            //switch(event.type) {
                //case(sf::Event::Closed):
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "button pressed" << std::endl;
                
                sf::Vector2i position = sf::Mouse::getPosition(window);
                
                if (grid.getCellIsAlive(position.x, position.y) == false){
                    grid.setCellIsAlive(true, position.x, position.y);
                    
                } else {
                    grid.setCellIsAlive(false, position.x, position.y);
                }
                
                std::cout << position.x << std::endl;
                std::cout << position.y << std::endl;
            }
        }
        
        window.clear();
        window.draw(start_menu);
        //drawGrid();
        grid.drawGridLines(window);
        grid.drawCells(window);
        grid.drawGridLines(window);
        //window.draw(line, 2, sf::Lines);
        window.draw(text);
        window.display();
        
    }
    
} //end run()

