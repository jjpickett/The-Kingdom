
#include "MainMenuState.h"
#include "SearchingState.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

void MainMenuState::Init()
{
	this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("PlayButton", MAIN_MENU_PLAY_FILEPATH);

	this->_background.setTexture(this->_data->assets.getTexture("Background"));
	this->_playButton.setTexture(this->_data->assets.getTexture("PlayButton"));

	this->_playButton.setPosition((SCREEN_WIDTH/2)-(this->_playButton.getGlobalBounds().width/2), (SCREEN_HEIGHT / 2) + 200);

}

void MainMenuState::HandleInput()
{
	sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window)) {
				this->_data->machine.AddState(StateRef(new SearchingState(_data)), true);
			}
		}
}

void MainMenuState::Update(float dt)
{

}

void MainMenuState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);

	this->_data->window.display();
}
