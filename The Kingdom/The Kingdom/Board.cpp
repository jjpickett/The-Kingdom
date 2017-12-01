#include "Board.h"
#include "Card.h"

Board::Board(GameDataRef data) : _data(data)
{

}

void Board::Init()
{
	gameState = STATE_PLAYING;

	//LOAD GAME BACKGROUND
	this->_data->assets.LoadTexture("GameBackground", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("GameBorder", GAME_BORDER_FILEPATH);

	//LOAD PLAYER IMAGES
	this->_data->assets.LoadTexture("Shaman", SHAMAN_FILEPATH);
	this->_data->assets.LoadTexture("Mage", MAGE_FILEPATH);
	this->_data->assets.LoadTexture("Warrior", WARRIOR_FILEPATH);

	//LOAD CARD IMAGES
	this->_data->assets.LoadTexture("Minion", MINION_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MinionTaunt", MINION_TAUNT_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MinionCharge", MINION_CHARGE_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MinionBattlecry", MINION_BATTLECRY_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MinionFriendly", MINION_FRIENDLY_CARD_FILEPATH);

	this->_data->assets.LoadTexture("MagicPlayer", MAGIC_PLAYER_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MagicSummon", MAGIC_SUMMON_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MagicBoard", MAGIC_BOARD_CARD_FILEPATH);
	this->_data->assets.LoadTexture("MagicMinion", MAGIC_MINION_CARD_FILEPATH);

	this->_data->assets.LoadTexture("TotemTaunt", TOTEM_TAUNT_CARD_FILEPATH);
	this->_data->assets.LoadTexture("TotemFriendly", TOTEM_FRIENDLY_CARD_FILEPATH);
	this->_data->assets.LoadTexture("TotemPlayer", TOTEM_PLAYER_CARD_FILEPATH);
	this->_data->assets.LoadTexture("TotemBoard", TOTEM_BOARD_CARD_FILEPATH);

	this->_data->assets.LoadTexture("CardBack", CARD_BACK_FILEPATH);

	//SET THE PLAYER TO THEIR CHARACTER
	if (this->_data->player == MAGE_CHARACTER)
	{
		hostPlayer = new Mage(this->_data);
	}
	else if (this->_data->player == SHAMAN_CHARACTER)
	{
		hostPlayer = new Shaman(this->_data);
	}
	else if (this->_data->player == WARRIOR_CHARACTER)
	{
		hostPlayer = new Warrior(this->_data);
	}

	//ENSURE WHO STARTS
	hostPlayer->setTurn(this->_data->myTurn);
	//INITIALIZE THE PLAYER
	hostPlayer->init();

	//SEND YOUR PLAYER DATA TO OPPONENT
	sf::Packet packet;
	MyPacket myPacket;

	packet << this->_data->player;
	this->_data->socket.send(packet);

	//CLEAR PACKET AND RECEIVE PLAYER DATA FROM OPPONENT

	this->_data->socket.setBlocking(true);
	this->_data->socket.receive(packet);
	guestPlayer = myPacket.initOpponent(packet, _data);

	//CLEAR PACKET AND RECEIVE INITIAL HAND DATA FROM OPPONENT
	packet.clear();
	packet << this->hostPlayer->hand.size();
	this->_data->socket.send(packet);
	this->_data->socket.receive(packet);

	guestPlayerInHand = myPacket.receiveHandPacket(packet, this->_data);

	this->_data->socket.setBlocking(false);

	guestPlayer->setPlayer(false);

	//SET BG TEXTURE
	this->_background.setTexture(this->_data->assets.getTexture("GameBackground"));
	this->_border.setTexture(this->_data->assets.getTexture("GameBorder"));

}

void Board::HandleInput()
{
	sf::Event event;
	sf::Packet packet;
	MyPacket packetSend;

	//EVENT HANDLER FOR GAME
	while (this->_data->window.pollEvent(event))
	{
		//DESTROY EVERYTHING WHEN THE GAME CLOSES
		if (sf::Event::Closed == event.type)
		{

			this->_data->socket.disconnect();
			this->_data->listener.close();
			this->_data->window.close();
		}

		//IF ITS YOUR TURN, THEN ALLOW ACTIONS
		if (hostPlayer->getTurn())
		{
			if (event.key.code == sf::Keyboard::E)
			{
				hostPlayer->setTurn(false);
				std::cout << "End Turn. " << std::endl;

				globalMutex.lock();
				this->_data->socket.send(packetSend.sendTurn(true));
				globalMutex.unlock();
			}

			//This is temporary. Delete when done
			if (event.key.code == sf::Keyboard::Q)
			{
				hostPlayer->drawCard();
			}

			//TODO: Clean this up
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int x = 0; x < this->hostPlayer->hand.size(); x++)
				{
					if (this->_data->input.isSpriteClicked(this->hostPlayer->hand.at(x)->_cardSprite, sf::Mouse::Left, this->_data->window) && !hostPlayer->isSeleting()) {
						this->hostPlayer->hand.at(x)->setSelected(true);
						this->hostPlayer->setSelection(true);
					}
				}
				for (int x = 0; x < this->hostPlayersCardsInPlay.size(); x++)
				{
					if (this->_data->input.isSpriteClicked(this->hostPlayersCardsInPlay.at(x)->_cardSprite, sf::Mouse::Left, this->_data->window) && !hostPlayer->isSeleting()) {
						this->hostPlayersCardsInPlay.at(x)->setSelected(true);
						this->hostPlayer->setSelection(true);
						std::cout << "Host Id: " << this->hostPlayersCardsInPlay.at(x) << std::endl;
					}
				}
			}

			//JUST COMPLETED THIS! SHOW CADS IN PLAY NEXT
			if (event.type == sf::Event::MouseButtonReleased)
			{
				for (int x = 0; x < this->hostPlayer->hand.size(); x++)
				{
					//THIS PUTS THE CARD INTO PLAY
					if (this->hostPlayer->hand.at(x)->isSelected() && sf::Mouse::getPosition(this->_data->window).y < SCREEN_HEIGHT / 2) 
                    {
						this->hostPlayer->hand.at(x)->setSelected(false);
						this->hostPlayer->setSelection(false);

                        if (this->hostPlayer->hand.at(x)->getId() == MINION_BATTLECRY_CARD)
                        {
                            this->hostPlayer->hand.at(x)->effect(this);
                        }
						
                        this->hostPlayersCardsInPlay.push_back(this->hostPlayer->playCard(x));
                        
						std::cout << "Cards in Play Now: " << hostPlayersCardsInPlay.size() << std::endl;
						packet = packetSend.sendHandPacket(this->hostPlayer->hand);

						globalMutex.lock();
						this->_data->socket.send(packet);
						globalMutex.unlock();

						packet.clear();
						packet = packetSend.sendPlayersCardsInPlay(hostPlayersCardsInPlay);

						globalMutex.lock();
						this->_data->socket.send(packet);
						globalMutex.unlock();


					}
					//THIS PUTS THE CARD BACK IN THE DECK
					else if (this->hostPlayer->hand.at(x)->isSelected() && sf::Mouse::getPosition(this->_data->window).y > SCREEN_HEIGHT / 2) {
						this->hostPlayer->hand.at(x)->setSelected(false);
						this->hostPlayer->setSelection(false);

					}
				}
				//Checks if there is collision with other objects
				for (int x = 0; x < this->hostPlayersCardsInPlay.size(); x++)
				{
					//THIS CHECKS WHICH CARD IS BEING PLAYER
					if (hostPlayersCardsInPlay.at(x)->isSelected()) 
					{
						//CHECKS FOR COLLISION AGAINST OTHER CARD
						for (int j = 0; j < this->guestPlayersCardsInPlay.size(); j++)
						{
							//TODO: Add Card attack here
							if (this->_data->input.CheckSpriteCollision(hostPlayersCardsInPlay.at(x)->_cardSprite, guestPlayersCardsInPlay.at(j)->_cardSprite, this->_data->window))
							{
								attack(hostPlayersCardsInPlay.at(x), guestPlayersCardsInPlay.at(j));
								//std::cout << "Collision Detexted Against: " << guestPlayersCardsInPlay.at(j)->getName() << std::endl;
							}
						}
						//CHECKS FOR COLLISION AGAINST OPPONENT PLAYER
						if (this->_data->input.CheckSpriteCollision(hostPlayersCardsInPlay.at(x)->_cardSprite, guestPlayer->_playerSprite, this->_data->window))
						{
							guestPlayer->setHealth(hostPlayersCardsInPlay.at(x)->getDamage() * -1);

							std::cout << "Guest player health: " << guestPlayer->getHealth() << std::endl;
							//TODO: Send the health of the opponent to the opponent 
						}
						hostPlayersCardsInPlay.at(x)->setSelected(false);
						this->hostPlayer->setSelection(false);
					}	
				}
				
			}
		}
	}
}

