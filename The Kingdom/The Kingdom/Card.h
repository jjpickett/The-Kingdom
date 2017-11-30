//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The Card class is an abstraction of any card that can be played on a Board.
///

#pragma once

#include <iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Network.hpp>
#include "DEFINITIONS.h"
#include <string>
#include "Game.h"

// *******************************************************************************
/// The Card class is an abstraction of any card that can be played on a Board.
/// This class provides the Cards name, description, the cost, whether or not the
/// card is asleep, and the filepath to the Cards image.
// *******************************************************************************
class Card
{
public:
	Card();
	
	void Init();

	Card(GameDataRef data);

	Card(GameDataRef data, std::string name, std::string description, int cost);

    /// Destroys the Card object.
    virtual ~Card() {};

    /// Returns the name of the Card.
    /// \return The name of the Card.
    std::string getName();

    /// Returns the description of the Card.
    /// \return The description of the Card.
    std::string getDescription();

    /// Returns the cost of the Card.
    /// \return The cost of the Card.
    int getCost();



	bool isSelected();

	void setSelected(bool selected);

	void setPosition(int x, int y);



	virtual void Draw(float dt) = 0;
	virtual sf::Int8 getId() = 0;

	virtual void read(sf::Packet & is) = 0;
	virtual sf::Packet write(sf::Packet & os) = 0;

	/// Gets the Minions curHealth.
	/// \return The Minions curHealth.
	virtual sf::Int8 getCurHealth() = 0;

	/// Sets the Minions curHealth.
	virtual void setCurHealth(int curHealth) = 0;

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	virtual sf::Int8 getDamage() = 0;

	/// Sets the Minions damageValue.
	virtual void setDamage(int damagealue) = 0;


	sf::Sprite _cardSprite;

protected:

    /// The name of the Card.
    std::string name;

    /// The description of the Card.
    std::string description;

    /// The filepath to the Cards image file.
    sf::String image;
    
    /// The value of action points required to play the Card.
    sf::Int8 cost;

	bool endLine;

    

	bool _selected = false;	

	sf::Font font;
	sf::Text descriptionText;
	sf::Text costText;


	GameDataRef _data;
};
