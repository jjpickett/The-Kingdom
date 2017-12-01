//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The MinionFriendly class is a concrete derived class, inherits from Minion. 
///

#pragma once

#include "Minion.h"

// *******************************************************************************
/// The MinionFriendly class is a concrete derived class, inherits from Minion.
/// Applies an effect that improves friendly minions on board.
// *******************************************************************************
class MinionFriendly : public Minion
{
public:

	MinionFriendly(GameDataRef data);
    /// Creates the MinionFriendly object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    MinionFriendly(GameDataRef data, std::string name, std::string description, int cost, int health, int attack, bool taunt, bool charge, char ability, int amount);

    /// Destroys the MinionFriendly object.
    ~MinionFriendly();

	void read(sf::Packet & is);
	sf::Packet write(sf::Packet &os) override;

    /// Determines which friendly effect to be used and applies the effect.
    /// \param[in] board The current game board.
	void effect(Board* board);

	sf::Int8 getId() override
	{
		return MINION_FRIENDLY_CARD;
	}
};

