
#include "InputManager.h"

bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		//Temporary rect for our object to see if it contains the mouse
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

bool InputManager::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::RenderWindow & window)
{
	sf::Rect<float> rect1 = sprite1.getGlobalBounds();
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();
	sf::IntRect tempRect(sprite2.getPosition().x, sprite2.getPosition().y, sprite2.getGlobalBounds().width, sprite2.getGlobalBounds().height);

	if (rect1.intersects(rect2) && tempRect.contains(sf::Mouse::getPosition(window)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}
