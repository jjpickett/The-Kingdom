/// \file	GenerealFailureTest.cc.
///
/// \brief	Int vector test class
#define private public
#include "GenerealFailureTest.h"
#include <cppunit/extensions/HelperMacros.h>

/// \fn	void GenerealFailureTest::setUp()
///
/// \brief	Sets the up
///
/// \author	Jordan Pickett
/// \date	11/2/2017

void GenerealFailureTest::setUp() 
{
	//Instantiate our variables
    mage = new Mage();
    warrior = new Warrior();
    shaman = new Shaman();
    server = new Server(); //Creates our server
	clientHost = new Client(); //Creates a client for the host
	clientOpponent = new Client(); //Creates a client as an opponent
	clientBoard = new Board();
	hostBoard = new Board();
	minion1 = new Minion();
	minion2 = new Minion();
	card = new Card();
}

/// \fn	void GenerealFailureTest::tearDown()
///
/// \brief	Tear down
///
/// \author	Jordan Pickett, Matthew Rose
/// \date	11/9/2017

void GenerealFailureTest::tearDown() {
	//Delete our variables
    delete mage;
    delete warrior;
    delete shaman;
	delete clientHost;
	delete clientServer;
	delete server;
	delete clientBoard;
	delete hostBoard;
	delete minion1;
	delete minion2;
	delete card;
}

/// \fn	void GenerealFailureTest::testPlayer()
///
/// \brief	Tests player
///
/// \author	Jordan Pickett, Matthew Rose
/// \date	11/9/2017

void GenerealFailureTest::testPlayer() 
{
	// TestGetHealth: Returns health attribute and asserts a value to ensure that it is returning the correct value.
	CPPUNIT_ASSERT(mage->getHealth() == 30);
	
	// TestSetHealth: Modifies health attribute and asserts the health value to ensure modification is correct.
	mage->setHealth(10);
	CPPUNIT_ASSERT(mage->getHealth() == 10);

	// TestGetActionPoints : Returns actionPoints attribute and asserts a value to ensure that it is returning the correct value.
	CPPUNIT_ASSERT(mage->getActionPoints() == 3);
	
	// TestSetActionPoints: Modifies actionPoints attribute and asserts the actionPoint value to ensure modification is correct.
	mage->setActionPoints(10);
	CPPUNIT_ASSERT(mage->getActionPoints() == 10);

	// TestDrawCard: Call the drawCard function and assert that a card was added to the vector<Card> hand and that a card was removed from vector<Card> deck.
	int deckSize = mage->deck.size();
	int originalHandSize = mage->hand.size();
	mage->drawCard();
	CPPUNIT_ASSERT(mage->deck.size() == deckSize - 1 && mage->hand.size() == originalHandSize + 1);

	// TestPlayCard : Call the playCard function and assert that a card was removed from vector<Card> hand and is passed to the board.
	Card card = mage->hand.at(0);
	mage->playCard(card);
	CPPUNIT_ASSERT(mage->hand.size() == originalHandSize && hostBoard->hostPlayersCardsInPlay.at(0) === card);

	// TestWarriorEffect: Call the warrior effect function and assert that two actionPoints are spent and shield is updated with two points.
	int originalActionPoints = warrior->actionPoints;
	warrior->effect();
	CPPUNIT_ASSERT(warrior->actionPoints == originalActionPoints - 2 && sheild == 2);

	// TestNotEnoughStamina : Call the warrior effect function and assert that two actionPoints arenít spent if there isnít enough actionPoints available and that shield isnít updated with two points.
	warrior->actionPoints = 1;
	warrior->effect();
	CPPUNIT_ASSERT(warrior->actionPoints == 1 && sheild == 2);

	// TestMageEffect: Call the mage effect function and assert that two actionPoints are spent and a target can be selected then check the selected cards health value to ensure that its updated correctly.
	int opponentHealth = hostBoard->guestPlayer->getHealth();
	originalActionPoints = mage->actionPoints;
	mage->effect();
	CPPUNIT_ASSERT(mage->actionPoints == originalActionPoints - 2 && hostBoard->guestPlayer->getHealth() == opponentHealth - 2);

	// TestNotEnoughStamina : Call the mage effect function and assert that two actionPoints arenít spent if there isnít enough actionPoints available and that targets health value hasnít changed.
	mage->actionPoints = 1;
	mage->effect();
	CPPUNIT_ASSERT(mage->actionPoints == 1);

    // TestShamanEffect: Call the shaman effect function and assert that two actionPoints are spent and a totem card is placed on the board.
	int cardsInPlay = hostBoard->hostPlayersCardsInPlay->size();
	originalActionPoints = shaman->actionPoints;
	shaman->effect();
	CPPUNIT_ASSERT(shaman->actionPoints == originalActionPoints - 2 && hostBoard->hostPlayersCardsInPlay.size() == cardsInPlay + 1);

	// TestNotEnoughtStamina : Call the shaman effect function and assert that two actionPoints arenít spent and that a totem card isnít placed onto the board.
	shaman->actionPoints = 1;
	shaman->effect();
	CPPUNIT_ASSERT(shaman->actionPoints == 1 && hostBoard->hostPlayersCardsInPlay.size() == cardsInPlay + 1);

}

