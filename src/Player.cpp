#include "Player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Classe criada para controle dos playres 

Player::Player(int p_id,float p_x,float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt, bool p_moveStart)
:x(p_x), y(p_y), tex(p_tex)
{


	// Determina a posição x do sprite
	xspt = p_xSpt;
	
	// Determina que o moveStart é atribuido pela inicializalção
	moveStart = p_moveStart;


	// Armazena as variaves de inicialização para posteriormente serem utilizadas para reset do player.
	i_x = p_x;
	i_y = p_y;
	i_moveEnd = false;
	i_moveStart = p_moveStart;
	i_xspt = p_xSpt;
	i_yspt = p_ySpt;
	i_wspt = p_wSpt;
	i_hspt = p_hSpt;

}

//Função para retornar X
float Player::getX(){

	return x;
}

//Função para retornar Y
float Player::getY(){

	return y;
}

//Função para retornar Textura
SDL_Texture* Player::getTex(){

	return tex;
}


//Função para retornar o ID
int Player::getId(){

	return id;
}

//Função para retornar se o movimento terminou
bool Player::getmoveEnd(){

		return moveEnd;
}

//Função para retornar se o movimento iniciou
bool Player::getmoveStart(){

		return moveStart;
}

//Função para retornar posição X do sprite
float Player::getSpritePosition(){

		return xspt;
}



//Função para retornar se o jogador vencou a rodada
bool Player::getWin(){

		return win;
}



//Função para adicionar movimento ao player e determinar se o movimento terminou
void Player::movePlayer(int p_speed,int p_maxHeight){

	// Testa se o movimento atingiu a altura definida por p_maxHeight
	if(y > p_maxHeight){

		// Caso aidna não tenha atingido adiciona movimento ao player com base na velocidade de p_speed
		y = y - p_speed;

	}
	// Caso contrario determina que o movimento chegou ao fim.
	else{

		// Devermina o fim do movimento.
		moveEnd = true;
	}
	
}



//Função para determinar a textura
void Player::setTex(SDL_Texture* p_tex){

	tex = p_tex;
}


//Função para determinar o id sorteado, alem de determinar a posição do sprite para ser exibido de acordo com o ID.
void Player::setId(int p_id){

	//Determina o ID sorteado
	id = p_id;

	// Se o ID sorteado for maior que 0
	if(p_id > 0){
		
		// Determina que a posição do sprite é a posição inicial do sprite de player * o numero de id
		xspt =  i_xspt * p_id;

	}
	// Caso ID sorteado seja 0
	else{

		// Determina que a posição do sprite é a posição de 60, tamanho do do sprite de player * o numero de id
		xspt =  60 * p_id;
	}
	
}
//Função para determinar se o movimento iniciou
void Player::setmoveStart(bool p_start){

	moveStart = p_start;
}


//Função para determinar se o jogador ganhou a rodada
void Player::setWin(bool p_win){

	win = p_win;
}

//Função para determinar se o movimento terminou
void Player::setmoveEnd(bool p_end){

	moveEnd = p_end;

}


//Função para resetar os player para o estado inicial e assim evitar qualquer problema de posicionamento e status
void Player::resetPlayer(){


	x = i_x;
	y = i_y;
	moveEnd = i_moveEnd;
	moveStart = i_moveStart;
	xspt = i_xspt;
	yspt = i_yspt;
	wspt = i_wspt;
	hspt = i_hspt;
	win = false;

}


