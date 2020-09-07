#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Entity.hpp"
#include "EntityText.hpp"

class RenderWindow{

public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void renderText(EntityText& p_entity);
	void display();

	SDL_Texture* loadTextureText(const char* p_text, int p_sizeFont, int p_colorR, int p_colorG, int p_colorB, int p_colorA);

	SDL_Surface* returnSizeText(const char* p_text, int p_sizeFont);

private:

	SDL_Window* window;
	SDL_Renderer* renderer;

};