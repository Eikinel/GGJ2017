#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

// Screens order
#define CLOSE		-1
#define GAME_INDEX	0

// Global variable for screens, containing menu, game, etc.
class IScreen;
extern std::vector<IScreen *> all_screens;