#pragma once
#include "Box.h"

class HitData {



};

class AnimData {
public:

	unsigned int move_ID = 0;
	unsigned int frameHold = 30;
	unsigned int cancels = 0;

	sf::Sprite sprite;
	int originX = 40;
	int originY = 128;


	Box** boxes = nullptr;

	AnimData* next = nullptr;

};

// this is a function that does memory management - therefore it is possible for it to shit itself and die
// I should do smth to make it less bad when it shits and dies. Too bad!
// also rewrite this with fscanf if possible?

AnimData* create_animation(const char* filename, sf::Texture &texture, AnimData* n = nullptr) {

	std::ifstream infile;
	infile.open(filename);		//have a failstate?

		//these should change for each animation
	int width = 76;
	int height = 128;

	AnimData** animation;
	
	animation = (AnimData**)malloc(sizeof(AnimData*));

	for (int frames = 0; ; frames++) {		//frames is also used for sprite offset

		animation = (AnimData**)realloc(animation, sizeof(AnimData*) * (frames + 1));

		if (infile.peek() == EOF) {
		
			std::cout << "no more datas, ending";
			animation[frames] = nullptr;
			break;
		
		}

		animation[frames] = new AnimData;

			//extra AnimData stuff 
		animation[frames]->sprite.setTexture(texture);
		animation[frames]->sprite.setTextureRect(sf::IntRect(frames*width, 0, width, height));


		animation[frames]->boxes = (Box**)malloc(sizeof(Box*));

		for (int i = 0; ; i++) {

			animation[frames]->boxes = (Box**)realloc(animation[frames]->boxes, sizeof(Box*) * (i + 1));

			if (infile.peek() == EOF) {
				animation[frames]->boxes[i] = nullptr;
				break;
			}

			if (infile.peek() == '\n') {

				infile.get();
				std::cout << "no more boxes, ending" << '\n';
				animation[frames]->boxes[i] = nullptr;
				break;

			}

			//box stuff

			int box_type = 0;
			infile >> box_type;

			Colbox* c = nullptr;
			Hurtbox* hu = nullptr;
			Hitbox* hi = nullptr;

			switch (box_type) {

			case 0:
				animation[frames]->boxes[i] = new Box();
				break;

			case 1:
				animation[frames]->boxes[i] = new Colbox();
				c = dynamic_cast<Colbox*>(animation[frames]->boxes[i]);
				break;

			case 2:
				animation[frames]->boxes[i] = new Hurtbox();
				hu = dynamic_cast<Hurtbox*>(animation[frames]->boxes[i]);
				break;

			case 3:
				animation[frames]->boxes[i] = new Hitbox();
				hi = dynamic_cast<Hitbox*>(animation[frames]->boxes[i]);
				break;

			default:
				animation[frames]->boxes[i] = new Box();
				continue;

			}

			infile >> animation[frames]->boxes[i]->posX;
			infile >> animation[frames]->boxes[i]->posY;
			infile >> animation[frames]->boxes[i]->width;
			infile >> animation[frames]->boxes[i]->height;

			switch (animation[frames]->boxes[i]->type) {	//could check against box_type again, but this ensures that it works properly

			case 0:
				break;

			case 1:
				//properties
				break;

			case 2:
				infile >> hu->invincible;
				break;

			case 3:
				//atkdata stuff	- maybe make them seperately?
				//so like each atkdata has 4 AtkData pointers

				break;
			}

			if (infile.peek() != EOF) {
				infile.get();
			}

		}

	}

	// linker
	for (int i = 0; ; i++) {
		animation[i]->next = animation[i + 1];

		if (!animation[i + 1]) {
			if (n)
				animation[i]->next = n;
			else
				animation[i]->next = animation[0];

			break;
		}
	}

	return animation[0];

}