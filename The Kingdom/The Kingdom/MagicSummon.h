//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The MagicSummon class is a concrete derived class, inherits from Magic.
///

#pragma once

#include "Magic.h"

// *******************************************************************************
/// The MagicSummon class is a concrete derived class, inherits from Magic.
/// Summons a minion to the field then is discarded.
// *******************************************************************************
class MagicSummon : public Magic
{
public:

	/// \fn	MagicSummon::MagicSummon(GameDataRef data);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	The data.

	MagicSummon(GameDataRef data);
    /// Creates the MagicSummon object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    MagicSummon(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);

    /// Destroys the MagicSummon object.
    ~MagicSummon();
    
    /// Determines which summon effect to be used and applies the effect.
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
	virtual void setDamage(int damagealue) {};

	sf::Int8 getId() override
	{
		return MAGIC_SUMMON_CARD;
	}

	void read(sf::Packet & is) override;
	sf::Packet write(sf::Packet & os) override;
};

