#pragma once
#include <SFML/Graphics.hpp>


	//draws a point
void draw(sf::RenderWindow& window, int x, int y) {
	sf::CircleShape circ(2.0f);
	
	circ.setPosition((float)x, (float)y);
	circ.setOrigin(2, 2);
	circ.setFillColor(sf::Color::Red);

	window.draw(circ);

}

	//draws a box
void draw(sf::RenderWindow& window, Box box) {

	sf::RectangleShape rect;
	sf::Color colour;

	switch (box.type) {

	case 1:
		colour = sf::Color::Magenta;
		break;

	case 2:
		colour = sf::Color::Blue;
		break;

	case 3:
		colour = sf::Color::Red;
		break;

	default:
		colour = sf::Color::Cyan;
		break;
	}


	rect.setPosition(box.posX, box.posY);
	rect.setSize(sf::Vector2f(box.width, box.height));

	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(colour);
	rect.setOutlineThickness(-2.0f);
	
	window.draw(rect);

}

void draw(sf::RenderWindow& window, Object object, bool extra_data = false) {

	//draw sprite - add when sprites added
	window.draw(object.sprite);

	//draw boxes and position if requested
	if (extra_data) {

		//boxes
		for (int i = 0; i < object.box_count; i++) {
			draw(window, object.boxes[i]);
		}

		//position
		draw(window, object.physics.posX, object.physics.posY);

	}

}


void draw(sf::RenderWindow& window, DPad dpad, int x, int y) {

	sf::CircleShape circ(15.0f);
	circ.setFillColor(sf::Color::Green);
	circ.setPosition(x + dpad.x * 30, y + dpad.y * 30);
	window.draw(circ);

}

void draw(sf::RenderWindow& window, Button button, int x, int y) {

	sf::CircleShape circ(8.0f);

	//button
	switch (button.status) {

	case Button::JUST_PRESSED:
		circ.setFillColor(sf::Color::Red);
		break;

	case Button::JUST_RELEASED:
		circ.setFillColor(sf::Color::Blue);
		break;

	case Button::NO_CHANGE:
		circ.setFillColor(sf::Color::Transparent);
		break;

	default:
		//shit is fucked yo
		circ.setFillColor(sf::Color::Green);

	}

	circ.setPosition(x, y);
	window.draw(circ);

}