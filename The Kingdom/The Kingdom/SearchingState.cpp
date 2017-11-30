
#include "DEFINITIONS.h"
#include "SearchingState.h"
#include "Board.h"
#include "MainMenuState.h"
#include "Shaman.h"
#include "Warrior.h"
#include "Mage.h"
#include <iostream>

const unsigned short PORT = 5000;
const std::string IPADDRESS("192.168.0.10");//change to suit your needs

SearchingState::SearchingState(GameDataRef data) : _data(data)
{

}

void SearchingState::Init()
{
	this->_data->assets.LoadTexture("SearchingBackground", SEARCHING_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("CancelButton", CANCEL_SEARCH_FILEPATH);

	this->_background.setTexture(this->_data->assets.getTexture("SearchingBackground"));
	this->_cancelButton.setTexture(this->_data->assets.getTexture("CancelButton"));

	this->_cancelButton.setPosition((SCREEN_WIDTH / 2) - (this->_cancelButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_cancelButton.getGlobalBounds().height / 2) + 200);
}

void SearchingState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->socket.disconnect();
			this->_data->listener.close();
			this->_data->window.close();
		}
		//If the user cancels the search, then take them back to the main menu
		if (this->_data->input.isSpriteClicked(this->_cancelButton, sf::Mouse::Left, this->_data->window)) {
			this->_data->socket.disconnect();
			this->_data->listener.close();
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
		//TODO: Add functionality for if a user connects with another player

	}
}

void SearchingState::Update(float dt)
{

}

void SearchingState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_cancelButton);

	this->_data->window.display();
	LookForPlayer();
}

void SearchingState::LookForPlayer()
{
	sf::Socket::Status status = this->_data->socket.connect(IPADDRESS, PORT);
	this->_data->socket.setBlocking(false);

	if (status == sf::Socket::Error)
	{
		this->_data->listener.listen(PORT);
		this->_data->listener.accept(this->_data->socket);
		std::cout << "New client connected: " << this->_data->socket.getRemoteAddress() << std::endl;
		this->_data->listener.close();
		//TODO: Make this dynamic
		this->_data->player = WARRIOR_CHARACTER;
		this->_data->myTurn = true;
		this->_data->machine.AddState(StateRef(new Board(_data)), true);
	}
	else if(status == sf::Socket::Done)
	{
		//TODO: Make this dynamic
		this->_data->player = SHAMAN_CHARACTER;
		this->_data->myTurn = false;
		std::cout << "Connected\n";
		this->_data->machine.AddState(StateRef(new Board(_data)), true);
	}


}
