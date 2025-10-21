#pragma once

class Object {
public:

	int ID = 0;

	Physics physics;

	int box_count = 0;	//not sure if i want this, but works for now
	Box* boxes = nullptr;

	AnimData animdata;

	int x_flip = 1;	//  1 for normal
	int y_flip = 1;	// -1 for flipped

	sf::Sprite sprite;

	void goto_next();
	void box_pos_update();
	void sprite_pos_update();

	

	virtual void update() {

		if (animdata.frameHold <= 0) {		//might change this back to ==, currently a precaution
			goto_next();
		}

		animdata.frameHold--;
		physics.update();
		box_pos_update();
		sprite_pos_update();

	}

	Object() {

	}

};

void Object::goto_next() {

	animdata = *animdata.next;
	//physics.apply_force(animdata.physics, x_flip, y_flip); uncomment when physics added

	//boxes
	box_count = 0;
	while (animdata.boxes[box_count]) box_count++;

	free(boxes);
	boxes = (Box*)malloc(box_count * sizeof(Box));

	for (int i = 0; i < box_count; i++) {

		//std::cout << i << " " << animdata.boxes[i] << "/n";

		boxes[i] = *animdata.boxes[i];	//careful around here, derefing nullptrs

	}

	sprite = animdata.sprite;

}

void Object::box_pos_update() {

	for (int i = 0; i < box_count; i++) {

		boxes[i].posX = physics.posX + animdata.boxes[i]->posX * x_flip;
		boxes[i].posY = physics.posY + animdata.boxes[i]->posY * y_flip;
		boxes[i].width = animdata.boxes[i]->width * x_flip;
		boxes[i].height = animdata.boxes[i]->height * y_flip;
	}

}

void Object::sprite_pos_update() {		//this isnt properly synced. too bad!

	sprite.setScale(x_flip, y_flip * -1);
	sprite.setPosition(physics.posX - (animdata.originX * x_flip),
		physics.posY - (animdata.originY * y_flip * -1));

}
