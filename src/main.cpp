#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>



#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "EntityText.hpp"
#include "Player.hpp"
#include "Raffle.hpp"
#include "GameLogic.hpp"
#include <vector>

int main(int argc, char* args[]){

	// Variaveis para Controle de FPS
	const int FPS = 60;
	const int frameDelay = 1000/ FPS;
	Uint32 frameStart;
	int frameTime;
	// Variaveis para controle de FPS


	// Variavel para Tamanho de Tela
	float sizeX = 900;
	float sizeY = 650;

	// Variavel para Quantidade de Objetos no Jogo
	int contentObj = 50;

	// Variavel para Altura onde vai ficar os objetos sorteados
	float raffleHeight = 150;

	//Variavel para determinar a velocidade de movimento dos objetos
	float speed = 8;


	//Variaveis para controle do status do jogo

	// Variavel para determinar se a partida esta em andamento
	bool matchOn = false;
	// Variavel para determinar se o pause esta Ativo
	bool pauseOn = false;
	// Variavel para controle do Loop do jogo e fechamento do jogo
	bool gameRunning = true;
	// Variavel para controlar se ja foi sorteado os objetos da partida e utilizada para qualquer elemento que precisa ser inicializado apenas uma vez na partida.
	bool randomMath = false;


	// Variaveis para controle de Credito

	// Variavel quantidade de credito
	int credits = 0;
	// Variavel para definir o custo de entrar em uma partida
	int custMath = 1;
	// Variavel que determina qual é o premio por acertar um objeto
	int prize = 10;
	// Variavel para quantidade de partidas jogadas
	int countMath = 0;
	// Variavel para a quantidade de credito retirado
	int creditsOut = 0;

	// Variavel para o Random nãa ser sempre o mesmo
	srand(time(0)); 





	// Inicia o SDL e testa se teve algum problema
	if(SDL_Init(SDL_INIT_VIDEO) > 0){
		std::cout <<"Falha ao iniciar o SDL_Init. SDL_ERROR: " << SDL_GetError() << std::endl;
	}


	// Inicializa lib ttf de fonte.
	TTF_Init();


	//Inicia o IMG e testa se teve algum problema
	if(!(IMG_Init(IMG_INIT_PNG))){
		std::cout <<"Falha ao iniciar o IMG_Init. ERROR: " << SDL_GetError() << std::endl;
	}

	// Criara a janela usando a clesse criada para isso
	RenderWindow window("Desafio-FABAMAQ-Paulo-Jorge", sizeX, sizeY);


	// Criar Variavel de GameLogic onde fica as logica do jogo
	GameLogic gameLogic;



	// Variaveis para Carregar Texturas
	// Load Textura dos Objetos
	SDL_Texture* objetosTexture = window.loadTexture("res/gfx/spritesObjetos.png");

	// Load Textura do background
	SDL_Texture* bgTexture = window.loadTexture("res/gfx/bg.png");

	// Load Textura dos Tubos
	SDL_Texture* tubeTexture = window.loadTexture("res/gfx/tube.png");

	// Load Textura da imagem de vitoria 
	SDL_Texture* winTexture = window.loadTexture("res/gfx/win.png");

	// Load Textura da imagem de deverrota.
	SDL_Texture* lostTexture = window.loadTexture("res/gfx/x.png");




	//Entidade de texto, chama o load Texture para criar a textura e chama o returnSizeTex para receber a altura e largura da textura, e passa para o entity.

	//Entidade de texto para o botão start
	EntityText entityTextStart(20,10,window.loadTextureText("F1 = START", 50, 255,255,255,255),
		window.returnSizeText("F1 = START", 50)->w, window.returnSizeText("F1 = START", 50)->h);

	//Entidade de texto para o botão Credits IN
	EntityText entityTextCreditsIn(250,10,window.loadTextureText("F2 = CREDITS IN", 50, 255,255,255,255),
		window.returnSizeText("F2 = CREDITS IN", 50)->w, window.returnSizeText("F2 = CREDITS IN", 50)->h);

	//Entidade de texto para o botão Credits OUT
	EntityText entityTextCreditsOut(570,10,window.loadTextureText("F3 = CREDITS OUT", 50, 255,255,255,255),
		window.returnSizeText("F3 = CREDITS OUT", 50)->w, window.returnSizeText("F3 = CREDITS OUT", 50)->h);


	//Entidade de texto para quantidade de creditos
	EntityText entityTextCountCredits(20,65,window.loadTextureText("Credits = 00", 35, 255,255,255,255),
		window.returnSizeText("Credits = 00", 35)->w, window.returnSizeText("Credits = 00", 35)->h);

		//Entidade de texto para quantidade de creditos retirados
	EntityText entityTextCountCreditsOut(320,65,window.loadTextureText("Credits OUT = 00", 35, 255,255,255,255),
		window.returnSizeText("Credits OUT = 00", 35)->w, window.returnSizeText("Credits OUT = 00", 35)->h);

	//Entidade de texto para quantidade de rodadas
	EntityText entityTextCountRounds(680,65,window.loadTextureText("Rounds = 00", 35, 255,255,255,255),
		window.returnSizeText("Rounds = 00", 35)->w, window.returnSizeText("Rounds = 0000", 35)->h);



	//Entidade de texto para o botão start
	EntityText entityTextSpeed(20,110,window.loadTextureText("F4 = -SPEED and F5 = +SPEED", 25, 2,12,15,255),
		window.returnSizeText("F4 = -SPEED and F5 = +SPEED", 25)->w, window.returnSizeText("F4 = -SPEED and F5 = +SPEED", 25)->h);



	// Cria vetor de Entidade de Players, foi definido diratemnte 5 declarações porque o escopo do jogo esta definido em 5.
	std::vector<Entity> entityPlayers{
	Entity(100,1000,objetosTexture,60,0,60,60),
	Entity(260,1000,objetosTexture,60,0,60,60),
	Entity(420,1000,objetosTexture,60,0,60,60),
	Entity(580,1000,objetosTexture,60,0,60,60),
	Entity(740,1000,objetosTexture,60,0,60,60)};



	// Cria vetor de Entidfade Raffles, foi definido diratemnte 5 declarações porque o escopo do jogo esta definido em 5.
	std::vector<Entity> entityRaffles{
	Entity(100,-100,objetosTexture,60,0,60,60),
	Entity(260,-100,objetosTexture,60,0,60,60),
	Entity(420,-100,objetosTexture,60,0,60,60),
	Entity(580,-100,objetosTexture,60,0,60,60),
	Entity(740,-100,objetosTexture,60,0,60,60)};



	//Entidade BackGraund
	Entity entityBackGround(0,0,bgTexture,0,0,sizeX,sizeY);

	//Entidade Tubo
	std::vector<Entity> entityTubes{
	Entity(70,204,tubeTexture,0,0,119,445),
	Entity(230,204,tubeTexture,0,0,119,445),
	Entity(390,204,tubeTexture,0,0,119,445),
	Entity(550,204,tubeTexture,0,0,119,445),
	Entity(710,204,tubeTexture,0,0,119,445)};




	std::vector<Entity> entityWins{
	Entity(-100,raffleHeight,winTexture,0,0,70,60),
	Entity(-100,raffleHeight,winTexture,0,0,70,60),
	Entity(-100,raffleHeight,winTexture,0,0,70,60),
	Entity(-100,raffleHeight,winTexture,0,0,70,60),
	Entity(-100,raffleHeight,winTexture,0,0,70,60)};







	// Cria vetor de Player, foi definido diratemnte 5 declarações porque o escopo do jogo esta definido em 5.
		std::vector<Player> players{
	Player(0,100,550,objetosTexture,60,0,60,60, true),
	Player(0,200,550,objetosTexture,60,0,60,60, false),
	Player(0,300,550,objetosTexture,60,0,60,60, false),
	Player(0,400,550,objetosTexture,60,0,60,60, false),
	Player(0,500,550,objetosTexture,60,0,60,60, false)};

	

	// Cria vetor de Raffle, foi definido diratemnte 5 declarações porque o escopo do jogo esta definido em 5.
		std::vector<Raffle> raffles{		
	Raffle (0,100,raffleHeight,objetosTexture,60,0,60,60),
	Raffle (0,200,raffleHeight,objetosTexture,60,0,60,60),
	Raffle (0,300,raffleHeight,objetosTexture,60,0,60,60),
	Raffle (0,400,raffleHeight,objetosTexture,60,0,60,60),
	Raffle (0,500,raffleHeight,objetosTexture,60,0,60,60)};




	// Variavel SDL que vai Receber os eventos de entrada.
	SDL_Event event;

	// Loop do Jogo
	while(gameRunning){

		// Variavel Utilizada temporariamente para exibir quantidade na tela
    	 std::string strText;


		// Definição para controle do FPS do jogo.
		frameStart = SDL_GetTicks();



		// Loop para controle de entrada de dados
		while(SDL_PollEvent(&event))
		{


			// Testa se o botão X da janela foi acionado  ou a tecla ESC, e muda status do jogo, para poder sair do loop do game e como consequencia fechar o jogo.
			if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE ){

				// Define a variavel de jogo rodando para false.
				gameRunning = false;
			}

			// Teste se alguma Tecla Foi pressionada
       		if(event.type == SDL_KEYDOWN){
            	
            	

       			// Testa se o jogador apertou a tecla de START e se o jogo esta pausado, caso esteja o jogo é despausdo
             	if(event.key.keysym.sym == SDLK_F1 && pauseOn){

             	// Define a variavel de pause como false e tira do pause
             	pauseOn = false;

           		}

           		// Testa se o jogador apertou start e a partida não esta iniciada, para assim iniciar a partida
           		else if(event.key.keysym.sym == SDLK_F1 && !matchOn){

           			// Testa se o jogador tem credito suficiente para iniciar a jogada, utilzia a variavel custMath para definir o custo da jogada, caso o jogador tenha credito suficiente a partida é iniciada e é retirado o custo de credito da quantidade total de credito do jogador
           			if(credits >= custMath){

                	credits = credits - custMath;
              	 	matchOn = true;



              	 	 	 	// Adiciona Texto e converte o credito em string
  				strText = "Credits = " + std::to_string(credits);
 
          
             	// Adiciona Credito para ser mostrada na entidade de texto de credito
             	entityTextCountCredits.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             	entityTextCountCredits.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             	entityTextCountCredits.setTextW(window.returnSizeText(strText.c_str(), 35)->w);


                	}    	
           		}

           		// Testa se o jogador apertou start e a partida ja esta iniciada, e assim definir o jogo como pausado
           		else if(event.key.keysym.sym == SDLK_F1 && matchOn && !pauseOn){

           		// Define que o pause esta on
           		pauseOn = true;

           		}


           		// Testa se o jogador apertou a tecla de adicionar credito, e assim adicionar creditos
           		if(event.key.keysym.sym == SDLK_F2 ){

           		// Adicona um credito ao jogador.	
             	credits++;


             	// Adiciona Texto e converte o credito em string
  				strText = "Credits = " + std::to_string(credits);
 
          
             	// Adiciona Credito para ser mostrada na entidade de texto de credito
             	entityTextCountCredits.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             	entityTextCountCredits.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             	entityTextCountCredits.setTextW(window.returnSizeText(strText.c_str(), 35)->w);

           		}

           		// Testa se o jogador apertou a tecla de retirar creditos, e assim manda os creditos para a "carteira" do jogador e zera os creditos disponiveis
				if(event.key.keysym.sym == SDLK_F3 ){

             	// Adiciona os creditos disponiveis na carteira do jogador
           	 	creditsOut = creditsOut + credits;


           	 	// Adiciona Texto e converte o credito em string
  				strText = "Credits OUT = " + std::to_string(creditsOut);
 
          
             	// Adiciona Credito para ser mostrada na entidade de texto de credito
             	entityTextCountCreditsOut.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             	entityTextCountCreditsOut.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             	entityTextCountCreditsOut.setTextW(window.returnSizeText(strText.c_str(), 35)->w);



           	 	//Zera os creditos disponiveis
           	 	credits = 0;

           	 	// Adiciona Texto e converte o credito em string
  				strText = "Credits = " + std::to_string(credits);
 
          
             	// Adiciona Credito para ser mostrada na entidade de texto de credito
             	entityTextCountCredits.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             	entityTextCountCredits.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             	entityTextCountCredits.setTextW(window.returnSizeText(strText.c_str(), 35)->w);



           		}


           		// Teste para saber se o jogador diminuiu a velocidade
           		if(event.key.keysym.sym == SDLK_F4){

           			// Se for maior ou igual a dois diminui um de velocidade
           			if(speed>=2){
           				speed--;
           			}

           		}
           		// Teste para saber se o jogador aumentou a velocidade
           		else if(event.key.keysym.sym == SDLK_F5){

           			// Define 25 como velocidade maxima
           			if(speed < 25){
           				speed++;
           			}
           			
           		}
        	}// Fecha o IF de testar tecla pressionada

		}// Fecha o loop de controle de eventos

		



		// Teste para ver se o jogo esta pausado ou não, tudo dentro desse teste é pausado quando o jogador aperta a tecla de start com uma partida em andamento.
		if(!pauseOn){


			// Teste para ver se uma partida esta em andamento
			if(matchOn){


				// Teste para saver se o sorteio da partida ja foi feito, caso não tenha sido feito é feito o sorteio e atribuido na classe players e faffles
				if(!randomMath){

					// Loop que Define a possição da entidade de exibição do sprite de vitoria ou derrota para uma posição fora da tela de exibição toda vez que inicia uma partida, para garantir que não seja exibido no momento errado.
					for(Entity& w :entityWins){ w.setX(-100);}
				

					// Adiciona um ao contador de partidas jogadas
					countMath++;



					// Adiciona Texto e converte o credito em string
  					strText = "Rounds = " + std::to_string(countMath);
 
          
             		// Adiciona Credito para ser mostrada na entidade de texto de credito
             		entityTextCountRounds.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             		entityTextCountRounds.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             		entityTextCountRounds.setTextW(window.returnSizeText(strText.c_str(), 35)->w);

					//Loop para gerar o sorteio dos players e atribuir os mesmos.
					for(Player& p :players){ gameLogic.setPlayerRandom(p,contentObj);};

					//Loop para gerar o sorteio dos raffles e atribuir os mesmos.
					for(Raffle& r :raffles){ gameLogic.setRaffleRandom(r,contentObj);};

					// Define a variavel de randoMath para true e assim define que ja foi feito o sorteio nessa partida.	
					randomMath = true;
				}

			

				//Loop para percorrer todo o player e raffle e defenir movimento, se o player é igual ao raffle e assim definir virtoria.
				for (std::size_t i = 0; i < players.size(); i++){


			 		// Teste para saber se o player ja terminou o percurso e se ele ja iniciou o seu percuso.
			 		if(!players[i].getmoveEnd() && players[i].getmoveStart()){


			 			// Caso o player cumpra as exigencia do teste acima, adiciona movimento ao player com base na variavel speed e determina qual é a altura final do percurso com a variavel raffleHeight + a posição do raffle para assim ficar abaixo do raffle.
			 			players[i].movePlayer(speed, raffleHeight + raffles[i].getSizeSpriteX());		
			 			
			 		}
			 		//Teste se o players ja terminou o movimento e se ainda tem mais players na fila.
			 		else if(players[i].getmoveEnd() && (i+1) <= players.size()){

			 			// Determina que o player não esta mais se movendo, já que chegou ao fim do movimento.
			 			players[i].setmoveStart(false);
			 			// Determina que o proximo player da fila inicie seu movimento.
			 			players[i+1].setmoveStart(true);

			 		}

			 		// Teste para definir que a rodada chegou ao fim, teste se todos os playres estão com o getmoveEnd com otrue.
			 		if(players[players.size()-1].getmoveEnd()){

			 			// Deternuba que a partida cehgou ao fim declarando a variavel matchOn como false
			 			matchOn = false;

			 			// Determina que já pode ser realizado outro sorteio na proxima todada, declarando a variavel fandomMath como false.
			 			randomMath = false;


			 			// Loop para percorrer todo o raffle e playres e testar se teve alguma virtoria, caso tenha adicionar ao montante de creditos
						for (std::size_t i = 0; i < raffles.size(); i++){	
					
							// Testa se teve alguma id igual e assim uma vitoria
							if(raffles[i].getY() == players[i].getY()){

								// Adiciona o Prmio ao credito
								credits = credits + prize;



								// Adiciona Texto e converte o credito em string
  								strText = "Credits = " + std::to_string(credits);
 
          
             					// Adiciona Credito para ser mostrada na entidade de texto de credito
             					entityTextCountCredits.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             					entityTextCountCredits.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             					entityTextCountCredits.setTextW(window.returnSizeText(strText.c_str(), 35)->w);


							}

						}

			 			

			 		}




					//Adiciona as informações na entidade player para que posteriormente possa ser renderizada na tela.
					//Determina a posição de Y do player
					entityPlayers[i].setY(players[i].getY());
					//Determina qual a posição do sprite para ser exibido de acordo com o ID sorteado do player
					entityPlayers[i].setPositionSpritX(players[i].getSpritePosition());		
	       		
				}// Fim do Loop para percorrer todo o player e raffle e defenir movimento, se o player é igual ao raffle e assim definir virtoria.



				// Loop para percorrer todo o raffle e definir, posição, e sprite a ser exibido.
				for (std::size_t i = 0; i < raffles.size(); i++){


					// Determina a possição Y que vai ser exibido o Raffle
			 		entityRaffles[i].setY(raffles[i].getY());
			 		//Determina qual a posição do sprite para ser exibido de acordo com o ID sorteado do raffle
					entityRaffles[i].setPositionSpritX(raffles[i].getSpritePosition());
				 	

 					 // Teste para ver o movimento do player terminou e se o id do raffle é igual ao id do player.
			 		if(players[i].getmoveEnd() && players[i].getId() == raffles[i].getId() ){

			 			//Define a posição X da entidade de exibição de vitoria
			 			entityWins[i].setX(entityRaffles[i].getX());	
			 			//Define a textura de vitoria para a entidade
			 			entityWins[i].setTex(winTexture);

			 			// Teste se e a primeira vez no loop com vitoria
			 			if(!players[i].getWin()){

			 			// Define que o player ja ganhou	
			 			players[i].setWin(true);

			 			// Adiciona o Prmio ao credito
						credits = credits + prize;



						// Adiciona Texto e converte o credito em string
  						strText = "Credits = " + std::to_string(credits);
 
          
             			// Adiciona Credito para ser mostrada na entidade de texto de credito
             			entityTextCountCredits.setTex(window.loadTextureText(strText.c_str(), 35, 255,255,255,255));
             			entityTextCountCredits.setTextH(window.returnSizeText(strText.c_str(), 35)->h);
             			entityTextCountCredits.setTextW(window.returnSizeText(strText.c_str(), 35)->w);

             			


			 			}

			 			

	 			
			 		}
			 		// Teste para ver o movimento do player terminou e se o id do raffle é diferente id do player.
			 		else if(players[i].getmoveEnd() && players[i].getId() != raffles[i].getId()){

			 			//Define a posição X da entidade de exibição de derrota
			 			entityWins[i].setX(entityRaffles[i].getX());
			 			//Define a textura de derrota para a entidade
			 			entityWins[i].setTex(lostTexture);

			 		}
						 			
				} // Fim do Loop para percorrer todo o raffle e definir, posição, e sprite a ser exibido.

				}// Fim do teste para ver se a partida esta em andamento, caso não esteja
				else{

				//Executa um Loop para Resetar o player.
				for(Player& p :players){ p.resetPlayer();};

			}							   

		}// Fim do Teste para ver se o jogo esta pausado ou não, tudo dentro desse teste é pausado quando o jogador aperta a tecla de start com uma partida em andamento.











		// Are destinada para renderização das entidades na tela.
		
		
		// Limpa a Janela
		window.clear();


		
		// Manda renderizar o background
		window.render(entityBackGround);



		//Loop para Renderizar dos as  entidades definidas em Players
		for(Entity& p :entityPlayers){ window.render(p);}

		//Loop para Renderizar dos as  entidades definidas em raffles
		for(Entity& r :entityRaffles){ window.render(r);}


		//Loop para Renderizar os tudbos
		for(Entity& t :entityTubes){ window.render(t);}

		// Manda renderizar a entidade de vitoria ou derrota.	
		//Loop para Renderizar dos as  entidades definidas em raffles
		for(Entity& w :entityWins){ window.render(w);}
		


		window.renderText(entityTextStart);
		window.renderText(entityTextCreditsIn);
		window.renderText(entityTextCreditsOut);
		window.renderText(entityTextCountCredits);
		window.renderText(entityTextCountCreditsOut);
		window.renderText(entityTextCountRounds);
		window.renderText(entityTextSpeed);

		
		

		// Mostra exibe tudo no display
		window.display();



		// Controel de FPS
		// Armazena o tempo de Frame do jogo e Faz a conta para manter o frame no limeite definido pela variavel FPS
		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelay > frameTime){

			SDL_Delay(frameDelay - frameTime);
		}


	}




	// Destroir a tela criada
	window.cleanUp();

	// Fecha o SDL
	SDL_Quit();


	return 0;
}




