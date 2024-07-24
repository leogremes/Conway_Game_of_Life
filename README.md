# Jogo da Vida de John Conway

## O que é o Jogo da Vida?

O jogo da vida, idealizado pelo matemático britânico John Conway é um [autômato celular](https://pt.wikipedia.org/wiki/Aut%C3%B3mato_celular). O jogo se passa em um arranjo bidimensional de células que podem estar em dois estados: "vivas ou mortas", e a cada geração seu estado pode mudar de acordo com as seguintes regras:<br>
1 - Toda célula viva com menos de dois vizinhos vivos morre por isolamento.<br>
2 - Toda célula viva com 2 ou 3 vizinhos vivos permanece viva.<br>
3 - Toda célula viva com mais de 3 vizinhos vivos morre por superpopulação.<br>
4 - Toda célula morta com exatamene 3 vizinhos vivos torna-se viva.<br>

[Saiba mais](https://pt.wikipedia.org/wiki/Jogo_da_vida)

## Aplicação

Essa versão do jogo da vida consiste em um pequeno tabuleiro. Quando a simulação está pausada, pode-se clicar nas células para alterar seu estado e assim criar padrões personalizados, ou pode-se gerar as células vivas de maneira aleatória.
### Controles
Barra de espaço - Pausa/Ativa a simulação<br>
Clique do mouse - Altera o estado da célula com a simulação pausada<br>
Seta pra cima - Avança para a próxima geração<br>
Seta pra baixo - Recua uma geração (Apenas uma vez)<br>
0 (teclado numérico) - Gera um tabuleiro aleatório<br>
\+ (teclado numérico) - Aumenta a velocidade da simulação<br>
\- (teclado numérico) - diminui a velocidade da simulação
### Compilaçao
O seguinte comando foi utilizado para compilar esse programa no Windows:
```
gcc main.c game_logic.c utils.c -I game_of_life -I .\SDL2\x86_64-w64-mingw32\include\ -L .\SDL2\x86_64-w64-mingw32\lib\ -lmingw32 -lSDL2main -lSDL2
```

## Motivação e aprendizado

Decidi criar a minha versão desse jogo para praticar os meus conhecimentos em C, fui inspirado por alguns vídeos que vi na internet. Para concluir o programa, tive que aprender a utilizar a biblioteca SDL2 para gerenciamento de janelas e rever alguns conceitos de programação, como a utilização de ponteiros.
#### Materiais que consultei durante o desenvolvimento
[Conway's Game of Life in Python](https://www.youtube.com/watch?v=cRWg2SWuXtM)<br>
[Como Instalar o SDL2 no Windows e Linux para Criar Jogos C/C++ e Primeiros Passos](https://www.youtube.com/watch?v=9IcIKdjSvfc)<br>
[SDL2 Tutorial](https://www.youtube.com/playlist?list=PLYmIsLVSssdIOn5J71CVBblPlXici1_2A)


