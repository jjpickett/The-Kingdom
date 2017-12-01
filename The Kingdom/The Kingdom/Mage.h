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

    /// \fn	Mage::Mage();
    ///
    /// \brief	Constructs a Mage object.
    ///
    /// \author	Jordan Pickett
    /// \date	11/30/2017

    Mage();

	/// \fn	Mage::Mage(GameDataRef data);
	///
	/// \brief	Creates a mage object with GameDataRef.
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	data	Contains Game Meta - Data.

	Mage(GameDataRef data);

    /// \fn	Mage::~Mage();
    ///
    /// \brief	Destroys the Mage object.
    ///
    /// \author	Jordan Pickett
    /// \date	11/30/2017

    ~Mage();

    /// Applies the effect of spending 2 stamina points to gain the ability to 
    /// shoot a fireball at any target that is in play. Once the target is hit, 
    /// it receives two damage.
    void effect(Board* board) override;

};

