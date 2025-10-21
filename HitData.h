#pragma once
#include "Physics.h"
#include "AnimData.h"	//not needed

//also AtkData

//this data will be stored in a file (shock horror)
/*
* 
* dmg stun stop
* 
* [Physics]
* X +op Y +op [x3]
* 
* knockdown backturn (+extras)
* 
* some sort of numerical ID
* 
*/

class HitData {
public:

	static HitData* pluh[2];

	// >= 0
	int dmg;
	int stun;
	int stop;

	Physics knockback;
	
	//-1, 0, 1
	int knockdown;
	int backturn;

	AnimData* forced_opp_anim = nullptr;

};


