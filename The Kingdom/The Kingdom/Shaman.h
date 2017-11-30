//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
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
	Shaman(GameDataRef data);

    /// Destroys the Shaman object.
    ~Shaman();

    /// Applies the effect of spending 2 stamina points to gain a 
    /// Totem card to their cards in play.
    void effect(Board* board);

};