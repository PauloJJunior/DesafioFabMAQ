#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"


// Classe criada para Rederizar as entidades na tela

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL){


	// Cria janela utilizando a biblioteca SDL, passando os atributos para criar a janela.
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h, SDL_WINDOW_SHOWN);

	// Debug para testar se a janela iniciou corretamente
	if(window == NULL){

		std::cout << "FAlaha ao Iniciar Window no SDL_CreateWindow, ERRO: " << SDL_GetError() << std::endl;
	}

	// Criar um renrer e determina que é para ser utilizada a Placa Grafica do PC
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}



// Funcao para carregar texturas
SDL_Texture* RenderWindow::loadTexture(const char*  p_filePath){

	// Cria uma variavel SDL para textura
	SDL_Texture* texture = NULL;
	// Atribui a variavel textura o renderer criar na função inicial e o caminho para a textura.
	texture = IMG_LoadTexture(renderer, p_filePath);

	// Debug para testar se a textura iniciou corretamente
	if(texture == NULL){

		std::cout << "Falha ao iniciar a textura ERRO:" << SDL_GetError() << std::endl;

	}

	// Retorna a Textura
	return texture;

}


// Funcao para carregar texturas
SDL_Texture* RenderWindow::loadTextureText(const char* p_text, int p_sizeFont, int p_colorR, int p_colorG, int p_colorB, int p_colorA){



	TTF_Font *font = TTF_OpenFont("res/gfx/brother.ttf" , p_sizeFont);

	SDL_Surface* surf = NULL;

	SDL_Color colorFont;

	colorFont.r = p_colorR;
	colorFont.g = p_colorG;
	colorFont.b = p_colorB;
	colorFont.a = p_colorA;



	// Cria uma variavel SDL para textura
	SDL_Texture* texture = NULL;



	surf = TTF_RenderText_Blended(font, p_text, colorFont);

	texture = SDL_CreateTextureFromSurface(renderer, surf);

	// Debug para testar se a textura iniciou corretamente
	if(texture == NULL){

		std::cout << "Falha ao iniciar a textura ERRO:" << SDL_GetError() << std::endl;

	}

	TTF_CloseFont(font);

	// Retorna a Textura
	return texture;

}



// Funcao para carregar texturas
SDL_Surface* RenderWindow::returnSizeText(const char* p_text, int p_sizeFont){



	TTF_Font *font = TTF_OpenFont("res/gfx/brother.ttf" , p_sizeFont);

	SDL_Surface* surf = NULL;

	SDL_Color colorFont {0,0,0,0};


	surf = TTF_RenderText_Blended(font, p_text, colorFont);

	TTF_CloseFont(font);


	return surf;

}





// Função para destruir a janela
void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

//Função apra limpar o renderer
void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}


//Função para atribuir uma tertyra ao renderer
void RenderWindow::render(Entity& p_entity)
{
	// Criar uma variavel Rect para definir o tamanho e a posição do sprite para carregar apenas o que eu pedir, no caso 1 objeto
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	// Criar uma variavel Rect para definir a posicao e tamanho da textura na janela
	SDL_Rect dst;
	dst.x =	p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;


	SDL_RenderCopy(renderer, p_entity.getTex(), &src,&dst);
}


//Função para atribuir uma tertyra ao renderer
void RenderWindow::renderText(EntityText& p_entity)
{
	// Criar uma variavel Rect para definir o tamanho e a posição do sprite para carregar apenas o que eu pedir, no caso 1 objeto
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	// Criar uma variavel Rect para definir a posicao e tamanho da textura na janela
	SDL_Rect dst;
	dst.x =	p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;


	SDL_RenderCopy(renderer, p_entity.getTex(), &src,&dst);
}

// Função para display
void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}