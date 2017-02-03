//
//  Game.cpp
//  Conway_GoL
//
//  Created by Joonsoo Han on 1/14/17.
//  Copyright © 2017 Joonsoo Han. All rights reserved.
//

#include "Game.hpp"
#include "ResourcePath.hpp"

using namespace Constants_GoL;

//Game::Game() : window(sf::VideoMode(kScreenWidth, kScreenHeight), "Game of Life")

Game::Game() {
    
    window.create(sf::VideoMode(kWindowWidth, kWindowHeight), "Game of Life");
    
    isGameRunning = false;
    
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

//we could draw the blinker at a specified location using mouse cursor
//void drawBlinker(int xPosition, int yPosition) {

void Game::drawBlinker() {
    //this scales the cells according to the cellSize
    grid.setCellIsAlive(true, kCellsPerCol/2*kCellSize, kCellsPerRow/2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2*kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2*kCellSize, kCellsPerRow/2*kCellSize + 2*kCellSize);
    
}

void Game::drawGlider() {
    
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize + kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize-kCellSize, kCellsPerRow/2*kCellSize + 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize + kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    }

void Game::drawGoblinGun() {
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    
    //left to right - second object
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 10*kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 10*kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 10*kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 11*kCellSize, kCellsPerRow/2 * kCellSize - kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 11*kCellSize, kCellsPerRow/2 * kCellSize + 3*kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 12*kCellSize, kCellsPerRow/2 * kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 12*kCellSize, kCellsPerRow/2 * kCellSize + 4*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 13*kCellSize, kCellsPerRow/2 * kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 13*kCellSize, kCellsPerRow/2 * kCellSize + 4*kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 14*kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 15*kCellSize, kCellsPerRow/2 * kCellSize - kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 15*kCellSize, kCellsPerRow/2 * kCellSize + 3*kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 16*kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 16*kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 16*kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 17*kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 20*kCellSize, kCellsPerRow/2 * kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 20*kCellSize, kCellsPerRow/2 * kCellSize - kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 20*kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 21*kCellSize, kCellsPerRow/2 * kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 21*kCellSize, kCellsPerRow/2 * kCellSize - kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 21*kCellSize, kCellsPerRow/2 * kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 22*kCellSize, kCellsPerRow/2 * kCellSize - 3*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 22*kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 24*kCellSize, kCellsPerRow/2 * kCellSize - 4*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 24*kCellSize, kCellsPerRow/2 * kCellSize - 3*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 24*kCellSize, kCellsPerRow/2 * kCellSize + 1*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 24*kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 34*kCellSize, kCellsPerRow/2*kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 35*kCellSize, kCellsPerRow/2*kCellSize - 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 34*kCellSize, kCellsPerRow/2*kCellSize - kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + 35*kCellSize, kCellsPerRow/2*kCellSize - kCellSize);
}




