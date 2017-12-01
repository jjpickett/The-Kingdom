/// \file	MainMenuState.h.
///
/// \brief	Declares the main menu state class

#pragma once

#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"

/// \class	MainMenuState
///
/// \brief	A main menu state.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class MainMenuState : public State
{
public:

	/// \fn	MainMenuState::MainMenuState(GameDataRef data);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	The data.

	MainMenuState(GameDataRef data);

	/// \fn	void MainMenuState::Init();
	///
	/// \brief	Initializes this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void Init();

	/// \fn	void MainMenuState::HandleInput();
	///
	/// \brief	Handles the input
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void HandleInput();

	/// \fn	void MainMenuState::Update(float dt);
	///
	/// \brief	Updates the given dt
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	void Update(float dt);

	/// \fn	void MainMenuState::Draw(float dt);
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

	/// \brief	The play button
	sf::Sprite _playButton;
};

