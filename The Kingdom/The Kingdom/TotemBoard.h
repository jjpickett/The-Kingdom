//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The TotemBoard class is a concrete derived class, inherits from Totem.
///

#pragma once

#include "Totem.h"

// *******************************************************************************
/// The TotemBoard class is a concrete derived class, inherits from Totem.
/// Applies its effect to minions on the board.
// *******************************************************************************
class TotemBoard : public Totem
{
public:
    
	TotemBoard(GameDataRef data);
    /// Creates the TotemBoard object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    TotemBoard(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount, int health, bool taunt);
    
    /// Destroys the TotemBoard object.
    ~TotemBoard();

    /// Determines the board effect and applies it to the Board. 
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
		return TOTEM_BOARD_CARD;
	}

};

