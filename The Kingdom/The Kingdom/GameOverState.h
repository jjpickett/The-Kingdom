/// \file	GameOverState.h.
///
/// \brief	Declares the game over state class

#pragma once

#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"

/// \class	GameOverState
///
/// \brief	A game over state.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class GameOverState : public State
{
public:

	/// \fn	GameOverState::GameOverState(GameDataRef data);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	The data.

	GameOverState(GameDataRef data);

	/// \fn	void GameOverState::Init();
	///
	/// \brief	Initializes this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void Init();

	/// \fn	void GameOverState::HandleInput();
	///
	/// \brief	Handles the input
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void HandleInput();

	/// \fn	void GameOverState::Update(float dt);
	///
	/// \brief	Updates the given dt
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	void Update(float dt);

	/// \fn	void GameOverState::Draw(float dt);
	///
	/// \brief	Draws
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	void Draw(float dt);

private:
	/// \brief	The data
	GameDataRef _data;

	/// \brief	The background
	sf::Sprite _background;

	/// \brief	The return button
	sf::Sprite _returnButton;

};

