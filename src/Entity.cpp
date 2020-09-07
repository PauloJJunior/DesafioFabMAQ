#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Classe utilizada para criar uma entidade com todos os parametros necessario para ser renderizada na tela.

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt)
:x(p_x), y(p_y), tex(p_tex)
{


 		currentFrame.x = p_xSpt;
 		currentFrame.y = p_ySpt;
 		currentFrame.w = p_wSpt;
 		currentFrame.h = p_hSpt;

 		


}

//função retornar X
float Entity::getX(){

	return x;
}

//função retornar y
float Entity::getY(){

	return y;
}

//função retornar Textura
SDL_Texture* Entity::getTex(){

	return tex;
}

//função retornar currentFrame
SDL_Rect Entity::getCurrentFrame(){

	return currentFrame;
}


//função set X
void Entity::setX(float p_x){

	x = p_x;
}

//função set Y
void Entity::setY(float p_y){

	y = p_y;
}

//função set Tex
void Entity::setTex(SDL_Texture* p_tex){

	tex = p_tex;
}


//função set posicao X do sprite
void Entity::setPositionSpritX(float p_x){

	currentFrame.x = p_x;
}