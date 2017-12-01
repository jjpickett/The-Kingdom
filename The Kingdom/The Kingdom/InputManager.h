/// \file	InputManager.h.
///
/// \brief	Declares the input manager class

#pragma once

#include <SFML/Graphics.hpp>

/// \class	InputManager
///
/// \brief	Manager for inputs.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class InputManager
{
public:

	/// \fn	InputManager::InputManager()
	///
	/// \brief	Default constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	InputManager() {}

	/// \fn	InputManager::~InputManager()
	///
	/// \brief	Destructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	~InputManager() {}

	/// \fn	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	///
	/// \brief	Query if 'object' is sprite clicked
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param 		   	object	The object.
	/// \param 		   	button	The button.
	/// \param [in,out]	window	The window.
	///
	/// \return	True if sprite clicked, false if not.

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

	/// \fn	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window);
	///
	/// \brief	Gets mouse position
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param [in,out]	window	The window.
	///
	/// \return	The mouse position.

	sf::Vector2i GetMousePosition(sf::RenderWindow &window);

	/// \fn	bool InputManager::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::RenderWindow & window);
	///
	/// \brief	Check sprite collision
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param 		   	sprite1	The first sprite.
	/// \param 		   	sprite2	The second sprite.
	/// \param [in,out]	window 	The window.
	///
	/// \return	True if it succeeds, false if it fails.

	bool InputManager::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::RenderWindow & window);

};

