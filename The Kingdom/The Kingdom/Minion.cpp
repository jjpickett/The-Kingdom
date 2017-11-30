
#include "Minion.h"


Minion::Minion() {}

void Minion::Init()
{
	healthText.setFont(font);
	damageText.setFont(font);
	asleepText.setFont(font);


	//SET SIZE AND FILL
	healthText.setFillColor(sf::Color::Black);
	damageText.setFillColor(sf::Color::Black);
	asleepText.setFillColor(sf::Color::Black);

	damageText.setCharacterSize(36);
	Card::Init();
}

Minion::Minion(GameDataRef data) : Card(data)
{
}

Minion::Minion(GameDataRef data, std::string name, std::string description, int cost, int health, int damageValue, bool taunt, bool charge) : Card(data, name, description, cost)
{
	
	this->maxHealth = health;
	this->curHealth = health;
	this->damageValue = damageValue;
	this->taunt = taunt;
	this->asleep = charge;
	this->charge = charge;

	Init();
}

Minion::~Minion()
{
}

sf::Int8 Minion::getDamage()
{
	return damageValue;
}

void Minion::setDamage(int damageAdjust)
{
	damageValue += damageAdjust;
}

bool Minion::isTaunt()
{
	return taunt;
}

bool Minion::isAsleep()
{
	return asleep;
}

void Minion::Draw(float dt)
{
	healthText.setString(std::to_string(curHealth));
	damageText.setString(std::to_string(damageValue));
	asleepText.setString(asleep ? "" : "ZZZ");

	Card::Draw(dt);
	
	//SET ASLEEP
	asleepText.setPosition(_cardSprite.getPosition().x + _cardSprite.getGlobalBounds().width - 60, _cardSprite.getPosition().y + 20);
	_data->window.draw(asleepText);

	//HEALTH
	healthText.setPosition(_cardSprite.getPosition().x + 9, _cardSprite.getPosition().y + _cardSprite.getGlobalBounds().height - 45);
	_data->window.draw(healthText);

	//DAMAGE
	damageText.setPosition(_cardSprite.getPosition().x + _cardSprite.getGlobalBounds().width - 38, _cardSprite.getPosition().y + _cardSprite.getGlobalBounds().height - 55);
	_data->window.draw(damageText);
}

void Minion::read(sf::Packet & is)
{
	is >> this->name >> this->description >> this->cost >> this->curHealth >> this->damageValue >> this->taunt >> this->charge >> this->endLine;

	Init();
}

sf::Packet Minion::write(sf::Packet & os)
{
	return os << this->getId() << this->name << this->description << this->cost << this->curHealth << this->damageValue << this->taunt << this->charge;
}
