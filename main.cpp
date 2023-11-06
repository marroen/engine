#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;

void open_window();

int main() {
  cout << "Hello?\n";
  open_window();
  return EXIT_SUCCESS;
}

void open_window() {
  sf::RenderWindow window(sf::VideoMode(1600, 1200), "Engine", sf::Style::Fullscreen);
  sf::Font font;
  if (!font.loadFromFile("rune.ttf")) {
    cout << "Error loading font\n";
  }
  sf::Text text("Hello", font, 50);
  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(text);
    window.display();
  }
}
