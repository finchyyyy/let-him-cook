#pragma once

/*
* 
* Slightly better
* Still have some more thinking to do though
* 
*/

//basically an interface
class Input {
public:

	sf::Keyboard::Key* binds = nullptr;

	virtual void assign_binds(sf::Keyboard::Key* a) = 0;		//this is (i hope?) allowed which is quite cool
	virtual void new_input() = 0;

	~Input() {
		//free(binds);
	}

};


class Button : public Input{
public:

	enum ButtonState {
		JUST_RELEASED = -1,
		NO_CHANGE = 0,
		JUST_PRESSED = 1
	};

	bool pressed;
	int status;

	Button() {

		binds = (sf::Keyboard::Key*)malloc(sizeof(sf::Keyboard::Key));
		pressed = false;
		status = NO_CHANGE;

	}

	void assign_binds(sf::Keyboard::Key* a) {

		*binds = *a;

	}

	void new_input() {

		bool now = sf::Keyboard::isKeyPressed(*binds);

		status = NO_CHANGE;

		if (pressed) status += JUST_RELEASED;
		if (now) status += JUST_PRESSED;

		pressed = now;

	}

};

class DPad : public Input{
public:

	int x, y;

	enum directions {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	DPad() {

		binds = (sf::Keyboard::Key*)malloc(sizeof(sf::Keyboard::Key) * 4);
		x = y = 0;

	}

	void assign_binds(sf::Keyboard::Key a[4]) {

		for (int i = 0; i < 4; i++)	binds[i] = a[i];

	}

	void new_input() {
		
		x = 0;
		if (sf::Keyboard::isKeyPressed(binds[RIGHT])) x++;
		if (sf::Keyboard::isKeyPressed(binds[LEFT])) x--;

		y = 0;
		if (sf::Keyboard::isKeyPressed(binds[UP])) y++;
		if (sf::Keyboard::isKeyPressed(binds[DOWN])) y--;

	}

};

/*
* 
* change name from Fightstick?
* assignment is slightly fucked from using two memory allocation
* 
*/

class Fightstick {	//is this the name i want?
public:

	enum input_device_names {
		DPAD = 0,
		LP,
		MP,
		HP,
		LK,
		MK,
		HK,
		INPUT_COUNT
	};

	//contains all sub-inputs
	Input** inputs = nullptr;

	DPad* move = nullptr;
	Button* buttons[6];

	Fightstick() {

		//input list
		inputs = (Input**)malloc(sizeof(Input*) * INPUT_COUNT);

		inputs[DPAD] = new DPad;
		for (int i = LP; i < INPUT_COUNT; i++)
			inputs[i] = new Button;

		//move and buttons
		move = (DPad*)inputs[DPAD];
		
		for (int i = 0; i < 6; i++) {
			buttons[i] = (Button*)inputs[i + LP];
		}

	}
						//!!!!TEST THIS!!!!
	~Fightstick() {

		for (int i = 0; i < INPUT_COUNT; i++) {
			delete inputs[i];
		}

		free(inputs);

	}

	void new_input() {

		for (int i = 0; i < INPUT_COUNT; i++) {

			inputs[i]->new_input();

		}

	}

	//[10] into [4] and 6*[1]
	//yucky hardcoded values incoming...
	void assign_binds(sf::Keyboard::Key a[10]) {
		
		//[4]
		sf::Keyboard::Key d[4];
		for (int i = 0; i < 4; i++) {
			d[i] = a[i];
		}
		move->assign_binds(d);

		//6*[1]
		for (int i = 0; i < 6; i++) {	
			buttons[i]->assign_binds(&a[i + 4]);
		}

	}

};
