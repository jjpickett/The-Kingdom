
#include "Totem.h"

Totem::Totem(GameDataRef data) : Card(data)
{
}

Totem::Totem(GameDataRef data, std::string name, std::string description, int cost, int health, bool taunt, char ability, int amount) : Card(data, name, description, cost)
{
	this->ability = ability;
	this->amount = amount;
	this->curHealth = health;
	this->maxHealth = health;
	this->taunt = taunt;

	Init();
	
}

void Totem::Init()
{
	healthText.setFont(font);


	//SET SIZE AND FILL
	healthText.setFillColor(sf::Color::Black);
	Card::Init();
}

Totem::~Totem()
{
}

void Totem::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->ability >> this->amount >> this->curHealth >> this->taunt >> this->endLine;
	Init();
}

sf::Packet Totem::write(sf::Packet & os)
{
	os << this->getId() << this->name << this->description << this->cost << this->ability << this->amount << this->curHealth << this->taunt;
	return os;
}

void Totem::effect()
{
}

void Totem::Draw(float dt)
{
	healthText.setString(std::to_string(curHealth));

	Card::Draw(dt);

	//HEALTH
	healthText.setPosition(_cardSprite.getPosition().x + 9, _cardSprite.getPosition().y + _cardSprite.getGlobalBounds().height - 45);
	_data->window.draw(healthText);
}
