//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
/// \brief The Shaman class is a concrete derived class, inherits from Player.
///


#pragma once

#include "Player.h"

// *******************************************************************************
/// The Shaman class is a concrete derived class, inherits from Player.
// *******************************************************************************
class Shaman : public Player
{
public:
    
    /// Constructs a Shaman object.
    Shaman();

    /// Constructs a Shaman object with GameDataRef data.
    /// \param data Contains Game Meta-Data.
	Shaman(GameDataRef data);

    /// Destroys the Shaman object.
    ~Shaman();

    /// Applies the effect of spending 2 stamina points to gain a 
    /// Totem card to their cards in play.
    void effect(Board* board);

};