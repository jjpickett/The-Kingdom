//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The Minion class is an abstract class that will be inherited by Minion cards, 
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

    /// The default constructor.
	Minion();

    /// Initializes the minion.
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

	/// Sets the card's taunt state.
	void setTaunt(bool state);

	/// Returns whether or not the card is asleep.
	/// \return Whether or not the card is asleep.
	bool isAsleep();
    
    /// Sets the card's sleep state.
    void setAsleep(bool state);

    /// Draws the card data to the screen.
    /// \param[in] dt Delta time (framerate).
	void Draw(float dt) override;

    /// Reading in the card data from a packet.
    /// \param[in] The input packet.
	void read(sf::Packet &is);
	
    /// Writing the card data to the packet.
    /// \param[in] os The outgoing packet.
    /// \return The completed packet.
    sf::Packet & write(sf::Packet &os) override;

    /// Gets the ID of the card.
    /// \return The ID of the card.
	sf::Int8 getId() override
	{
		if (charge == true)
			return MINION_CHARGE_CARD;
		else if (taunt == true)
			return MINION_TAUNT_CARD;
		else
			return MINION_CARD;
	}

    /// Text displayed for a sleeping card.
    sf::Text asleepText;

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

    /// The text which displays the health.
	sf::Text healthText;
	
    /// The text which displays the damage the card can do.
    sf::Text damageText;
	

};

