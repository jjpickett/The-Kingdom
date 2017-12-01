//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// The Totem class is an abstract class that will be inherited 
/// by Totem cards, inherits from Card.
///

#pragma once

#include "Card.h"

// *******************************************************************************
/// The Totem class is an abstract class that will be inherited 
/// by Totem cards, inherits from Card.
// *******************************************************************************
class Totem : public Card
{
public:

	/// Creates the Totem object and initializes it.
	/// \param[in] data The structure of game data.
	Totem(GameDataRef data);

    /// Constructs a Totem object.
	/// \param[in] data The structure of game data.
	/// \param[in] name The name of the card.
	/// \param[in] description The description of the card.
	/// \param[in] cost The amount of action points required to play the card.
	/// \param[in] ability The char that is related to which type of ability the card does.
	/// \param[in] taunt A boolean of whether a taunt is active on this card.
	/// \param[in] health The amount of health that the card has.
	/// \param[in] amount The value to be used by the effect.
    Totem(GameDataRef data, std::string name, std::string description, int cost, char ability, bool taunt, int health, int amount);

	/// Initializes the cards
	void Init();

    /// Destroys the Totem object.
    ~Totem();

	/// Reading in the card data from a packet.
	/// \param[in] The input packet.
	void read(sf::Packet & is);

	/// Writing the card data to the packet.
	/// \param[in] os The outgoing packet.
	/// \return The completed packet.
	sf::Packet write(sf::Packet &os) override;

	/// Gets the Totem's curHealth.
	/// \return The Totem's curHealth.
	sf::Int8 getCurHealth() override { return curHealth; };

	/// Sets the Totem's curHealth.
	/// \param[in] healthModifier The amount the health will be modified.
	void setCurHealth(int healthModifer) override { curHealth += healthModifer; };

	/// Gets the Totem's damageValue.
	/// \return The Totem's damageValue.
	sf::Int8 getDamage() { return -1; }

	/// Sets the Totem's damageValue.
	/// \param[in] damageValue The amount the damageValue will be modified.
	void setDamage(int damagealue) {}

	/// Gets the Totem's taunt boolean value.
	/// \return The Totem's taunt boolean value.
	bool isTaunt();

	/// Sets the Totem's taunt boolean value.
	/// \param[in] newTaunt Sets the taunt as active or inactive.
	void setTaunt(bool newTaunt);

	/// The effect of the Totem card.
	/// \param[in] board The current game board.
	void effect(Board* board);

	/// Gets the ID of the card
	/// \return The ID of the card
	sf::Int8 getId() override
	{
		return TOTEM_TAUNT_CARD;
	}

protected:

    /// ID of the Totem which will determine what effect it has.
    sf::Uint8 ability;

    /// Value used by the effect.
	sf::Int8 amount;

    /// Total health of the Totem.
	sf::Int8 maxHealth;

    /// Current health of the Totem.
	sf::Int8 curHealth;

    /// Determines whether Totem has a taunt or not.
    bool taunt;

	/// Draws the card data to the screen.
	/// \param[in] dt Delta time (framerate).
	void Draw(float dt) override;

	//int getId() 

	/// The text that is displayed to the UI.
	sf::Text healthText;
};

