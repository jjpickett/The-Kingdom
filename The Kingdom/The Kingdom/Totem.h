//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The Totem class is an abstract class that will be inherited 
/// by Totem cards, inherits from Card.
///

#pragma once

#include "Card.h"

// *******************************************************************************
/// The Totem class is an abstract class that will be inherited 
/// by Totem cards, inherits from Card.
// *******************************************************************************
class Totem : public Card
{
public:

	Totem(GameDataRef data);

    /// Constructs a Totem object.
    Totem(GameDataRef data, std::string name, std::string description, int cost, int health, bool taunt, char ability, int amount);

	void Init();

    /// Destroys the Totem object.
    ~Totem();

	sf::Int8 getId() override
	{
		return TOTEM_TAUNT_CARD;
	}

	void read(sf::Packet & is);
	sf::Packet write(sf::Packet &os) override;

	/// Gets the Minions curHealth.
	/// \return The Minions curHealth.
	sf::Int8 getCurHealth() override { return curHealth; };

	/// Sets the Minions curHealth.
	void setCurHealth(int healthModifer) override { curHealth += healthModifer; };

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	sf::Int8 getDamage() { return -1; }

	/// Sets the Minions damageValue.
	void setDamage(int damagealue) {}

	/// Gets the Totem's taunt boolean value.
	/// \return The Totem's taunt boolean value.
	bool isTaunt();

	/// Sets the Totem's taunt boolean value.
	void setTaunt(bool newTaunt);

	/// The effect of the Totem card.
	/// \param[in] board The current game board.
	void effect(Board* board);

protected:

    /// ID of the Totem which will determine what effect it has.
    sf::Uint8 ability;

    /// Value used by the effect.
	sf::Int8 amount;

    /// Total health of the Totem.
	sf::Int8 maxHealth;

    /// Current health of the Totem.
	sf::Int8 curHealth;

    /// Determines whether totem has a taunt or not.
    bool taunt;

	void Draw(float dt) override;

	//int getId() 

	sf::Text healthText;
};

