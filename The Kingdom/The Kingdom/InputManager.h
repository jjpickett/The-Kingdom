#pragma once

#include <SFML/Graphics.hpp>


class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	bool InputManager::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::RenderWindow & window);

};

