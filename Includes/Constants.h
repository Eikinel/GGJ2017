#pragma once

# include <SFML\Graphics.hpp>
# include <vector>
# include <iostream>

// Screens order
# define CLOSE			-1
# define MENU_INDEX		0
# define OPTIONS_INDEX	2
# define GAME_INDEX		1

// Directories
# define ASSETS_DIR		"../Assets"
# define SPRITES_DIR	ASSETS_DIR"/Sprites"
# define FONTS_DIR		ASSETS_DIR"/Fonts"

// Global variable for screens, containing menu, game, etc.
class IScreen;
extern std::vector<IScreen *> all_screens;