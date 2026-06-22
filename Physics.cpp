#include "Physics.h"

#define FLOOR 0
#define FRICTION_VAL -1
#define GRAVITY_VAL -1


void Physics::apply_force(Physics force, int x_dir = 1, int y_dir = 1) {

	if (force.posX_op == ADD) posX += force.posX * x_dir;
	else					  posX  = force.posX;

	if (force.posY_op == ADD) posY += force.posY * y_dir;
	else					  posY  = force.posY;

	if (force.velX_op == ADD) velX += force.velX * x_dir;
	else					  velX  = force.velX * x_dir;

	if (force.velY_op == ADD) velY += force.velY * y_dir;
	else					  velY  = force.velY * y_dir;

	if (force.accX_op == ADD) accX += force.accX * x_dir;
	else					  accX  = force.accX * x_dir;

	if (force.accY_op == ADD) accY += force.accY * y_dir;
	else					  accY  = force.accY * y_dir;

}

//> might need a revisit - what did i want to use accX/Y values for again?
void Physics::update() {

	velX += accX;
	velY += accY;

	if (FRICTION && posY == FLOOR) {
		if (velX > 0){
			velX += FRICTION_VAL;
            if(velX < 0) velX = 0;
        }
        if (velX < 0)
            velX -= FRICTION_VAL;
            if(velX > 0) velX = 0;
	}
    
	if (GRAVITY) {
		velY += GRAVITY_VAL;
		if (posY == FLOOR) velY = 0;
	}

	posX += velX;
	posY += velY;

	if (posY < FLOOR) posY = 0;

}
