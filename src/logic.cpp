#include <SFML/Graphics.hpp>
#include <iostream>
#include "logic.h"

using namespace std;
using namespace sf;

const int GROUND_Y = 500;

void openWindow() {
  RenderWindow window(VideoMode(1600, 1200), "Engine", Style::Close);
  window.setFramerateLimit(60);
  sf::Font font;
  if (!font.loadFromFile("rune.ttf")) {
    cout << "Error loading font\n";
  }
  Text text("Hello", font, 50);
  ConvexShape stickman = createStickman();
  RectangleShape ground = createGround();
  RectangleShape wall = createWall();
  while(window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::KeyPressed) {        
        stickman = handleInput(event.key.scancode, stickman);
        if (stickman.getGlobalBounds().intersects(ground.getGlobalBounds())
          || stickman.getGlobalBounds().intersects(wall.getGlobalBounds()))
        stickman = handleInput(reverseKeyPressedEvent(event.key.scancode), stickman);
        // Global Bounds act as "traditional" bounds
        if (stickman.getGlobalBounds().intersects(ground.getGlobalBounds()))
          cout << "Intersection\n";
        if (stickman.getGlobalBounds().intersects(wall.getGlobalBounds()))
          cout << "Intersection\n";
      }
    }
    window.clear();
    window.draw(text);
    window.draw(stickman);
    window.draw(ground);
    window.draw(wall);
    window.display();
  }
}

Keyboard::Scan::Scancode reverseKeyPressedEvent(Keyboard::Scan::Scancode scancode) {
  switch(scancode) {
    case Keyboard::Scan::D:
      return Keyboard::Scan::A;
      break;
    case Keyboard::Scan::A:
      return Keyboard::Scan::D;
      break;
    case Keyboard::Scan::W:
      return Keyboard::Scan::S;
      break;
    case Keyboard::Scan::S:
      return Keyboard::Scan::W;
      break;
    default:
      return Keyboard::Scan::Unknown;
      break;
  }
}

ConvexShape handleInput(Keyboard::Scan::Scancode scancode, ConvexShape stickman) {
  if (scancode == Keyboard::Scan::D) {
    stickman.move(10, 0);
  }
  if (scancode == Keyboard::Scan::A) {
    stickman.move(-10, 0);
  }
  if (scancode == Keyboard::Scan::W) {
    stickman.move(0, -10);
  }
  if (scancode == Keyboard::Scan::S) {
    if (stickman.getPosition().y < (GROUND_Y - 17))
      stickman.move(0, 10);
  }
  return stickman;
}

ConvexShape createStickman() {
  ConvexShape polygon = ConvexShape(3);
  polygon.setPoint(0, Vector2f(0, 0));
  polygon.setPoint(1, Vector2f(0, 10));
  polygon.setPoint(2, Vector2f(25, 5));
  polygon.setOutlineColor(Color::Red);
  polygon.setOutlineThickness(5);
  polygon.setFillColor(Color::Red);
  polygon.setPosition(700, 483);
  return polygon;
}

RectangleShape createGround() {
  RectangleShape ground = RectangleShape(Vector2f(1700, 100));
  ground.setPosition(0, GROUND_Y);
  ground.setFillColor(Color::Green);
  return ground;
}

RectangleShape createWall() {
  RectangleShape wall = RectangleShape(Vector2f(100,500));
  wall.setPosition(1300, GROUND_Y - 500);
  wall.setFillColor(Color::Blue);
  return wall;
}

