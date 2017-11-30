//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The TotemFriendly class is a concrete derived class, inherits from Totem.
///

#pragma once

#include "Totem.h"

// *******************************************************************************
/// The TotemFriendly class is a concrete derived class, inherits from Totem.
/// Applies its effect to friendly minions on the board.
// *******************************************************************************
class TotemFriendly : public Totem
{
public:
    
	TotemFriendly(GameDataRef data);
    /// Creates the TotemFriendly object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    TotemFriendly(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt);
    
    /// Destroys the TotemFriendly object.
    ~TotemFriendly();

    /// Determines the friendly effect use and applies it.
    /// \param[in] board The current game board.
    void effect(Board* board);

	void read(sf::Packet & is);
	sf::Packet write(sf::Packet &os) override;

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	sf::Int8 getDamage() { return -1; }

	/// Sets the Minions damageValue.
	void setDamage(int damagealue) {}

	sf::Int8 getId() override
	{
		return TOTEM_FRIENDLY_CARD;
	}

};