void Board::Update(float dt)
{
	MyPacket myPacket;
	sf::Packet packetReceive;

	if (!hostPlayer->getTurn())
		this->_data->socket.receive(packetReceive);


	int x = 0;
	if (packetReceive.getDataSize() > 0)
	{
		packetReceive >> x;
		switch (x)
		{
		case 1:
			guestPlayerInHand = myPacket.receiveHandPacket(packetReceive, this->_data);
			break;
		case 2:
			guestPlayersCardsInPlay = myPacket.receiveOpponentInPlayPacket(packetReceive, this->_data);
			break;
		case 3:
			hostPlayersCardsInPlay = myPacket.receivePlayerInPlayPacket(packetReceive, this->_data);
			break;
		case 4:
			hostPlayer->setTurn(myPacket.receiveTurnPacket(packetReceive));
            for (int i = 0; i < this->hostPlayersCardsInPlay.size(); i++)
            {
                if (this->hostPlayersCardsInPlay.at(i)->getId() != MINION_BATTLECRY_CARD)
                {
                    this->hostPlayersCardsInPlay.at(i)->effect(this);
                }
            }
			//TODO: Run Totems on players side ability here

			break;
		case 5:
		default:
			break;
		}
	}
	else
	{
		//std::cout << packetReceive.getDataSize() << std::endl;
		//sf::sleep(sf::seconds(5));
	}


}

