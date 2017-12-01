/// \file	SearchingState.h.
///
/// \brief	Declares the searching state class

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "SFML\Network.hpp"
#include <iostream>

/// \class	SearchingState
///
/// \brief	A searching state.
///

class SearchingState : public State
{
public:

	/// \fn	SearchingState::SearchingState(GameDataRef data);
	///
	/// \brief	Constructor
	///
	///
	/// \param	data	The data.

	SearchingState(GameDataRef data);

	/// \fn	void SearchingState::Init();
	///
	/// \brief	Initializes this object
	///

	void Init();

	/// \fn	void SearchingState::HandleInput();
	///
	/// \brief	Handles the input
	///

	void HandleInput();

	/// \fn	void SearchingState::Update(float dt);
	///
	/// \brief	Updates the given dt
	///
	///
	/// \param	dt	The dt.

	void Update(float dt);

	/// \fn	void SearchingState::Draw(float dt);
	///
	/// \brief	Draws
	///
	///
	/// \param	dt	The dt.

	void Draw(float dt);

	/// \fn	void SearchingState::LookForPlayer();
	///
	/// \brief	Look for player
	///

	void LookForPlayer();

private:
	/// \brief	The data
	GameDataRef _data;

	/// \brief	The background
	sf::Sprite _background;

	/// \brief	The cancel button
	sf::Sprite _cancelButton;


};

