//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The MagicBoard class is a concrete derived class, inherits from Magic.
///

#pragma once

#include "Magic.h"

// *******************************************************************************
/// The MagicBoard class is a concrete derived class, inherits from Magic. 
/// Applies its effect to minions on the board then is discarded.
// *******************************************************************************
class MagicBoard : public Magic
{
public:

	MagicBoard(GameDataRef data);
    /// Creates the MagicBoard object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    MagicBoard(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);
    
    /// Destroys the MagicBoard object.
    ~MagicBoard();

    /// Determines the board effect and applies it to the Board. 
    /// \param[in] board The current game board.
	void effect(Board* board);

	/// Gets the Minions curHealth.
	/// \return The Minions curHealth.
	virtual sf::Int8 getCurHealth() { return -1; };

	/// Sets the Minions curHealth.
	virtual void setCurHealth(int curHealth) {};

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	virtual sf::Int8 getDamage() { return -1; };

	/// Sets the Minions damageValue.
	virtual void setDamage(int damageValue) {};

	sf::Int8 getId() override
	{
		return MAGIC_BOARD_CARD;
	}

	void read(sf::Packet & is) override;
	sf::Packet write(sf::Packet & os) override;
};
