//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The Magic class is an abstract class that will be inherited by Magic cards, 
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
    /// Constructs a Magic object with GameDataRef data.
    /// \param data Contains Game Meta-Data.
	Magic(GameDataRef data);
	/// Constructs a Magic object.
	Magic(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);

	/// Destroys the Magic object.
	~Magic();

	/// The effect of the Magic card.
	/// \param[in] board The current game board.
	virtual void effect(Board* board) = 0;

    /// Draws the sprite to the screen.
    /// \param dt Delta-Time (frames per second)
	void Draw(float dt) override { Card::Draw(dt); }
	
    /// Writes the contents of the output stream to a Packet.
    /// \param The output stream to send as a packet.
    /// \return A packet to send across the network.
    virtual sf::Packet write(sf::Packet & os) = 0;
	
    /// Returns the ID of the card.
	virtual sf::Int8 getId() = 0;

	/// Gets the Minions curHealth.
	/// \return The current health.
	virtual sf::Int8 getCurHealth() = 0;

	/// Sets the Minions curHealth.
    /// \param curHealth The health to set the player's health to.
	virtual void setCurHealth(int curHealth) = 0;

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	virtual sf::Int8 getDamage() = 0;

	/// Sets the damage value.
    /// \param The value to set the damage to.
	virtual void setDamage(int damageValue) = 0;

protected:

	/// \brief ID of the card which will determine what effect it has.
	sf::Uint8 ability;

	/// \brief The amount
	sf::Int8 amount;
};

