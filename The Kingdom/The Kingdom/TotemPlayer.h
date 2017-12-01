//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
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

	/// Creates the TotemPlayer object and initializes it.
	/// \param[in] data The structure of game data.
	TotemPlayer(GameDataRef data);

	/// Creates the TotemPlayer object and initializes it.
	/// \param[in] data The structure of game data.
	/// \param[in] name The name of the card.
	/// \param[in] description The description of the card.
	/// \param[in] cost The amount of action points required to play the card.
	/// \param[in] ability The char that is related to which type of ability the card does.
	/// \param[in] amount The value to be used by the effect.
	/// \param[in] health The amount of health that the card has.
	/// \param[in] taunt A boolean of whether a taunt is active on this card.
    TotemPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt);

	/// Destroys the TotemPlayer object.
    ~TotemPlayer();

	/// Determines the player effect and applies it.
	/// \param[in] board The current game board.
    void effect(Board* board);

	/// Reading in the card data from a packet.
	/// \param[in] The input packet.
	void read(sf::Packet & is);

	/// Writing the card data to the packet.
	/// \param[in] os The outgoing packet.
	/// \return The completed packet
	sf::Packet & write(sf::Packet &os) override;

	/// Gets the TotemPlayer's damageValue.
	/// \return The TotemPlayer's damageValue.
	sf::Int8 getDamage() { return -1; }

	/// Sets the TotemPlayer's damageValue.
	/// \param[in] damagealue The amount of damage that the Totem delivers
	void setDamage(int damagealue) {}

	/// Gets the ID of the card
	/// \return The ID of the card
	sf::Int8 getId() override
	{
		return TOTEM_PLAYER_CARD;
	}
};
