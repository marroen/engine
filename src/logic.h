//#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void openWindow();
ConvexShape createStickman();
ConvexShape createNPC();
RectangleShape createGround(); // TODO: static
RectangleShape createWall();
Keyboard::Scan::Scancode reverseKeyPressedEvent(Keyboard::Scan::Scancode scancode);
ConvexShape handleInput(Keyboard::Scan::Scancode scancode, ConvexShape stickman);
ConvexShape randomMove(ConvexShape npc);
