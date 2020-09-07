#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Entity{

public:
	Entity(float p_x,float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt);
	void init();
	float getX();
	float getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	

	void setX(float p_x);
	void setY(float p_y);
	void setTex(SDL_Texture* p_tex);

	void setPositionSpritX(float p_x);
private:

	float x,y;
	float xspt,yspt, wspt,hspt;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

};
