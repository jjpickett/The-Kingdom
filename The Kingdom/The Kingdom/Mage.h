//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Oct 26, 2017
///
///
/// \brief The Mage class is a concrete derived class, which inherits from Player. 
///

#pragma once

#include "Player.h"

// *******************************************************************************
/// The Mage class is a concrete derived class, which inherits from Player. 
/// It applies an effect when the Player decides to use the effect.
// *******************************************************************************
class Mage : public Player
{
public:

    /// Constructs a Mage object.
    Mage();

    /// Creates a mage object with GameDataRef.
    /// \param data Contains Game Meta - Data.
	Mage(GameDataRef data);

    /// Destroys the Mage object.
    ~Mage();

    /// Applies the effect of spending 2 stamina points to gain the ability to 
    /// shoot a fireball at any target that is in play. Once the target is hit, 
    /// it receives two damage.
    void effect(Board* board) override;

};

