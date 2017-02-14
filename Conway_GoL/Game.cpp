//  Game.cpp
//  Conway_GoL


#include "Game.hpp"

using namespace Constants_GoL;


//Game class default constructor
Game::Game() {
    //assign window settings
    window.create(sf::VideoMode(kWindowWidth, kWindowHeight), "Game of Life");
    
    //initialize game status flag
    isGameRunning = false;
    
}

//simplify button draw methods
void Game::drawButton(Button &btn) {
    window.draw(btn.getShape());
    window.draw(btn.getText()); 
}


//draw the blinker shape
void Game::drawBlinker() {
    
    //scale the drawing of shape according to the cellSize and draw at center of window
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);

}

//draw the glider shape
void Game::drawGlider() {
    
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize + kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize-kCellSize, kCellsPerRow/2 *kCellSize + 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/2 * kCellSize + kCellSize, kCellsPerRow/2 * kCellSize + 2*kCellSize);
}

//draw the gun shape from left to right
void Game::drawGoblinGun() {
    
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + kCellSize, kCellsPerRow/2 * kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    grid.setCellIsAlive(true, kCellsPerCol/4 * kCellSize + kCellSize, kCellsPerRow/2*kCellSize + kCellSize);
    
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

//runs the main game loop
void Game::run() {
    
    //set background texture
    sf::Texture background;
    if (!(background.loadFromFile(resourcePath() + "white_1600x1200.jpg"))) {
        std::cout << "Error: could not load image" << std::endl;
        return EXIT_FAILURE;
    }
    
    //set font
    sf::Font font;
    if (!(font.loadFromFile(resourcePath() + "Arial.ttf"))) {
        std::cout << "Error: could not load text file" << std::endl;
        return EXIT_FAILURE;
    }

    //assign texture to sprite, which will be drawn
    sf::Sprite gameBackground(background);
    
    //limit fps
    window.setFramerateLimit(30);
    
    //create gray color
    sf::Color gray(210, 210, 210);
    
    //create buttons with text, color, and x and y positions
    Button blinkerButton ("Blinker", gray, 160, 1060);
    Button gliderButton ("Glider", gray, 330, 1060);
    Button goblinGunButton ("GoblinGun", gray, 480, 1060);
    Button clearButton("CLEAR", gray, 1100, 1060);
    Button startButton("START", gray, 1260, 1060);
    Button stopButton("STOP", gray, 1260, 1060);
    Button speedUpButton("SPEED +", gray, 700, 1060);
    Button speedDownButton("SPEED -", gray, 850, 1060);
    
    //set cell generation counter
    int genNum = 0;
    
    //set text that shows the cell generation counter
    sf::Text genCounter("generation: " + std::to_string(genNum), font, 40);
    genCounter.setFillColor(sf::Color::Black);
    genCounter.setPosition(5, 0);
  
    //start the clock
    sf::Clock clock;
    
    //set delay between frames
    sf::Time frameDelay = sf::milliseconds(500);

    //set text that shows the frame delay
    sf::Text delayCounter("delay: " + std::to_string(frameDelay.asMilliseconds()) + "ms", font, 40);
    delayCounter.setFillColor(sf::Color::Black);
    delayCounter.setPosition(5, 40);
    
    int count = 0;
    int countBottom = 0;
    //main game loop
    while (window.isOpen()) {
        //event handler
        while (window.pollEvent(event)) {

            //when window close button is pressed, close it
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //check when left mouse button is released (instead of 'pressed' which will sometimes detect
            //multiple clicks in each loop iteration)
            if (event.type == sf::Event::MouseButtonReleased) {
                
                //get the position of the mouse within the window
                sf::Vector2i position = sf::Mouse::getPosition(window);
               
                //if mouse position is hovering over startButton
                if (position.x > startButton.getBound(Button::left) && position.x < startButton.getBound(Button::right) && position.y > startButton.getBound(Button::top) && position.y < startButton.getBound(Button::bottom)) {
                    
                    //if game is running, mouse click pauses it; else restarts it
                    if (isGameRunning == true) {
                        isGameRunning = false;
                    } else {
                        isGameRunning = true;
                    }
                }
                
                if (!isGameRunning) {
                    count++;
                    std::cout << "key pressed " << count << std::endl;
                    //if left mouse is pressed, set switch cell status
                    if (grid.getCellIsAlive(position.x, position.y) == false) {
                        grid.setCellIsAlive(true, position.x, position.y);
                    }
                    
                    else {
                        grid.setCellIsAlive(false, position.x, position.y);
                    }
                    
                    //if mouse is over clearButton
                    if (position.x > clearButton.getBound(Button::left) && position.x < clearButton.getBound(Button::right) && position.y > clearButton.getBound(Button::top) && position.y < clearButton.getBound(Button::bottom)) {
                        
                        //clear grid and reset generation counter
                        grid.clearGrid();
                        genNum = 0;
                        genCounter.setString("generation: " + std::to_string(genNum));
                    }
                }
                //if mouse is over blinkerButton
                if (position.x > blinkerButton.getBound(Button::left) && position.x < blinkerButton.getBound(Button::right) && position.y > blinkerButton.getBound(Button::top) && position.y < blinkerButton.getBound(Button::bottom)) {
                    
                    grid.clearGrid();
                    genNum = 0;
                    drawBlinker();
                }
                //if mouse is over gliderButton
                if (position.x > gliderButton.getBound(Button::left) && position.x < gliderButton.getBound(Button::right) && position.y > gliderButton.getBound(Button::top) && position.y < gliderButton.getBound(Button::bottom)) {
                    
                    grid.clearGrid();
                    genNum = 0;
                    drawGlider();
                }
                //if mouse is over goblinGunButton
                if (position.x > goblinGunButton.getBound(Button::left) && position.x < goblinGunButton.getBound(Button::right) && position.y > goblinGunButton.getBound(Button::top) && position.y < goblinGunButton.getBound(Button::bottom)) {
                    
                    grid.clearGrid();
                    genNum = 0;
                    drawGoblinGun();
                }
                //if mouse is over speedUpButton
                if (position.x > speedUpButton.getBound(Button::left) && position.x < speedUpButton.getBound(Button::right) && position.y > speedUpButton.getBound(Button::top) && position.y < speedUpButton.getBound(Button::bottom)) {
                    
                    //with every press of speedUpButton, decrement delay by 50ms but keep delay >= 0
                    if (frameDelay.asMilliseconds() > 0) {
                        frameDelay -= sf::milliseconds(50);
                    }
                    delayCounter.setString("delay: " + std::to_string(frameDelay.asMilliseconds())+"ms");
                }
                //if mouse is over speedDownButton
                if (position.x > speedDownButton.getBound(Button::left) && position.x < speedDownButton.getBound(Button::right) && position.y > speedDownButton.getBound(Button::top) && position.y < speedDownButton.getBound(Button::bottom)) {
                    
                    //increment delay with each press but keep frameDelay <= 1000
                    if (frameDelay.asMilliseconds() < 1000) {
                        frameDelay += sf::milliseconds(50);
                    }
                    delayCounter.setString("delay: " + std::to_string(frameDelay.asMilliseconds())+"ms");
                }
                
            } //end mouse pressed
    
            //if spacebar is pressed, pause the game
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space) {
                    isGameRunning = !isGameRunning;
                }
            }
            
        }
        //begin drawing in the loop
        window.clear();
        window.draw(gameBackground);
        grid.drawCells(window);
        grid.drawGridLines(window);

        //get elapsed time with each loop
        sf::Time elapsed = clock.getElapsedTime();
        
        if (isGameRunning == true) {
            
            //only update cells if the time elapsed goes over frameDelay
            if (elapsed.asMilliseconds() > frameDelay.asMilliseconds()) {
                grid.update(window);

                clock.restart();
                genNum++;
                genCounter.setString("generation: " + std::to_string(genNum));
            }
            drawButton(stopButton);
            drawButton(speedUpButton);
            drawButton(speedDownButton);

        } else {
            drawButton(startButton);
            drawButton(clearButton);
        }
        
        grid.drawCells(window);
        grid.drawGridLines(window);
        drawButton(blinkerButton);
        drawButton(gliderButton);
        drawButton(goblinGunButton);
        
        countBottom++;
        std::cout << countBottom << std::endl;
        window.draw(genCounter);
        window.draw(delayCounter);
        window.display();
    }
    
} //end run()

