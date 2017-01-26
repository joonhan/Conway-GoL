
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
/*
int main(int, char const**) {
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Game of Life");
    
    sf::Texture background_pic;
    sf::Texture soldier_2d;
    sf::Sprite background;
    sf::Sprite soldier;
    
    if (!background_pic.loadFromFile(resourcePath() + "cute_image.jpg")) {
        std::cout << "Error: could not load image!" << std::endl;
    }
    if (!soldier_2d.loadFromFile(resourcePath() + "soldier.png")) {
        std::cout << "Error: could not load image!" << std::endl;
    }
    
    background.setTexture(background_pic);
    soldier.setTexture(soldier_2d);
    soldier.setTextureRect(sf::IntRect(10, 10, 45, 60));
    soldier.setTextureRect(sf::IntRect(70, 10, 45, 60));
    
    double counter = 10;
    double movementSpeed = 1;
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color(0, 0, 50));

    sf::RectangleShape line(sf::Vector2f(300, 10));
    line.setFillColor(sf::Color(255, 0, 0));
    line.rotate(10);
    */
    //window.setVerticalSyncEnabled(true);  // turn on if there is screen tearing
/*    while (window.isOpen()) {
        
        sf::Event windowOpen;
        //window.setPosition(sf::Vector2i(10, 10));
        //window.setSize(sf::Vector2u(1920, 1080));
        
        while(window.pollEvent(windowOpen)) {
        
            //if user clicks "x" button, close window
            //if(windowOpen.type == sf::Event::Closed){
            switch (windowOpen.type) {
                case(windowOpen.Closed) :
                    window.close();
                    break;
                    
                case(windowOpen.Resized) :
                    std::cout << "Height: " << windowOpen.size.height << "  Width: " << windowOpen.size.width << std::endl;
                    break;
                    
                default:
                    break;
            
            }
        }
        window.clear();
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            soldier.move(movementSpeed, 0);
            soldier.setTextureRect(sf::IntRect(counter, 200, 45, 60));
            counter += 64;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            soldier.move(-movementSpeed, 0);
            soldier.setTextureRect(sf::IntRect(counter, 73, 45, 60));
            counter += 64;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            soldier.move(0, movementSpeed);
            soldier.setTextureRect(sf::IntRect(counter, 130, 45, 60));
            counter += 64;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            soldier.setTextureRect(sf::IntRect(counter, 10, 45, 60));
            soldier.move(0, -movementSpeed);
            counter += 64;
        }
        if (counter >= 576) {
            counter = 10;
        }
         
        //window.clear(sf::Color::Black);
        //  window.draw(background);
        window.draw(soldier);
        window.display();
        //window.draw(circle);
        //window.draw(line);
        //window.display();
        //window.clear(sf::Color::Black);
        //line.rotate(10);
        //window.draw(line);
        //window.display();
    }
            
    return EXIT_SUCCESS;
}*/
