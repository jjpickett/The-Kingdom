//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The TotemPlayer class is a concrete derived class, inherits from Totem.
///

#pragma once

#include "Totem.h"

// *******************************************************************************
/// The TotemPlayer class is a concrete derived class, inherits from Totem.
/// Applies its effect to the player who controls it.
// *******************************************************************************
class TotemPlayer : public Totem
{
public:

	TotemPlayer(GameDataRef data);
    /// Creates the TotemPlayer object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    TotemPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt);

    /// Destroys the TotemPlayer object.
    ~TotemPlayer();

    /// Determines the player effect and applies it.
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
		return TOTEM_PLAYER_CARD;
	}
};
