
#include "GameOverState.h"
#include "Board.h"
#include "MainMenuState.h"
#include <iostream>

GameOverState::GameOverState(GameDataRef data) : _data(data)
{

}

void GameOverState::Init()
{
	this->_data->assets.LoadTexture("GameWin", WIN_SCREEN_FILEPATH);
	this->_data->assets.LoadTexture("GameLose", LOSE_SCREEN_FILEPATH);
	this->_data->assets.LoadTexture("ReturnButton", RETURN_TO_MAIN_FILEPATH);

	//TODO: Implement Logic for game winning or losing here
	this->_background.setTexture(this->_data->assets.getTexture("GameWin"));


	this->_returnButton.setTexture(this->_data->assets.getTexture("ReturnButton"));

	this->_returnButton.setPosition((SCREEN_WIDTH / 2) - (this->_returnButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_returnButton.getGlobalBounds().height / 2));

}

void GameOverState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		//If the user cancels the search, then take them back to the main menu
		if (this->_data->input.isSpriteClicked(this->_returnButton, sf::Mouse::Left, this->_data->window)) {
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}

		//TODO: Add functionality for if a user connects with another player
	}
}

void GameOverState::Update(float dt)
{

}

void GameOverState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_returnButton);

	this->_data->window.display();
}
