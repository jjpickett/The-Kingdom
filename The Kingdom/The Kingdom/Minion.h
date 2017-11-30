//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The Minion class is an abstract class that will be inherited by Minion cards, 
/// inherits from Card.
///

#pragma once

#include "Card.h"
#include "Game.h"

// *******************************************************************************
/// The Minion class is an abstract class that will be inherited by Minion cards, 
/// inherits from Card.
// *******************************************************************************
class Minion : public Card
{
public:

	Minion();

	void Init();

	Minion(GameDataRef data);
	/// Constructs a Minion object.
    /// \param[in] health The health of the card.
    /// \param[in] attack The attack damage of the card.
    /// \param[in] taunt Determines whether card has taunt or not.
    /// \param[in] charge Determines whether card has charge or not.
	Minion(GameDataRef data, std::string name, std::string description, int cost, int health, int attack, bool taunt, bool charge);

    /// Destroys the Minion object.
    ~Minion();

    /// The effect of the Minion card.
    /// \param[in] board The current game board.
	void effect(Board* board) {}

    /// Gets the Minions curHealth.
    /// \return The Minions curHealth.
	sf::Int8 getCurHealth() override { return curHealth;  };

    /// Sets the Minions curHealth.
	void setCurHealth(int healthModifer) override { curHealth += healthModifer; };
    
    /// Gets the Minions damageValue.
    /// \return The Minions damageValue.
	sf::Int8 getDamage();
    
    /// Sets the Minions damageValue.
    void setDamage(int damageValue);

    /// Gets the Minions taunt boolean value.
    /// \return The Minions taunt boolean value.
    bool isTaunt();

	/// Returns whether or not the card is asleep.
	/// \return Whether or not the card is asleep.
	bool isAsleep();

	void Draw(float dt) override;

	void read(sf::Packet &is);
	sf::Packet write(sf::Packet &os) override;

	sf::Int8 getId() override
	{
		if (charge == true)
			return MINION_CHARGE_CARD;
		else if (taunt == true)
			return MINION_TAUNT_CARD;
		else
			return MINION_CARD;
	}

protected:

    /// ID of the Minion which will determine what effect it has.
    sf::Uint8 ability;

	/// Value used by the effect.
	sf::Int8 amount;

    /// Total health of the Minion.
	sf::Int8 maxHealth;

    /// Current health of the Minion.
	sf::Int8 curHealth;

    /// Attack damage of the Minion.
	sf::Int8 damageValue;
    
	bool charge;

    /// Determines whether the Minion has taunt or not.
    bool taunt;

	/// Whether or not the Card is asleep.
	bool asleep;

	sf::Text healthText;
	sf::Text damageText;
	sf::Text asleepText;

};

