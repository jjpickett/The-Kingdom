/// \file	Player.cpp.
///
/// \brief	Implements the player class

#include "Player.h"

/// \fn	Player::Player()
///
/// \brief	Default constructor
///
/// \author	Jordan Pickett
/// \date	11/30/2017

Player::Player()
{
}

/// \fn	Player::Player(GameDataRef data)
///
/// \brief	Constructor
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	data	The data.

Player::Player(GameDataRef data):_data(data)
{
	this->font.loadFromFile(GAME_FONT);
	healthText.setFont(font);
	costTextactionPointText.setFont(font);

	healthText.setFillColor(sf::Color::Black);
	costTextactionPointText.setFillColor(sf::Color::Black);
}

/// \fn	Player::~Player()
///
/// \brief	Destructor
///
/// \author	Jordan Pickett
/// \date	11/30/2017

Player::~Player()
{
}

/// \fn	void Player::init()
///
/// \brief	Initializes this object
///
/// \author	Jordan Pickett
/// \date	11/30/2017

void Player::init()
{
	std::cout << "Init success" << std::endl;
	//TODO: Create a deck
	deck = CardFactory::newDeck(this->_data);


	drawCard();
	drawCard();
	drawCard();

}

/// \fn	int Player::getActionPoints()
///
/// \brief	Gets action points
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \return	The action points.

int Player::getActionPoints()
{
	return actionPoints;
}

/// \fn	void Player::setActionPoints(int modify)
///
/// \brief	Sets action points
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	modify	The modify.

void Player::setActionPoints(int modify)
{
	actionPoints += modify;
	if (actionPoints > 10)
		actionPoints = 10;
}

/// \fn	int Player::getHealth()
///
/// \brief	Gets the health
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \return	The health.

int Player::getHealth()
{
	return health;
}

/// \fn	void Player::setHealth(int modify)
///
/// \brief	Sets a health
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	modify	The modify.

void Player::setHealth(int modify)
{
	health += modify;
}

/// \fn	void Player::drawCard()
///
/// \brief	Draw card
///
/// \author	Jordan Pickett
/// \date	11/30/2017

void Player::drawCard()
{
	this->hand.push_back(deck.at(0));
	this->deck.erase(deck.begin());
}

/// \fn	Card* Player::playCard(int cardNum)
///
/// \brief	Play card
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	cardNum	The card number.
///
/// \return	Null if it fails, else a pointer to a Card.

Card* Player::playCard(int cardNum)
{
	Card* temp = hand.at(cardNum);
	this->hand.erase(hand.begin() + cardNum);
	return temp;
}

/// \fn	bool Player::isSeleting()
///
/// \brief	Query if this object is seleting
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \return	True if seleting, false if not.

bool Player::isSeleting()
{
	return currentlySelecting;
}

/// \fn	void Player::setSelection(bool isSelecting)
///
/// \brief	Sets a selection
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	isSelecting	True if this object is selecting.

void Player::setSelection(bool isSelecting)
{
	currentlySelecting = isSelecting;
}

/// \fn	void Player::Draw(float dt)
///
/// \brief	Draws
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	dt	The dt.

void Player::Draw(float dt)
{
	healthText.setString(std::to_string(health));
	costTextactionPointText.setString(std::to_string(actionPoints));

	if (isPlayer)
		_playerSprite.setPosition(SCREEN_WIDTH - (_playerSprite.getGlobalBounds().width * 1.15), SCREEN_HEIGHT - (_playerSprite.getGlobalBounds().height * 2) + 40);
	else
		_playerSprite.setPosition(SCREEN_WIDTH - (_playerSprite.getGlobalBounds().width * 1.15), _playerSprite.getGlobalBounds().height * 0.25);

	_data->window.draw(_playerSprite);

	//SET COST
	healthText.setPosition(_playerSprite.getPosition().x + 10, _playerSprite.getPosition().y + (_playerSprite.getGlobalBounds().height / 2) + 10);

	//SET DESCRIPTION
	costTextactionPointText.setPosition(_playerSprite.getPosition().x + _playerSprite.getGlobalBounds().width - 28, _playerSprite.getPosition().y + (_playerSprite.getGlobalBounds().height / 2));


	_data->window.draw(healthText);
	_data->window.draw(costTextactionPointText);


	int width = 0;
	//Draw whats in the Players hand 
	for (int index = 0; index < hand.size(); index++)
	{
		if (this->hand.at(index)->isSelected())
			hand.at(index)->setPosition(sf::Mouse::getPosition(this->_data->window).x - hand.at(index)->_cardSprite.getGlobalBounds().width / 2, sf::Mouse::getPosition(this->_data->window).y - hand.at(index)->_cardSprite.getGlobalBounds().height / 2);
		else
			hand.at(index)->setPosition(width, SCREEN_HEIGHT - hand.at(index)->_cardSprite.getGlobalBounds().height * 0.5);

		hand.at(index)->Draw(dt);
		width += hand.at(index)->_cardSprite.getGlobalBounds().width;

	}

}

/// \fn	bool Player::getTurn()
///
/// \brief	Gets the turn
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \return	True if it succeeds, false if it fails.

bool Player::getTurn()
{
	return myTurn;
}

/// \fn	void Player::setTurn(bool setTurn)
///
/// \brief	Sets a turn
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	setTurn	True to set turn.

void Player::setTurn(bool setTurn)
{
	myTurn = setTurn;
}

/// \fn	void Player::setPlayer(bool setPlayer)
///
/// \brief	Sets a player
///
/// \author	Jordan Pickett
/// \date	11/30/2017
///
/// \param	setPlayer	True to set player.

void Player::setPlayer(bool setPlayer)
{
	isPlayer = setPlayer;
}


