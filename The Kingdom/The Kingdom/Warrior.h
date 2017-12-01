//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// The Warrior class is a concrete derived class, which inherits from Player. 
///

#pragma once

#include "Player.h"

// *******************************************************************************
/// The Warrior class is a concrete derived class, which inherits from Player. 
/// It applies an effect when the Player decides to use the effect.
// *******************************************************************************
class Warrior : public Player 
{
public:

	Warrior();

	/// Constructs a Warrior object.
    Warrior(GameDataRef data);

	/// Destroys the Warrior object.
    ~Warrior();

	/// Applies the effect of spending 2 stamina points to gain 2 points toward 
	/// its shield.
    void effect(Board* board) override;

private:

    /// An additional health bonus. When the opponent attacks a Warrior, 
    /// the shield is hit first. The health will only deplete if the shield 
    /// is at 0.
    int shield;

};