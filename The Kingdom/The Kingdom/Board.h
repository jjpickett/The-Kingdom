#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Shaman.h"
#include "MyPacket.h"


class Board : public State

{
public:
	Board(GameDataRef data);
	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);


	/// Checks the win conditions to see if any player has less than 0 health points.
	void checkWinConditions();

	/// Lets a Card attack another Card.
	/// \param[in] card1 The attacking Card.
	/// \param[in] card2 The Card being attacked.
	void attack(Card* card1, Card* card2);

	/// Cycles through all opponent's cards in play.
	/// \return If there are taunts on the board.
	bool checkTaunts();

	/// Updates the board and removes cards that have a health less than 0.
	void update();

	/// Ends the current players turn, locks their Cards, and then begins the
	/// turn for the next player and unlocks their Cards.
	void endTurn();

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::Sprite _border;


	/// The cards that the hostPlayer has in play.
	std::vector<Card*> hostPlayersCardsInPlay;

	/// The cards that the guestPlayer has in play.
	std::vector<Card*> guestPlayersCardsInPlay;

	/// True or false value used for verifying the turn order.
	bool hostPlayerTurn;

	Player* hostPlayer = NULL;
	Player* guestPlayer = NULL;
	
	std::vector<sf::Sprite*> guestPlayerInHand;

	int gameState;

	std::string msgSend;

	sf::Mutex globalMutex;

};

