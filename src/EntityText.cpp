#include "EntityText.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Classe utilizada para criar uma entidade com todos os parametros necessario para ser renderizada um texto na tela.

EntityText::EntityText(float p_x, float p_y, SDL_Texture* p_tex, float p_wTex, float p_hTex)
:x(p_x), y(p_y), tex(p_tex)
{


 		currentFrame.x = 0;
 		currentFrame.y = 0;
 		currentFrame.w = p_wTex;
 		currentFrame.h = p_hTex;

 		
}

//função retornar X
float EntityText::getX(){

	return x;
}

//função retornar y
float EntityText::getY(){

	return y;
}

//função retornar Textura
SDL_Texture* EntityText::getTex(){

	return tex;
}

//função retornar currentFrame
SDL_Rect EntityText::getCurrentFrame(){

	return currentFrame;
}


//função set X
void EntityText::setX(float p_x){

	x = p_x;
}

//função set Y
void EntityText::setY(float p_y){

	y = p_y;
}

//função set Tex
void EntityText::setTex(SDL_Texture* p_tex){

	tex = p_tex;
}


//função set posicao H do texto
void EntityText::setTextH(float p_h){

	currentFrame.h = p_h;
}

//função set posicao W do texto
void EntityText::setTextW(float p_w){

	currentFrame.w = p_w;
}