#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Player{

public:
	Player(int p_id,float p_x,float p_y, SDL_Texture* p_tex,float p_xSpt, float p_ySpt,float p_wSpt, float p_hSpt, bool p_moveStart);
	
	float getX();
	float getY();
	int getId();
	bool getmoveEnd();
	bool getmoveStart();
	bool getWin();

	SDL_Texture* getTex();


	void movePlayer(int p_speed, int p_maxHeight);
	void setTex(SDL_Texture* p_tex);
	void setId(int p_id);
	void setmoveStart(bool p_start);
	void setmoveEnd(bool p_end);
	void setWin(bool p_win);

	void resetPlayer();

	float getSpritePosition();


private:
	float x,y;
	float xspt,yspt, wspt,hspt;
	int id;
	bool moveEnd = false;
	bool moveStart = false;
	bool win = false;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

	float i_x, i_y;
	bool i_moveEnd, i_moveStart;
	float i_xspt,i_yspt, i_wspt,i_hspt;


};
