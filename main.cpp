#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void openWindow();
ConvexShape getStickman();
RectangleShape getGround();
ConvexShape handleInput(Event event, ConvexShape stickman);

int main() {
  cout << "Hello?\n";
  openWindow();
  return EXIT_SUCCESS;
}

void openWindow() {
  RenderWindow window(VideoMode(1600, 1200), "Engine", Style::Close);
  window.setFramerateLimit(60);
  sf::Font font;
  if (!font.loadFromFile("rune.ttf")) {
    cout << "Error loading font\n";
  }
  Text text("Hello", font, 50);
  ConvexShape stickman = getStickman();
  RectangleShape ground = getGround();
  while(window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::KeyPressed) {
        stickman = handleInput(event, stickman);
        // Global Bounds act as "traditional" bounds
        if (stickman.getGlobalBounds().intersects(ground.getGlobalBounds()))
          cout << "Intersection\n";
      }
    }
    window.clear();
    window.draw(text);
    window.draw(stickman);
    window.draw(ground);
    window.display();
  }
}

ConvexShape handleInput(Event event, ConvexShape stickman) {
  if (event.key.scancode == Keyboard::Scan::D) {
    stickman.move(10, 0);
  }
  if (event.key.scancode == Keyboard::Scan::A) {
    stickman.move(-10, 0);
  }
  if (event.key.scancode == Keyboard::Scan::W) {
    stickman.move(0, -10);
  }
  if (event.key.scancode == Keyboard::Scan::S) {
    stickman.move(0, 10);
  }
  return stickman;
}

ConvexShape getStickman() {
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

RectangleShape getGround() {
  RectangleShape ground = RectangleShape(Vector2f(1700, 100));
  ground.setPosition(0, 500);
  ground.setFillColor(Color::Green);
  return ground;
}
