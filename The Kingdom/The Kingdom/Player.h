//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The Player class is an abstract class that will be inherited by 
/// different player type (character) classes.
///

#pragma once

#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "CardFactory.h"
#include "Minion.h"
#include "Game.h"


// *******************************************************************************
/// The Player class is an abstract class that will be inherited by different 
/// player type (character) classes. It contains the player's deck as well as 
/// shows the player what cards are in their hand. This class also shows the 
/// player their health as well as current action points. This class also manages
/// how many actions the player can do.
// *******************************************************************************
class Player
{
public:
	Player();
    /// Creates the Player object and initializes it.
    /// \param[in] name The name of the Player.
	Player(GameDataRef data);
    
	~Player();
    
	void init();

    /// Gets the actionPoints for verifying if a card can be played, and for 
    /// displaying to GUI.
    /// \return The Players actionPoints.
    int getActionPoints();

    /// Sets the Players actionPoints upon the start of a turn and in 
    /// the case of a buff.
    /// \param[in] modify The amount of action points to assign to actionPoints. 
    void setActionPoints(int modify);
    
    /// Gets the health of the Player for the board to verify win conditions, 
    /// and for displaying to GUI.
    int getHealth();

    /// Sets the health of the Player in the case of being healed 
    /// or losing health from an attack.
    /// \param[in] modify The amount of health to assign to the Player.
    void setHealth(int modify);
    
    /// Removes card from deck and puts it in the hand.
    void drawCard();

    /// Removes card from hand and puts it on the Board.
    /// \param[in] card The card to be played.
    Card* playCard(int cardNum);

	bool isSeleting();

	void setSelection(bool isSelecting);
    
    /// Determines the players effect and applies it to the player.
    virtual void effect(Board* board) = 0;	

	void Draw(float dt);

	bool getTurn();

	void setTurn(bool setTurn);

	void setPlayer(bool setPlayer);
	
	/// A vector of Cards currently in the players hand.
    std::vector<Card*> hand;
	
	sf::Sprite _playerSprite;

private:

	bool currentlySelecting = false;

    /// A vector of Cards currently in the players deck.
    std::vector<Card*> deck;

    /// The name of the Player.
    std::string name;

    /// The total number of health points that the player has.
    int health = 30;
    /// The total number of current action points that 
    /// the player has available to use.
    int actionPoints = 2;

	bool myTurn;

protected:
	
	sf::Font font;
	sf::Text healthText;
	sf::Text costTextactionPointText;

	bool isPlayer = true;
	
	GameDataRef _data;

};