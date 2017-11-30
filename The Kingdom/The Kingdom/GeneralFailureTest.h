/// \file	GenerealFailureTest.h.
///
/// \brief	Declares the int vector test class

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Board.h"
#include "Card.h"
#include "Client.h"
#include "Mage.h"
#include "Magic.h"
#include "MagicBoard.h"
#include "MagicMinion.h"
#include "MagicPlayer.h"
#include "MagicSummon.h"
#include "Minion.h"
#include "MinionBattleCry.h"
#include "Player.h"
#include "Server.h"
#include "Shaman.h"
#include "Totem.h"
#include "TotemBoard.h"
#include "TotemFriendly.h"
#include "TotemPlayer.h"
#include "Warrior.h"


/// \class	GenerealFailureTest
///
/// \brief	A GeneralFailure test.
///
/// \author	Jordan Pickett
/// \date	11/2/2017

class GenerealFailureTest : public CppUnit::TestFixture {

	/// \fn	GenerealFailureTest::CPPUNIT_TEST_SUITE(GenerealFailureTest);
	///
	/// \brief	Copy constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017
	///
	/// \param	parameter1	The first parameter.

	CPPUNIT_TEST_SUITE(GenerealFailureTest);

	/// \fn	GenerealFailureTest::CPPUNIT_TEST(testPlayer);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017
	///
	/// \param	parameter1	The first parameter.

	CPPUNIT_TEST(testPlayer);

	/// \fn	GenerealFailureTest::CPPUNIT_TEST(testCard);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017
	///
	/// \param	parameter1	The first parameter.

	CPPUNIT_TEST(testCard);

	/// \fn	GenerealFailureTest::CPPUNIT_TEST(testBoard);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017
	///
	/// \param	parameter1	The first parameter.

	CPPUNIT_TEST(testBoard);

	/// \fn	GenerealFailureTest::CPPUNIT_TEST(testClientServer);
	///
	/// \brief	Constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017
	///
	/// \param	parameter1	The first parameter.

	CPPUNIT_TEST(testClientServer);

	/// \fn	GenerealFailureTest::CPPUNIT_TEST_SUITE_END();
	///
	/// \brief	Default constructor
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	CPPUNIT_TEST_SUITE_END();

public:

	/// \fn	void GenerealFailureTest::setUp();
	///
	/// \brief	Sets the up
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void setUp();

	/// \fn	void GenerealFailureTest::tearDown();
	///
	/// \brief	Tear down
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void tearDown();

	/// \fn	void GenerealFailureTest::testPlayer();
	///
	/// \brief	Tests player
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void testPlayer();

	/// \fn	void GenerealFailureTest::testCard();
	///
	/// \brief	Tests card
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void testCard();

	/// \fn	void GenerealFailureTest::testBoard()
	///
	/// \brief	Tests board
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void testBoard();

	/// \fn	void GenerealFailureTest::testClientServer()
	///
	/// \brief	Tests clientServer
	///
	/// \author	Jordan Pickett
	/// \date	11/2/2017

	void testClientServer();

private:
	//Declare our variables for the testing
    Mage* mage;
    Warrior* warrior;
    Shaman* shaman;
	Card* card;
	Client* clientHost;
	Client* clientServer;
	Server* server;
	Board* clientBoard;
	Board* hostBoard;
	Minion* minion1;
	Minion* minion2;
};