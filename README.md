# desafioFABMAQ

Desafio feito pela empresa FABMAQ para desenvolver um jogo em C/C++ para linux e windows

Mini Jogo desenvolvido em C/C++ para execução em Linux e Windows 

Tentando seguir as directivas passadas através do enunciado do desafio, foi criado um mini jogo com as seguintes características. 
  
     1) O jogo inicia em uma tela exibindo as informações referente aos créditos e rodadas definida como 0.  

     2) Para iniciar uma rodada o jogador deve apertar a tecla F1 e ter ao menos 1 crédito disponível, caso não tenha o jogador deverá utilizar a tecla F2 para adicionar créditos. 

     3) Estão disponíveis no jogo 50 objectos variados, todos esses objectos tem uma exibição de textura diferente um dos outros. 

     4) Ao iniciar uma rodada são sorteados 5 objectos (que irei chamar de raffle) dentre os 50 disponíveis no jogo para representar a combinação necessária para uma vitória, esses 5 objectos passam a ser exibidos na parte superior da tela. 

    5) Logo após o sorteio dos objectos acima, é iniciado um novo sorteio de mais 5 objectos (que irei chamar de player) dentre os 50 disponíveis no jogo, para verificar se existe alguma combinação com os objectos “raffle” sorteados anteriormente e assim definir a vitoria, esses objectos sorteados ficam armazenados e não são exibidos inicialmente. 

    6) Ao iniciar a jogada o objecto “player” se move em direcção ao objecto "raffle" com velocidade definida pelo sistema. 

    7) Ao finalizar o movimento do objecto “player” é verificado se os objectos são iguais, caso os objectos sejam iguais é exibida uma imagem representando uma vitória sobre o objecto “raffle” e é somado 10 de crédito ao jogador. Caso os objectos não sejam iguais é exibida uma mensagem representando uma derrota sobre o objecto “raffle”. 

    8) Ao finalizar o movimento do primeiro óbito “player”, é iniciado o seguinte, e assim por diante até finalizar a rodada após o término do movimento do objecto "player” numero 5. 
 
    9) Ao iniciar uma rodada o jogador tem a opção de apertar a tecla F1-START e pausar o jogo, ao apertar novamente o jogo volta a rodar. 

    10) Ao finalizar uma rodada o jogador tem que apertar a tecla F1-START para iniciar uma nova rodada, caso ainda tenha créditos. 

    11) O jogador pode diminuir ou aumentar a velocidade dos objectos, utilizando respectivamente as teclas F4 e F5. 

    12) A cada rodada iniciada é adicionado 1 ao contador de ROUNDS exibido na tela. 

    13) O jogar tem a opção de transferir os créditos disponíveis para uma "carteira" apertando a tecla F3-CREDITS OUT. 

 

UI/Informações exibidas na tela: 

    Credits: Exibe a quantidade de créditos disponíveis para o jogador. 

    Credits Out: Exibe a quantidade de créditos que o jogador retirou do jogo. 

    Rounds: Exibe a quantidade de rodadas que o jogador já jogou. 

 

Teclas/Botões:  

     F1:  Botão de START para iniciar uma rodada de sorteio e caso uma rodada esteja em andamento o mesmo botão PAUSE o jogo.  

    F2:  Botão para adicionar CREDITS IN, cada vez que é pressionado adiciona 1 de crédito para o jogador. 

    F3: Botão para transferir os créditos para a "carteira” do jogador, apenas se tiver créditos disponíveis. 

    F4: Botão para diminuir a velocidade em que os objectos se movem e consequentemente a velocidade da rodada. OBS: O mínimo de velocidade é 1. 

    F5: Botão para aumentar a velocidade em que os objectos se movem e consequentemente a velocidade da rodada. OBS: O máximo de velocidade é 25. 

 

 

Desenvolvimento/Código: 

     Codigo Font Donwload:
     https://github.com/PauloJJunior/desafioFABMAQ
          

   O desenvolvimento do minijogo utilizou a linguagem C/C++ e como auxílio principal a biblioteca SDL2, procurei nomear as classes e variáveis para melhor entendimento do código, alem disso busquei comentar linha por linha a execução do código, caso exista alguma dúvida em alguma implementação ou parte especifica do código, favor entrar em contacto. 


 
Donwload

     Linux: 
     https://github.com/PauloJJunior/desafioFABMAQ/raw/master/Desafio_FABMAQ_Paulo_Jorge_Linux.zip

     Windows: 
     https://github.com/PauloJJunior/desafioFABMAQ/raw/master/Desafio_FABMAQ_Paulo_Jorge_Windows.zip
 

Instalação/Execução 

   TTentei ao máximo incluir todos os arquivos necessários para a execução em suas respectivas builds, mas como mostrado abaixo existem alguns passos para serem seguidos especificamente para Linux. 
   

Linux: 

    Disponibilizo abaixo duas formas para instalação e execução no linux. 

    1) Entrar no diretório onde foi extraído os arquivos e executar os seguintes comandos no terminal. 

       make install 

       make run 

    2) Instalar as bibliotecas necessárias para a execução do binário, executando os seguintes comandos no terminal. 

       sudo apt-get install libsdl2-2.0 

       sudo apt-get install libsdl2-image-dev 

       sudo apt-get install libsdl-ttf2.0 

    Em seguida executar o binario com o comando 

      ./main 

Windows:  

    Basta fazer o download dos arquivos disponibilizados, extrair para uma paste de sua preferência e executar o Desafio_FABAMAQ _Paulo_Jorge.exe. 

 

 
