//AnimData.h
#ifndef ANIMDATA_H
#define ANIMDATA_H

#include "Box.h"
#include <SFML/Graphics.hpp>

class AnimData {
public:
	unsigned int move_ID = 0;
	unsigned int frameHold = 30;
	unsigned int cancels = 0b00000000;		//bitfield - needs to be defined further
	AnimData* next = nullptr;

	sf::Sprite sprite;
	int originX = 40;
	int originY = 128;

	Box** boxes = nullptr;
};

AnimData* create_animation(const char* filename, sf::Texture &texture, AnimData* n = nullptr);
#endif
