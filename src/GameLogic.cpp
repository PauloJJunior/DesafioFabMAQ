#include "GameLogic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Player.hpp"
#include "GameLogic.hpp"
#include "Raffle.hpp"


// Classe criada para utilziar alguma logicas necessarias no jogo


//Função gera um id aleatorio com base na quantidade de objetos disponiveis no jogo e e armazena essa informação no player.
void GameLogic::setPlayerRandom(Player& p_player,int p_content){

	//Gerar id aleatorio
	int tempRandomPlayer = rand() % p_content; 
	//Definir id gerado no player
	p_player.setId(tempRandomPlayer);

}


//Função gera um id aleatorio com base na quantidade de objetos disponiveis no jogo e e armazena essa informação no raffle.
void GameLogic::setRaffleRandom(Raffle& p_raffle,int p_content){

	//Gerar id aleatorio
	int tempRandomRaffle = rand() % p_content; 
	//Definir id gerado no raffle
	p_raffle.setId(tempRandomRaffle);
	
}







