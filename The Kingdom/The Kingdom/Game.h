/// \file	Game.h.
///
/// \brief	Declares the game class

#pragma once

#include <memory>
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

/// \struct	GameData
///
/// \brief	A game data.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

struct GameData
{
	/// \brief	The machine
	StateMachine machine;
	/// \brief	The window
	sf::RenderWindow window;
	/// \brief	The assets
	AssetManager assets;
	/// \brief	The input
	InputManager input;
	/// \brief	Temporary
	int player;
	/// \brief	True to my turn
	bool myTurn;
	/// \brief	The socket
	sf::TcpSocket socket;
	/// \brief	The listener
	sf::TcpListener listener;
};

/// \typedef	std::shared_ptr<GameData> GameDataRef
///
/// \brief	Defines an alias representing the game data reference

typedef std::shared_ptr<GameData> GameDataRef;

/// \class	Game
///
/// \brief	A game.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class Game
{
public:

	/// \fn	Game::Game(int width, int height, std::string title);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	width 	The width.
	/// \param	height	The height.
	/// \param	title 	The title.

	Game(int width, int height, std::string title);

private:
	/// \brief	The dt
	const float dt = 1.0f/60.0f;
	/// \brief	The clock
	sf::Clock _clock;

	/// \brief	The data
	GameDataRef _data = std::make_shared<GameData>();

	/// \fn	void Game::Run();
	///
	/// \brief	Runs this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	void Run();

};

