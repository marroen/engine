//#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void openWindow();
ConvexShape getStickman();
RectangleShape getGround(); // TODO: static
ConvexShape handleInput(Event event, ConvexShape stickman);
