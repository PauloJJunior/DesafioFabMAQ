#include "Raffle.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Classe criada para controle dos raffles 

Raffle::Raffle(int p_id,float p_x,float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt)
:x(p_x), y(p_y), tex(p_tex)
{

	i_xspt = p_xSpt;
	hspt = p_hSpt;

}


//Função para retornar Id
int Raffle::getId(){

	return id;
}


//Função para retornar posição X do sprite
float Raffle::getSpritePosition(){

		return xspt;
}

//Função para retornar posição Y
float Raffle::getY(){

		return y;
}

//Função para retornar posição X
float Raffle::getX(){

		return x;
}

//Função para retornar posição altura do sprite
float Raffle::getSizeSpriteX(){

		return hspt;
}


//Função para determinar posição X
void Raffle::setX(float p_x){

	x = p_x;
}

//Função para determinar posição Y
void Raffle::setY(float p_y){

	y = p_y;
}

//Função para determinar textura
void Raffle::setTex(SDL_Texture* p_tex){

	tex = p_tex;
}


//Função para determinar o id sorteado, alem de determinar a posição do sprite para ser exibido de acordo com o ID.
void Raffle::setId(int p_id){

	//Determina o ID sorteado
	id = p_id;

	// Se o ID sorteado for maior que 0
	if(p_id > 0){
		
		// Determina que a posição do sprite é a posição inicial do sprite de player * o numero de id
		xspt =  i_xspt * p_id;

	}
	// Caso ID sorteado seja 0
	else{

		// Determina que a posição do sprite é a posição de 60, tamanho do do sprite de raffle * o numero de id
		xspt =  60 * p_id;
	}


}

