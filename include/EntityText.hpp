#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class EntityText{

public:
	EntityText(float p_x,float p_y, SDL_Texture* p_tex,float p_wTex, float p_hTex);
	void init();
	float getX();
	float getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	

	void setX(float p_x);
	void setY(float p_y);
	void setTex(SDL_Texture* p_tex);
	void setTextH(float p_h);
	void setTextW(float p_w);


	void setPositionSpritX(float p_x);
private:

	float x,y;
	float xspt,yspt, wspt,hspt;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

};
