#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "Player.hpp"
#include "Raffle.hpp"

class GameLogic{

public:

	void setPlayerRandom(Player& p_player,int p_content);
	void setRaffleRandom(Raffle& p_rafle,int p_content);
	

private:


};
