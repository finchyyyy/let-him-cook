#pragma once
#define FLOOR 0

//_op are bitflags that can be used for anything

//for applying forces
#define ADD false
#define REPLACE true

//for updating objects
#define FRICTION accX_op
#define GRAVITY accY_op

#define FRICTION_VAL -1
#define GRAVITY_VAL -1

class Physics {
public:

	int posX, posY; bool posX_op, posY_op;		//position
	int velX, velY; bool velX_op, velY_op;		//velocity
	int accX, accY; bool accX_op, accY_op;		//acceleration

	void apply_force(Physics, int, int);

	void update();

};


void Physics::apply_force(Physics force, int x_dir = 1, int y_dir = 1) {

	if (force.posX_op == ADD) posX += force.posX * x_dir;
	else					  posX = force.posX;

	if (force.posY_op == ADD) posY += force.posY * y_dir;
	else					  posY = force.posY;

	if (force.velX_op == ADD) velX += force.velX * x_dir;
	else					  velX = force.velX * x_dir;

	if (force.velY_op == ADD) velY += force.velY * y_dir;
	else					  velY = force.velY * y_dir;

	if (force.accX_op == ADD) accX += force.accX * x_dir;
	else					  accX = force.accX * x_dir;

	if (force.accY_op == ADD) accY += force.accY * y_dir;
	else					  accY = force.accY * y_dir;

}

void Physics::update() {

	velX += accX;
	velY += accY;

	if (FRICTION) {

		if (velX)

			velX += FRICTION_VAL;

	}
	if (GRAVITY) {

		velY += GRAVITY_VAL;	//acts down

		if (posY == FLOOR) velY = 0;
	}

	posX += velX;
	posY += velY;

	if (posY < FLOOR) posY = 0;

}