#pragma once
#include "Card.h"
#include <vector>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

#include "DEFINITIONS.h"
#include "MinionBattlecry.h"
#include "MinionFriendly.h"
#include "MagicPlayer.h"
#include "MagicSummon.h"
#include "MagicBoard.h"
#include "MagicMinion.h"
#include "TotemFriendly.h"
#include "TotemPlayer.h"
#include "TotemBoard.h"
#include "Game.h"
class CardFactory
{
public:
	static std::vector<Card*> newDeck(GameDataRef data)
	{
		std::vector<Card*> returnHand;
		std::ifstream input_stream(CARD_FILE_LIST);

		std::string buffer;


		int id;
		std::string description;
		int cost;
		int health;
		int attack;

		//TOTEM AND MINIONS
		int taunt = 0;
		int charge = 0;

		//MINION
		char ability;
		int amount;





		while (input_stream.good())
		{
			getline(input_stream, buffer, ',');
			std::cout << "Buffer: " << buffer << std::endl;
			id = std::stoi(buffer);


			getline(input_stream, description, ',');
			//Convert it so the \n's are read as carriage return
			// 
			// //TODO: Fix this as it only does it for the first
			//description.replace(description.find_first_of("\\n"), description.find_first_of("\\n")+2, "\n");

			getline(input_stream, buffer, ',');
			cost = std::stoi(buffer);

			if (id >= MINION_CARD && id <= TOTEM_BOARD_CARD)
			{
				getline(input_stream, buffer, ',');
				health = std::stoi(buffer);

				if (id >= MINION_CARD && id <= MINION_CHARGE_CARD)
				{
					getline(input_stream, buffer);
					attack = std::stoi(buffer);
				}
				if (id == MINION_BATTLECRY_CARD || id == MINION_FRIENDLY_CARD)
				{
					getline(input_stream, buffer, ',');
					attack = std::stoi(buffer);
				}
			}

			if (id == MINION_TAUNT_CARD || id == TOTEM_TAUNT_CARD)
				taunt = 1;

			if (id == MINION_CHARGE_CARD)
				charge = 1;

			if (id > MINION_CHARGE_CARD)
			{
				getline(input_stream, buffer, ',');
				ability = buffer[0];

				getline(input_stream, buffer);
				amount = std::stoi(buffer);
			}


			switch (id)
			{
			case MINION_CARD:
				returnHand.push_back(new Minion(data, "Minion", description, cost, health, attack, taunt, charge));
				break;
			case MINION_TAUNT_CARD:
				returnHand.push_back(new Minion(data, "MinionTaunt", description, cost, health, attack, taunt, charge));
				break;
			case MINION_CHARGE_CARD:
				returnHand.push_back(new Minion(data, "MinionCharge", description, cost, health, attack, taunt, charge));
				break;
			case MINION_BATTLECRY_CARD:
				returnHand.push_back(new MinionBattleCry(data, "MinionBattlecry", description, cost, health, attack, taunt, charge, ability, amount));
				break;
			case MINION_FRIENDLY_CARD:
				returnHand.push_back(new MinionFriendly(data, "MinionFriendly", description, cost, health, attack, taunt, charge, ability, amount));
				break;
			case TOTEM_TAUNT_CARD:
				returnHand.push_back(new Totem(data, "TotemTaunt", description, cost, health, taunt, ability, amount));
				break;
			case TOTEM_FRIENDLY_CARD:
				returnHand.push_back(new TotemFriendly(data, "TotemFriendly", description, cost, ability, amount, health, taunt));
				break;
			case TOTEM_PLAYER_CARD:
				returnHand.push_back(new TotemPlayer(data, "TotemPlayer", description, cost, ability, amount, health, taunt));
				break;
			case TOTEM_BOARD_CARD:
				returnHand.push_back(new TotemBoard(data, "TotemBoard", description, cost, ability, amount, health, taunt));
				break;
			case MAGIC_PLAYER_CARD:
				returnHand.push_back(new MagicPlayer(data, "MagicPlayer", description, cost, ability, amount));
				break;
			case MAGIC_SUMMON_CARD:
				returnHand.push_back(new MagicSummon(data, "MagicSummon", description, cost, ability, amount));
				break;
			case MAGIC_BOARD_CARD:
				returnHand.push_back(new MagicBoard(data, "MagicBoard", description, cost, ability, amount));
				break;
			case MAGIC_MINION_CARD:
				returnHand.push_back(new MagicMinion(data, "MagicMinion", description, cost, ability, amount));
				break;

			}

		}
		input_stream.close();
		return returnHand;
	}

	static std::vector<Card*> newCard(GameDataRef data, sf::Packet & packet)
	{
		std::vector<Card*> returnHand;
		//Card* newCard = NULL;
		sf::Uint32 size;
		packet >> size;
		for (int i = 0; i < size; i++)
		{
			sf::Int8 id = 0;

			//std::cout << "Packet Get Data: " << packet.getData() << std::endl;
			packet >> id;
			
			switch (id)
			{
			case MINION_CARD:
				returnHand.push_back(new Minion(data));
				break;
			case MINION_TAUNT_CARD:
				returnHand.push_back(new Minion(data));
				break;
			case MINION_CHARGE_CARD:
				returnHand.push_back(new Minion(data));
				break;
			case MINION_BATTLECRY_CARD:
				returnHand.push_back(new MinionBattleCry(data));
				break;
			case MINION_FRIENDLY_CARD:
				returnHand.push_back(new MinionFriendly(data));
				break;
			case TOTEM_TAUNT_CARD:
				returnHand.push_back(new Totem(data));
				break;
			case TOTEM_FRIENDLY_CARD:
				returnHand.push_back(new TotemFriendly(data));
				break;
			case TOTEM_PLAYER_CARD:
				returnHand.push_back(new TotemPlayer(data));
				break;
			case TOTEM_BOARD_CARD:
				returnHand.push_back(new TotemBoard(data));
				break;
			case MAGIC_PLAYER_CARD:
				returnHand.push_back(new MagicPlayer(data));
				break;
			case MAGIC_SUMMON_CARD:
				returnHand.push_back(new MagicSummon(data));
				break;
			case MAGIC_BOARD_CARD:
				returnHand.push_back(new MagicBoard(data));
				break;
			case MAGIC_MINION_CARD:
				returnHand.push_back(new MagicMinion(data));
				break;
			}
			returnHand.at(i)->read(packet);
		}
		return returnHand;
	}

};

