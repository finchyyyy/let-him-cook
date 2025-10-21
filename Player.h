#pragma once
#include "Object.h"
#include "Input.h"

#define QCF_WINDOW 60
#define QCB_WINDOW 60	//numbers pulled fresh from my ass
#define SRK_WINDOW 60

class Player : public Object {
public:

	static DPad QCFinputs[3];
	static DPad QCBinputs[3];
	static DPad SRKinputs[3];
	
	Fightstick input;
	Fightstick input_history[60] = {};	//change this, either big ROUND_LENGTH array or dynamic

	//make this virtual
	void update();

	//make these pure
	//virtual void hit();
	//virtual void hurt();

	bool QCF;
	bool QCB;
	bool SRK;

		//reliant on input_history[]
	bool QCF_check();
	bool QCB_check();
	bool SRK_check();

	static void SI_checker_init();
	Player();

};

Player::Player() {
	
}


void Player::update() {
	
	//input history needs to be changed
	/*
	for (int i = 0; i < 58; i++) {
		input_history[i + 1] = input_history[i];
	}
	*/

	input.new_input();
	//input_history[0] = input;

		//reliant on input_history
	//QCF = QCF_check();
	//QCB = QCB_check();
	//SRK = SRK_check();

	if (animdata.frameHold <= 0) {		//might change this back to ==, currently a precaution
		goto_next();
	}

	animdata.frameHold--;
	physics.update();
	box_pos_update();
	sprite_pos_update();

}

bool Player::QCF_check() {

	int prog = 0;

	for (int i = 0; i < QCF_WINDOW && prog < 3; i++) {
		if (input_history[i].move->x * x_flip == QCFinputs[prog].x
			&& input_history[i].move->y * y_flip == QCFinputs[prog].y) prog++;
	}

	if (prog == 3) return true;

	return false;

}

bool Player::QCB_check() {

	int prog = 0;

	for (int i = 0; i < QCB_WINDOW && prog < 3; i++) {
		if (input_history[i].move->x * x_flip == QCBinputs[prog].x
			&& input_history[i].move->y * y_flip == QCBinputs[prog].y) prog++;
	}

	if (prog == 3) return true;

	return false;

}

bool Player::SRK_check() {

	int prog = 0;

	for (int i = 0; i < SRK_WINDOW && prog < 3; i++) {
		if (input_history[i].move->x * x_flip == SRKinputs[prog].x
			&& input_history[i].move->y * y_flip == SRKinputs[prog].y) prog++;
	}

	if (prog == 3) return true;

	return false;

}

void Player::SI_checker_init() {
	
	
	QCFinputs[0].x = 0;
	QCFinputs[0].y = -1;
	QCFinputs[1].x = 1;
	QCFinputs[1].y = -1;
	QCFinputs[2].x = 1;
	QCFinputs[2].y = 0;

	QCBinputs[0].x = 0;
	QCBinputs[0].y = -1;
	QCBinputs[1].x = 1;
	QCBinputs[1].y = -1;
	QCBinputs[2].x = 1;
	QCBinputs[2].y = 0;

	SRKinputs[0].x = 1;
	SRKinputs[0].y = 0;
	SRKinputs[1].x = 0;
	SRKinputs[1].y = -1;
	SRKinputs[2].x = 1;
	SRKinputs[2].y = -1;
	
}