void Board::Draw(float dt)
{
	//Clear the window before additions are made
	this->_data->window.clear();

	this->_data->window.draw(this->_background);

	hostPlayer->Draw(dt);
	guestPlayer->Draw(dt);

	//DRAW CARDS IN PLAYING FIELD
	int width = 0;
	
	//Guests player cards
	for (int index = 0; index < guestPlayersCardsInPlay.size(); index++)
	{
		guestPlayersCardsInPlay.at(index)->setPosition(width, guestPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().height + 5);
		guestPlayersCardsInPlay.at(index)->Draw(dt);
		width += guestPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().width;
	}

	width = 0;
	//Players playing cards
	for (int index = 0; index < hostPlayersCardsInPlay.size(); index++)
	{
		if (this->hostPlayersCardsInPlay.at(index)->isSelected())
			hostPlayersCardsInPlay.at(index)->setPosition(sf::Mouse::getPosition(this->_data->window).x - hostPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().width / 2, sf::Mouse::getPosition(this->_data->window).y - hostPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().height / 2);
		else
			hostPlayersCardsInPlay.at(index)->setPosition(width, SCREEN_HEIGHT - (hostPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().height * 2) + 5);
		
		hostPlayersCardsInPlay.at(index)->Draw(dt);
		width += hostPlayersCardsInPlay.at(index)->_cardSprite.getGlobalBounds().width;
	}



	//DRAW OPPONENTS CARDS IN HAND'
	for (int index = 0; index < guestPlayerInHand.size(); index++) {
		guestPlayerInHand.at(index)->setPosition(index * guestPlayerInHand.at(index)->getGlobalBounds().width, guestPlayerInHand.at(index)->getGlobalBounds().height * -0.5);

		this->_data->window.draw(*guestPlayerInHand.at(index));
	}

	this->_data->window.draw(this->_border);

	this->_data->window.display();
}

void Board::checkWinConditions()
{
}

void Board::attack(Card* card1, Card* card2)
{
	card2->setCurHealth(card1->getDamage() * -1);
	card1->setCurHealth(card2->getDamage() * -1);
}

bool Board::checkTaunts()
{
	return false;
}

void Board::update()
{
}

void Board::endTurn()
{
}
