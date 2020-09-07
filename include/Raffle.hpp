#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Raffle{

public:
	Raffle(int p_id,float p_x,float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt);
	void init();
	int getId();	
	float getY();
	float getX();
	float getSizeSpriteX();

	void setX(float p_x);
	void setY(float p_y);
	void setTex(SDL_Texture* p_tex);
	void setId(int p_id);


	float getSpritePosition();
private:
	float x,y;
	float xspt,yspt, wspt,hspt;
	float i_xspt;
	int id;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

};
