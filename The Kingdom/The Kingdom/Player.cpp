#include "Player.h"

Player::Player()
{
}

Player::Player(GameDataRef data):_data(data)
{
	this->font.loadFromFile(GAME_FONT);
	healthText.setFont(font);
	costTextactionPointText.setFont(font);

	healthText.setFillColor(sf::Color::Black);
	costTextactionPointText.setFillColor(sf::Color::Black);
}

Player::~Player()
{
}

void Player::init()
{
	std::cout << "Init success" << std::endl;
	//TODO: Create a deck
	deck = CardFactory::newDeck(this->_data);


	drawCard();
	drawCard();
	drawCard();

}


int Player::getActionPoints()
{
	return actionPoints;
}

void Player::setActionPoints(int modify)
{
	actionPoints += modify;
	if (actionPoints > 10)
		actionPoints = 10;
}

int Player::getHealth()
{
	return health;
}
void Player::setHealth(int modify)
{
	health += modify;
}
void Player::drawCard()
{
	this->hand.push_back(deck.at(0));
	this->deck.erase(deck.begin());
}
Card* Player::playCard(int cardNum)
{
	Card* temp = hand.at(cardNum);
	this->hand.erase(hand.begin() + cardNum);
	return temp;
}

bool Player::isSeleting()
{
	return currentlySelecting;
}

void Player::setSelection(bool isSelecting)
{
	currentlySelecting = isSelecting;
}

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

bool Player::getTurn()
{
	return myTurn;
}

void Player::setTurn(bool setTurn)
{
	myTurn = setTurn;
}

void Player::setPlayer(bool setPlayer)
{
	isPlayer = setPlayer;
}


