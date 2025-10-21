#pragma once
class Box {
public:
	unsigned int type = 0;		//make sure this is an int, it gets fucky when you make it a char

	int posX, posY;
	int width, height;

	virtual ~Box() {			//needed for dynamic_cast stuff

	}
};

class Colbox : public Box {
public:

	Colbox() {
		type = 1;
	}
};

class Hurtbox : public Box {
public:

	bool invincible = false;

	Hurtbox() {
		type = 2;
	}
};

class Hitbox : public Box {
public:
	//AtkData atkdata;

	Hitbox() {
		type = 3;
	}
};