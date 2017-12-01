
#include "Card.h"
#include "Board.h"

Card::Card()
{
}

Card::Card(GameDataRef data):_data(data)
{
}

void Card::Init()
{
	this->_cardSprite.setTexture(_data->assets.getTexture(name));

	this->font.loadFromFile(GAME_FONT);

	descriptionText.setFont(font);
	costText.setFont(font);
	asleepText.setFont(font);

	//SET SIZE AND FILL
	descriptionText.setFillColor(sf::Color::Black);
	descriptionText.setCharacterSize(14);

	costText.setFillColor(sf::Color::Black);


	asleepText.setFillColor(sf::Color::Black);
}



Card::Card(GameDataRef data, std::string name, std::string description, int cost) : _data(data)
{
	this->name = name;
	this->description = description;
	this->cost = cost;

	Init();
}

std::string Card::getName()
{
	return name;
}

std::string Card::getDescription()
{
	return description;
}

int Card::getCost()
{
	return cost;
}

bool Card::isSelected()
{
	return _selected;
}

void Card::setSelected(bool selected)
{
	_selected = selected;
}

void Card::setPosition(int x, int y)
{
	_cardSprite.setPosition(x, y);
}

void Card::Draw(float dt)
{
	descriptionText.setString(description);
	costText.setString(std::to_string(cost));

	//SET COST
	costText.setPosition(_cardSprite.getPosition().x + 14, _cardSprite.getPosition().y + 10);

	//SET DESCRIPTION
	descriptionText.setPosition(_cardSprite.getPosition().x + 28, _cardSprite.getPosition().y + (_cardSprite.getGlobalBounds().height / 2) + 28);
	
	_data->window.draw(_cardSprite);
	_data->window.draw(descriptionText);
	_data->window.draw(costText);

}

void Card::effect(Board * board)
{
}
