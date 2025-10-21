#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <fstream>
#define SOURCE 1

#include "Input.h"
#include "Physics.h"
#include "Box.h"
#include "Input.h"
#include "AnimData.h"
#include "Object.h"
#include "Player.h"
#include "PanMan.h"
#include "Drawer.h"

	//1920x1080 or 1600x1200

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200

sf::Texture pan_sidle;


#ifdef SOURCE

DPad Player::QCFinputs[] = {};
DPad Player::QCBinputs[] = {};
DPad Player::SRKinputs[] = {};

#endif // SOURCE

/*
* !
* ! any Object's sprite is unassigned until its first goto_next() call - fix this in specific constructors?
* !
*/


int main() {
	
	pan_sidle.loadFromFile("pan_sidle.png");

	AnimData* animation = create_animation("pluh.txt", pan_sidle);

	Player player;
	player.animdata = animation[0];

	sf::Keyboard::Key binds[10] = {
		sf::Keyboard::W,
		sf::Keyboard::S,
		sf::Keyboard::A,
		sf::Keyboard::D,
		sf::Keyboard::Numpad7,
		sf::Keyboard::Numpad8,
		sf::Keyboard::Numpad9,
		sf::Keyboard::Numpad4,
		sf::Keyboard::Numpad5,
		sf::Keyboard::Numpad6
	};
	player.input.assign_binds(binds);

		/* displaying them */
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "BIG GAMING", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	sf::View view;		//(0, 0) is bottom left, +y is up (default is +y as down) - NOTE: THIS REVERSES ROTATIONS
	view.reset(sf::FloatRect(0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT * -1));
	window.setView(view);

	while (window.isOpen()) {

		sf::Event event;	//generic window events
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.physics.posX++;
		player.update();

			// <------------ rendering starts HERE dumbass
		window.clear();

		draw(window, *player.input.move, 100, 100);
		draw(window, *player.input.buttons[0], 200, 100);

		draw(window, player, true);

		window.display();
	}


	std::cout << sizeof(Box) << " ";
	std::cout << sizeof(Hurtbox) << " ";
	std::cout << sizeof(Hitbox) << " ";

	std::cout << "yuh";
	

	return 0;
}