/// \fn	void GenerealFailureTest::testCard()
///
/// \brief	Tests card
///
/// \author	Jordan Pickett
/// \date	11/2/2017

void GenerealFailureTest::testCard() {
	//Check to see that the get name is working
	CPPUNIT_ASSERT(card->getName() == card->name);

	//Check to see that the get description is working
	CPPUNIT_ASSERT(card->getDescription() == card->description);

	//Check to see that the get cost is working
	CPPUNIT_ASSERT(card->getCost() == card->cost);

	//Check to see that isAsleep is working
	CPPUNIT_ASSERT(card->isAsleep() == card->asleep);

}
/// \fn	void GenerealFailureTest::testBoard()
///
/// \brief	Tests board
///
/// \author	Jordan Pickett
/// \date	11/2/2017

void GenerealFailureTest::testBoard() {

	//This will return false after the search for the player has timed out
	CPPUNIT_ASSERT(hostBoard->searchForPlayer() == false);

	hostBoard->searchForPlayer();

	//This will return true after the host and client have found eachother
	CPPUNIT_ASSERT(clientBoard->searchForPlayer());

	//The host always starts first
	CPPUNIT_ASSERT(hostBoard->isMyTurn());

	//The client always starts second
	CPPUNIT_ASSERT(clientBoard->isMyTurn() == false);

	clientBoard->checkWinConditions();
	
	//The win conditions wont trigger because the health's are above 0
	CPPUNIT_ASSERT((mage->getHealth() > 0)&&(shaman->getHealth() > 0));

	mage->play(minion1);
	mage->play(minion2);

	hostBoard->update();
	//Since the cards are in play, this should not equal
	//the clients board
	CPPUNIT_ASSERT(hostBoard != clientBoard);


	//This sets the minions so that one will be destroyed.
	minion1->setHealth(1);
	minion1->setDamage(1); 
	minion2->setHealth(5);
	minion2->setDamage(5); 

	hostBoard->attack(minion2, minion1);

	//This will show that after getting attacked the minion
	//that was weaker will get destroyed
	CPPUNIT_ASSERT(minion1 == NULL);

	minion2 = new Minion();
	mage->play(minion2);

	//Returns true since there is minion on the board with a taunt
	CPPUNIT_ASSERT(hostBoard->checkTaunts() == false);

	minion2->taunt = true;

	//Returns true since there is now a minion on the board that has a taunt
	CPPUNIT_ASSERT(hostBoard->checkTaunts());

	hostBoard->endTurn();

	//Checks to see that the turn has been properly changed.
	CPPUNIT_ASSERT(hostBoard->isMyTurn() == false)
}

/// \fn	void GenerealFailureTest::testClientServer()
///
/// \brief	Tests clientServer
///
/// \author	Jordan Pickett
/// \date	11/2/2017

void GenerealFailureTest::testClientServer() {
	mage->play(card);
	clientHost.updateBoard(hostBoard);

	//Checks to see if the board has been changed properly by checking
	//it against the board before the card was drawn.
	CPPUNIT_ASSERT(hostBoard != clientBoard);
	
	//This checks whether the update has been sent or not
	CPPUNIT_ASSERT(clientHost->sendUpdate());

	//Checks to see that the boards are the same after the update has been sent
	CPPUNIT_ASSERT(hostBoard == clientBoard);

	//This checks to see if the server has gotten the
	//update from the client. Returns true if it has
	//been recieved. False if it hasn't
	CPPUNIT_ASSERT(server->listen());
}