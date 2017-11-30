#pragma once

//CONSTANTS
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define SPLASH_STATE_SHOW_TIME 3
#define ACTION_POINT_MAX 10

//Screens
#define SPLASH_SCENE_BACKGROUND_FILEPATH "assets/screens/splashScreen.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "assets/screens/mainMenuBackground.png"
#define GAME_BACKGROUND_FILEPATH "assets/screens/gameBackground.png"
#define GAME_BORDER_FILEPATH "assets/screens/gameBorder.png"
#define SEARCHING_BACKGROUND_FILEPATH "assets/screens/searchingForOpponent.png"
#define WIN_SCREEN_FILEPATH "assets/screens/winScreen.jpg"
#define LOSE_SCREEN_FILEPATH "assets/screens/loseScreen.jpg"


//Images-UI

//Font
#define GAME_FONT "assets/fonts/Kingdom.otf"

//Images-Players
#define MAGE_FILEPATH "assets/players/mage.png"
#define SHAMAN_FILEPATH "assets/players/shaman.png"
#define WARRIOR_FILEPATH "assets/players/warrior.png"

//Images-Cards
#define CARD_FILE_LIST "assets/cards/cardList.csv"
#define CARD_BACK_FILEPATH "assets/cards/cardBack.png"

#define MINION_CARD_FILEPATH "assets/cards/minion.png"
#define MINION_TAUNT_CARD_FILEPATH "assets/cards/minionTaunt.png"
#define MINION_CHARGE_CARD_FILEPATH "assets/cards/minionCharge.png"
#define MINION_BATTLECRY_CARD_FILEPATH "assets/cards/minionBattlecry.png"
#define MINION_FRIENDLY_CARD_FILEPATH "assets/cards/minionFriendly.png"

#define MAGIC_PLAYER_CARD_FILEPATH "assets/cards/magicPlayer.png"
#define MAGIC_SUMMON_CARD_FILEPATH "assets/cards/magicSummon.png"
#define MAGIC_BOARD_CARD_FILEPATH "assets/cards/magicBoard.png"
#define MAGIC_MINION_CARD_FILEPATH "assets/cards/magicMinion.png"

#define TOTEM_TAUNT_CARD_FILEPATH "assets/cards/totemTaunt.png"
#define TOTEM_BOARD_CARD_FILEPATH "assets/cards/totemBoard.png"
#define TOTEM_FRIENDLY_CARD_FILEPATH "assets/cards/totemFriendly.png"
#define TOTEM_PLAYER_CARD_FILEPATH "assets/cards/totemPlayer.png"


//Buttons
#define MAIN_MENU_PLAY_FILEPATH "assets/buttons/playButton.png"
#define RETURN_TO_MAIN_FILEPATH "assets/buttons/returnToMain.png"
#define CANCEL_SEARCH_FILEPATH "assets/buttons/cancelButton.png"

//Game State Variables
#define STATE_PLAYING 98
#define STATE_WON 97
#define STATE_LOSE 96

#define STATE_CONNECTED 93
#define STATE_DISCONNECTED 92

//TODO: Maybe get rid of these?
#define STATE_MY_PLAYING true
#define STATE_OPPONENT_PLAYING false


//This will define what the characters are
#define MAGE_CHARACTER 69
#define SHAMAN_CHARACTER 68
#define WARRIOR_CHARACTER 67

//CARDS - TEMPORARY
#define BLANK_CARD 30

#define MINION_CARD 31
#define MINION_TAUNT_CARD 32
#define MINION_CHARGE_CARD 33
#define MINION_BATTLECRY_CARD 34
#define MINION_FRIENDLY_CARD 35

#define TOTEM_TAUNT_CARD 36
#define TOTEM_FRIENDLY_CARD 37
#define TOTEM_PLAYER_CARD 38
#define TOTEM_BOARD_CARD 39

#define MAGIC_PLAYER_CARD 40
#define MAGIC_SUMMON_CARD 41
#define MAGIC_BOARD_CARD 42
#define MAGIC_MINION_CARD 43

