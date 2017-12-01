//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The MagicPlayer class is a concrete derived class, inherits from Magic.
///

#pragma once

#include "Magic.h"

// *******************************************************************************
/// The MagicMinion class is a concrete derived class, inherits from Magic.
/// Applies its effect to friendly minions on the board then is discarded.
// *******************************************************************************
class MagicPlayer : public Magic
{
public:

	/// \fn	MagicPlayer::MagicPlayer(GameDataRef data);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	The data.

	MagicPlayer(GameDataRef data);
    /// Creates a MagicPlayer object.
    MagicPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);

    /// Destroys the MagicPlayer object.
    ~MagicPlayer();

    /// Determines the player effect and applies it.
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
		return MAGIC_PLAYER_CARD;
	}
	
	void read(sf::Packet & is) override;
	sf::Packet write(sf::Packet & os) override;
};

