/// \file	SplashState.h.
///
/// \brief	Declares the splash state class

#pragma once

#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"

/// \class	SplashState
///
/// \brief	A splash state.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class SplashState : public State
{
public:

	/// \fn	SplashState::SplashState(GameDataRef data);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	The data.

	SplashState(GameDataRef data);

	/// \fn	void SplashState::Init();
	///
	/// \brief	Initializes this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void Init();

	/// \fn	void SplashState::HandleInput();
	///
	/// \brief	Handles the input
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void HandleInput();

	/// \fn	void SplashState::Update(float dt);
	///
	/// \brief	Updates the given dt
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	void Update(float dt);

	/// \fn	void SplashState::Draw(float dt);
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

	/// \brief	The clock
	sf::Clock _clock;

	/// \brief	The background
	sf::Sprite _background;
};

