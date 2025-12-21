//Box.h
#pragma once

class Box {
public:
	unsigned int type = 0;

	int posX, posY;
	int width, height;

	virtual ~Box() {

	}
};

bool overlap(Box a, Box b);
