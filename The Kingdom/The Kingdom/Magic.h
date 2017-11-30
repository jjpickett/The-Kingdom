//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The Magic class is an abstract class that will be inherited by Magic cards, 
/// inherits from Card.
///

#pragma once

#include "Card.h"
#include "DEFINITIONS.h"
#include "Game.h"

// *******************************************************************************
/// The Magic class is an abstract class that will be inherited by Magic cards, 
/// inherits from Card. Non permanent card that applies its effect then 
/// leaves play.
// *******************************************************************************
class Magic : public Card
{
public:

	Magic(GameDataRef data);
	/// Constructs a Magic object.
	Magic(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);

	/// Destroys the Magic object.
	~Magic();

	/// The effect of the Magic card.
	/// \param[in] board The current game board.
	virtual void effect() = 0;

	void Draw(float dt) override { Card::Draw(dt); }
	virtual sf::Packet write(sf::Packet & os) = 0;
	
	virtual sf::Int8 getId() = 0;

	/// Gets the Minions curHealth.
	/// \return The Minions curHealth.
	virtual sf::Int8 getCurHealth() = 0;

	/// Sets the Minions curHealth.
	virtual void setCurHealth(int curHealth) = 0;

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	virtual sf::Int8 getDamage() = 0;

	/// Sets the Minions damageValue.
	virtual void setDamage(int damagealue) = 0;

protected:

	/// \brief	ID of the card which will determine what effect it has.
	sf::Uint8 ability;

	/// \brief	The amount
	sf::Int8 amount;
};

