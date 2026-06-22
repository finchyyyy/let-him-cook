#ifndef PHYSICS_H
#define PHYSICS_H
//> Physics objects can represent one of two things:
//
//> Actual objects: These are things that we want to simulate, and usually run update() every game tick
//^ They are the intended target for apply_force()
//^ in this form, only accX_op and accY_op are used as flags, to denote whether friction and gravity apply to them:
#define FRICTION accX_op
#define GRAVITY accY_op
//
//> Forces: These are forces we apply to actual objects (the Physics param in apply_force())
//^ THEY ARE NOT INTENDED TO BE USED BY update()
//^ in this form, all _op flags have use, specifically to decide whether the base variable is to be added to or write over the original:
#define ADD false
#define REPLACE true

class Physics {
public:
	int posX, posY; bool posX_op, posY_op;		//position
	int velX, velY; bool velX_op, velY_op;		//velocity
	int accX, accY; bool accX_op, accY_op;		//acceleration

	void apply_force(Physics, int, int);

	void update();

};
#endif
