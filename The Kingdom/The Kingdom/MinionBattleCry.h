//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The MinionBattleCry class is a concrete derived class, inherits from Minion. 
///

#pragma once

#include "Minion.h"

// *******************************************************************************
/// The MinionBattleCry class is a concrete derived class, inherits from Minion.
/// Applies an effect upon play of card.
// *******************************************************************************
class MinionBattleCry : public Minion
{
public:
    
	MinionBattleCry(GameDataRef data);
    /// Creates the MinionBattleCry object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    MinionBattleCry(GameDataRef data, std::string name, std::string description, int cost, int health, int attack, bool taunt, bool charge, char ability, int amount);

    /// Destroys the MinionBattleCry object.
    ~MinionBattleCry();

	void read(sf::Packet & is);
	sf::Packet write(sf::Packet &os) override;

    /// Determines which battlecry effect to be used and applies the effect.
    /// \param[in] board The current game board.
    virtual void effect();
	sf::Int8 getId() override
	{
		return MINION_BATTLECRY_CARD;
	}
};