void Game::run() {
    
    sf::Texture background;
    if (!(background.loadFromFile(resourcePath() + "white_1600x1200.jpg"))) {
        std::cout << "Error: could not load image" << std::endl;
        return EXIT_FAILURE;
    }
    
    sf::Sprite start_menu(background);
    window.setFramerateLimit(30);
    
    
    sf::Color gray(210, 210, 210);
    Button blinkerButton ("Blinker", gray, 160, 1060);
    Button gliderButton ("Glider", gray, 330, 1060);
    Button goblinGunButton ("GoblinGun", gray, 480, 1060);
    Button clearButton("CLEAR", gray, 1100, 1060);
    Button startButton("START", gray, 1260, 1060);
    Button stopButton("STOP", gray, 1260, 1060);
    Button speedUpButton("SPEED +", gray, 700, 1060);
    Button speedDownButton("SPEED -", gray, 850, 1060);
    //"Clear", sf::Color::Black, 10, 700);
    

    sf::Font font;
    if (!(font.loadFromFile(resourcePath() + "Arial.ttf"))) {
        std::cout << "Error: could not load text file" << std::endl;
            return EXIT_FAILURE;
    }
    
    
    int genNum = 0;
    sf::Text genCounter("generation: " + std::to_string(genNum), font, 40);
    //genCounter.setFont(font);
    //genCounter.setString();
    //genCounter.setCharacterSize(100);
    genCounter.setFillColor(sf::Color::Black);
    genCounter.setPosition(5, 0);
  
    
    /*
    sf::Text text("Welcome to the Game of Life", font, 50);
    sf::Text textClear;
    textClear.setFont(font);
    textClear.setString("Clear");
    textClear.setCharacterSize(100);
    textClear.setFillColor(sf::Color::Black);
    
    //retrieve the dimensions of the text box
    sf::FloatRect textRect = textClear.getLocalBounds();
    //set the origin of the text box (aka its center of gravity)
    text.setOrigin(textRect.width/2, 0);
    //using the origin, set it on the screen
    text.setPosition(1600/2.0f, 0);
    
    sf::RectangleShape button;
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);
    button.setSize(sf::Vector2f(100, 100));
    button.setPosition(10, 600);
    */
    
    
    
/*    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(10,10), sf::Color::Red),
        sf::Vertex(sf::Vector2f(150,150), sf::Color::Red)
    };
 
 
 */
    time_t start;
    time_t end;
    bool resetTimer = true;
    sf::Clock clock;
    sf::Time t1 = sf::milliseconds(1000);
    int count = 0;
    
    sf::Text delayCounter("delay: " + std::to_string(t1.asMilliseconds()) + "ms", font, 40);
    delayCounter.setFillColor(sf::Color::Black);
    delayCounter.setPosition(5, 40);
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            //switch(event.type) {
                //case(sf::Event::Closed):
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //sf::Vector2i position = sf::Mouse::getPosition(window);
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                /*
                if (position.x > startButton.getLeftBound() && position.x < startButton.getRightBound() && position.y > startButton.getTopBound() && position.y < startButton.getBottomBound() && isGameRunning == true) {
                    
                    isGameRunning = false;
                    count++;
                    std::cout << "count is " << count << std::endl;
                }*/
                
                
                if (position.x > startButton.getLeftBound() && position.x < startButton.getRightBound() && position.y > startButton.getTopBound() && position.y < startButton.getBottomBound()) {
                    std::cout << " start button pressed " << std::endl;
                    
                    if (isGameRunning == true) {
                        isGameRunning = false;
                    } else {
                        isGameRunning = true;
                    }
                    count++;
                    std::cout << "count is " << count << std::endl;

                    //isGameRunning = !isGameRunning;
                }
                
                
                if (!isGameRunning) {
                    std::cout << "mouse button pressed" << std::endl;
                    //sf::Vector2i position = sf::Mouse::getPosition(window);
              
                //check that mouse press is within grid boundaries
               /*if (position.x > kLeftMargin && position.x < kRightMargin &&
                    position.y > kTopMargin && position.y < kBottomMargin) {
                */
                    if (grid.getCellIsAlive(position.x, position.y) == false) {
                        grid.setCellIsAlive(true, position.x, position.y);
                    } else {
                        grid.setCellIsAlive(false, position.x, position.y);
                    }
                    //std::cout << position.x << std::endl;
                    //std::cout << position.y << std::endl;
                //}
                    if (position.x > 1100 && position.x < 1200 && position.y > 1060 && position.y < 1100) {
                    std::cout << "hit clear box!" << std::endl;
                    grid.clearGrid();
                        genNum = 0;
                        genCounter.setString("generation: " + std::to_string(genNum));
                        //window.draw(genCounter);
                    }
                }
                
                if (position.x > blinkerButton.getLeftBound() && position.x < blinkerButton.getRightBound() && position.y > blinkerButton.getTopBound() && position.y < blinkerButton.getBottomBound()) {
                    grid.clearGrid();
                    genNum = 0;
                    drawBlinker();
                }
                if (position.x > gliderButton.getLeftBound() && position.x < gliderButton.getRightBound() && position.y > gliderButton.getTopBound() && position.y < gliderButton.getBottomBound()) {
                    grid.clearGrid();
                    genNum = 0;
                    drawGlider();
                }
                if (position.x > goblinGunButton.getLeftBound() && position.x < goblinGunButton.getRightBound() && position.y > goblinGunButton.getTopBound() && position.y < goblinGunButton.getBottomBound()) {
                    
                    grid.clearGrid();
                    genNum = 0;
                    drawGoblinGun();
                }
                if (position.x > speedUpButton.getLeftBound() && position.x < speedUpButton.getRightBound() && position.y > speedUpButton.getTopBound() && position.y < speedUpButton.getBottomBound()) {
                    
                    if (t1.asMilliseconds() > 0) {
                        t1 -= sf::milliseconds(50);
                    }
                    delayCounter.setString("delay: " + std::to_string(t1.asMilliseconds())+"ms");
                }
                if (position.x > speedDownButton.getLeftBound() && position.x < speedDownButton.getRightBound() && position.y > speedDownButton.getTopBound() && position.y < speedDownButton.getBottomBound()) {
                    
                    if (t1.asMilliseconds() < 1000) {
                        t1 += sf::milliseconds(50);
                    }
                    delayCounter.setString("delay: " + std::to_string(t1.asMilliseconds())+"ms");
                }
                
            } //mouse pressed
    
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "space pressed" << std::endl;
                    isGameRunning = !isGameRunning;
                }
            }
            
        }
        window.clear();
        window.draw(start_menu);
        grid.drawGridLines(window);
        grid.drawCells(window);
        
        
        //sf::Clock clock;
        //sf::Time elapsed = clock.getElapsedTime();
        sf::Time elapsed = clock.getElapsedTime();
        std::cout << elapsed.asMilliseconds() << std::endl;
        //clock.restart();
        
        /*
        if (resetTimer == true){
            time(&start);
            resetTimer = false;
        }*/
        grid.drawGridLines(window);
        
        
        if (isGameRunning == true) {
            //grid.drawCells(window);
            //grid.drawGridLines(window);
        
            //sf::Time t1 = sf::milliseconds(5);
            //sf::sleep(t1);
            
            //time(&end);
            std::cout << "start is " << start << std::endl;
            std::cout << "end is " << end << std::endl;

            
            //std::cout << "time is " << end - start << std::endl;
            
            if (elapsed.asMilliseconds() > t1.asMilliseconds()) {
                grid.update(window);
                grid.drawGridLines(window);
                //resetTimer = true;
                clock.restart();
                genNum++;
                genCounter.setString("generation: " + std::to_string(genNum));
                //delayCounter.setString("delay: " + std::to_string(t1.asMilliseconds())+"ms");


            }
            //grid.drawCells(window);
            //grid.drawGridLines(window);
            //}
            //window.draw(line, 2, sf::Lines);
        }
        
        //draw buttons
        
        window.draw(blinkerButton.getShape());
        window.draw(blinkerButton.getText());
        window.draw(gliderButton.getShape());
        window.draw(gliderButton.getText());
        
        window.draw(goblinGunButton.getShape());
        window.draw(goblinGunButton.getText());
        if(!isGameRunning) {
        window.draw(clearButton.getShape());
        window.draw(clearButton.getText());
        }
        if(!isGameRunning) {
        window.draw(startButton.getShape());
        window.draw(startButton.getText());
        } else {
        window.draw(stopButton.getShape());
        window.draw(stopButton.getText());
        window.draw(speedUpButton.getShape());
        window.draw(speedUpButton.getText());
        window.draw(speedDownButton.getShape());
        window.draw(speedDownButton.getText());
        }

        window.draw(genCounter);
        window.draw(delayCounter);
        window.display();
    }
    
} //end run()

