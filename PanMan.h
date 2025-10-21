#pragma once
#include "Player.h"

class PanMan : public Player{
public:

	static AnimData** animation_bank;
	static sf::Texture* texture_bank;
	static char** movename_bank;

	static AnimData** opponent_bank;

	enum animation_names {

		S_IDLE,
		B_WALK,
		F_WALK,
		
		S_LP

	};

	

	void update();
	void hurt();
	void hit();

	PanMan();

};

PanMan::PanMan() {

	/* load all files */

	/* make all animations */

	/* initialise the goober */
	

}
void PanMan::update() {

	/* get new input */



	/* change anim if needed */
	if (animdata.frameHold == 0) {
		goto_next();
	}

	/* process input */



	/* cancel into new animation */
	if (animdata.frameHold == 0) {
		goto_next();
	}

	//if(hitstop--) return;

	/* update physics */
	animdata.frameHold--;
	physics.update();
	box_pos_update();
	sprite_pos_update();

}
void PanMan::hurt() {	//needs an AtkData

	/* ... */

}
void PanMan::hit() {

	/* ... */

}