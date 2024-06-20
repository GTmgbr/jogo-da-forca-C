#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

//Prot�tipos das fun��es
void load_menu(int* pontos, char*  player);//Carregar o menu
void jogar(int* pontos);//Iniciar o jogo
void instrucoes(void);//Ler as instru��es
void devs(void);//Nome dos desenvolvedores
void sobre(void);//Mais informa��es sobre o jogo
void ranking(int* pontos, char* player);//Ranking de jogadores 
void bubbleSort(int* pontuacao, char nomes[10][255], int tamanho);//Ordenar a maior pontua��o
//bubbleSort = compara repetidamente pares de pontua��es adjacentes, e troca suas posi��es se estiverem na ordem errada 
void geraPalavra(char* nome_arq, char* destino);//Sortear palavra

//Desenha o boneco na forca para cada n�mero de erros at� 6
void forca(int estado){
    if(estado==0){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==1){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==2){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|           |");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==3){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|          -|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==4){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|          -|-");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==5){
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|          -|-");
      printf("\n|           |");
      printf("\n|          /");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-");
    }else if(estado==6){//Se o jogador errar 6 vezes, o jogo acaba
      printf("\n-------------");
      printf("\n|/          |");
      printf("\n|           0");
      printf("\n|          -|-");
      printf("\n|           |");
      printf("\n|          / \\");
      printf("\n|");
      printf("\n|");
      printf("\n|");
      printf("\n-    Game over!\n");
      printf("\n");
      printf("               _.------._       \n");
      printf("              /  _    _  \\      \n");
      printf("           _  ( (_\\  /_) )  _   \n");
      printf("          { \\._\\   /\\   /_./ }  \n");
      printf("          /_ =-.}______{.-= _\\  \n");
      printf("            _ _.=(IIII)=._  _   \n");
      printf("          (_' _.- `~~` -._ '_)  \n");
      printf("           {_/           \\_}   \n");
      printf("\n");
      printf("\n");
    }
}

//Fun��o para limpar a tela e esconder a palavra secreta
void limpa_tela(){
  for(int i=0; i<30; i++){//Pula 30 linhas
    printf("\n");
    } 
  }

//Fun��o main
int main(int argc, char** argv) {//Indica a quantidade de argumentos que foram passados ao chamar o programa
                                 //Par�metro argc = n�mero de par�metros na linha de comando que lan�ou a execu��o
                                 //Par�metro argv = vetor de strings que cont�m os argumentos de linha de comando, finalizado por um ponteiro 
//Passagem de par�metros com ponteiro para ponteiro pois a vari�vel "argv" guarda o endere�o de outra vari�vel
								 
  srand(time(NULL));//Recebe um argumento do tipo inteiro sem sinal e gera palavras aleat�rias
 
  int pontos = 0;//Quantidade de pontos come�a zerada
  char player[30];//Vari�vel para armazenar o nome do jogador 
  
  printf("\n");
  printf("\t\t  ---------------------------------------------------   \n");
  printf("\t\t  |  XXXXXXXX   XXXX    XXXXXXX   XXXXXX  XXXXXXXX  |   \n");
  printf("\t\t  |  XX       XX    XX  XX   XX   XX      XX    XX  |   \n");
  printf("\t\t  |  XX       XX    XX  XX   XX   XX      XX    XX  |   \n");
  printf("\t\t  |  XXXXXXX  XX    XX  XXXXXX    XX      XX    XX  |   \n");
  printf("\t\t  |  XX       XX    XX  XX  XX    XX      XXXXXXXX  |   \n");
  printf("\t\t  |  XX       XX    XX  XX   XX   XX      XX    XX  |   \n");
  printf("\t\t  |  XX         XXXX    XX    XX  XXXXXX  XX    XX  |   \n");
  printf("\t\t  |                                                 |   \n");    
  printf("\t\t  |     XXXXXXX  XXXXXXXX  XX       XX  XXXXXXX     |   \n"); 
  printf("\t\t  |     XX   XX  XX    XX  XXX     XXX  XX          |   \n");
  printf("\t\t  |     XX       XX    XX  XXXX   XXXX  XX          |   \n");
  printf("\t\t  |     XX  XXXX XX    XX  XX XX XX XX  XXXXXXX     |   \n");
  printf("\t\t  |     XX   XX  XXXXXXXX  XX  XXX  XX  XX          |   \n");
  printf("\t\t  |     XX   XX  XX    XX  XX       XX  XX          |   \n");
  printf("\t\t  |     XXXXXXX  XX    XX  XX       XX  XXXXXXX     |   \n");
  printf("\t\t  ---------------------------------------------------   \n");
  printf("\n"); 
  printf("Digite seu nome para jogar: \n");
  scanf("%s",player);
  load_menu(&pontos, player);//Carrega o menu
  return 0;
  }

//Selecionar cada op��o do menu
void load_menu(int* pontos, char* player)//Fun��o chama os ponteiros referentes �s vari�veis "pontos" e "player" declaradas na main
{
	int escolha;//Vari�vel para armazenar a escolha de tema digitada pelo jogador 

	do//Garante que o bloco de instru��es seja executado no m�nimo uma vez
	{   
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("*****MENU*****\n\n");
		printf("1. Jogar\n");
		printf("2. Instrucoes\n");
		printf("3. Desenvolvedores\n");
		printf("4. Sobre o jogo\n");
		printf("5. Ranking\n");
    printf("6. Sair\n");
    printf("\n");
    printf("Digite a opcao escolhida: \n");
		scanf("%d",&escolha);//Passagem por refer�ncia, pois est� passando o endere�o da vari�vel "escolha"

		switch(escolha)//Inicia a fun��o a depender do que foi digitado pelo jogador no menu em cada um dos casos
		{
			case 1: jogar(pontos);//O jogo come�a atrav�s da fun��o "jogar", e chama a vari�vel referente � pontua��o do jogador (que est� inicialmente zerada)
				break;
			case 2: instrucoes();
				break;
      case 3: devs();
				break;
			case 4: sobre();
			  break;
			case 5: 
      ranking(pontos, player);//Escreve no arquivo do ranking o nome e a pontua��o do jogador
        break;
        exit(0);
      case 6: printf("Fechando o programa!\n");
				exit(0);//Fecha o programa
				break;
			default: printf("Escolha invalida!\n");//Qualquer n�mero sem ser entre 1 e 6, � invalido 
				break;
		}

	} while (escolha != 7);//Enquanto a escolha for diferente de 7, n�o encerra o programa
}

//Iniciar o jogo
void jogar(int* pontos)//Passagem de par�metro por refer�ncia
{
  int tema;//Vari�vel para definir qual o tema escolhido pelo jogador
  
  printf("\n");
  printf("\n");
  printf("\n/////TEMAS/////");
  printf("\n");
  printf("\n");
  printf("1. Instrumentos musicais\n");
  printf("2. Paises\n");
  printf("3. Animais\n");
  printf("4. Esportes\n");
  printf("\n");
  printf("Escolha um tema para advinhar uma palavra aleatoria: \n");
  scanf("%d", &tema);
  
  int i;
  char palavra_sec[100];//Vari�vel que armazena a palavra secreta
  printf("\n");
  printf("Jogador:\n");

	switch(tema)//Inicia a forca a depender do tema escolhido pelo jogador
	{//Em cada um dos casos, o programa ir� sortear uma palavra dentre as que est�o no arquivo do tema selecionado, e copiar para a vari�vel que armazena a palavra secreta
		case 1:
      geraPalavra("instrumentos", palavra_sec);
      break;
    case 2:
      geraPalavra("paises", palavra_sec);
      break;
    case 3:
      geraPalavra("animais", palavra_sec);
      break;
    case 4:
      geraPalavra("esportes", palavra_sec);
      break;
	}
	
  printf("A palavra tem %d caracteres:",  strlen(palavra_sec)); //strlen = Retorna a quantidade de caracteres existentes em uma string. Inicia contando menos um, para n�o incluir o enter

  limpa_tela();//Chama a fun��o que limpa a tela

  char palavra_tela[100];//Vari�vel referente � palavra que aparece na tela
  strcpy(palavra_tela, palavra_sec);//strcpy = Fun��o que copia o conte�do de uma string para outra string. No caso, copia o conte�do da palavra tela para a palavra secreta

  
  for(size_t i=0; i<strlen(palavra_tela); i++){//Adiciona um underscore para cada letra da palavra escolhida
    palavra_tela[i]='_';
  }
  
  int erros = 0;//N�mero de erros come�a zerado
  
  while(1){//Roda o programa indefinidamente at� alguma condicional acontecer

    limpa_tela();
    
    forca(erros);//Imprime a forca 

    printf("\nAdivinhe: ");
    
    //Imprime palavra_tela
    for(size_t i=0; i<strlen(palavra_tela); i++){
      printf("%c ", palavra_tela[i]);
      }
    
    printf("\nLetra: ");
    char letra;
    scanf(" %c", &letra);//Recebe a letra

    int sera_que_errou=1;//Vari�vel para identificar qual letra digitada acertou e qual errou

	//Verifica se a letra est� correta
    for(size_t i=0; i<strlen(palavra_tela); i++){
      if(letra==palavra_sec[i]){//Se estiver correto
        palavra_tela[i]=letra;//Palavra escrita fica na tela 
        sera_que_errou=0;//Sem erros 
        }
    }

  if(sera_que_errou==1){//Se o jogador errar a letra, incrementa um erro 
    erros++;
    }

  //Verifica se a palavra secreta � igual a palavra da tela
  if(strcmp(palavra_tela, palavra_sec)==0){//strcmp = Fun��o que compara o conte�do de duas strings e devolve um valor
  (*pontos)++;//Se a palavra for igual, o jogador acertou, e ent�o ele ganha um ponto

    printf("\nAcertou: ");
    
    for(size_t i=0; i<strlen(palavra_tela); i++){//Se o jogador acertar todas as letras da palavra secreta, ele vence o jogo
      printf("%c ", palavra_tela[i]);
      
      }

    printf("\n");
    printf("\nVoce venceu o game. Parabens!\n");
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
    printf("\n");
    printf("Digite 5 para registrar sua vitoria no ranking...");
    printf("\n");
    break;
    }

  if(erros==6){//Se a quantidade de erros chegar a 6, o jogo acaba
    forca(erros);
    printf("A palavra secreta era: %s", palavra_sec);
    break;
    }
}
  return;
}

//Exibir as instru��es do jogo
void instrucoes(void)
{
	printf("\n");
	printf("O jogador, ao adivinhar uma letra, tem 2 possibilidades finais:\n");
	printf("1)Caso a letra escolhida esteja na palavra, ela se revelara em sua(s) posicao e o enforcado nao sofre mudancas\n");
	printf("2)Caso a letra escolhida nao se encontre na palavra, surgira na tela uma nova parte do corpo do enforcado\n");
	printf("\n");
	return;
}

//Exibir o nome dos participantes 
void devs(void)
{
	printf("\n");
	printf("Devs: Gabriel, Gustavo e Vinicius\n");
	printf("\n");
	return;
}

//Exibir mais informa��es sobre o jogo
void sobre(void)
{
	printf("\n");
	printf("Jogo tradicional de forca. O objetivo deste jogo eh descobrir qual eh a palavra oculta. O jogador recebe a informacao da quantidade de letras da palavra a ser descoberta, e deve tentar adivinha-las, escolhendo uma letra por vez.\n");
  printf("\n");
	return;
}

//Sortear uma palavra dentre um dos temas escolhidos
void geraPalavra (char* nome_arq, char* destino)//Passagem de par�metros por refer�ncia, pois possui dois ponteiros. Um referente ao nome do arquivo de tema escolhido e um para o destino da palavra
{
	
	FILE* arq = NULL;
	
	arq = fopen(nome_arq, "r");//Abre o arquivo escolhido e l� o conte�do. "r" especifica que � para leitura (read)
	
	if (arq == NULL) {//Se houverem problemas na cria��o do arquivo, uma mensagem de erro � exibida
    printf("Errado");
		return;
	}
	
	int linha = rand() % 10;//Gera palavras aleat�rias do arquivo entre 0 e 9
	
	while (fscanf(arq, "%s", destino) != EOF) {//L� o arquivo enquando n�o chegar ao fim		
		linha--;
		
		if (linha == 0) {
			break;
		}		
	}
	
	fclose(arq);//Fecha o arquivo
} 

//Ordena a pontua��o dos jogadores 
void bubbleSort(int* pontuacao, char nomes[10][255], int tamanho)//Passagem de par�metros por valor e por refer�ncia
{   
    int i;
    int trocou;//Vari�vel que representa a troca de pontua��o  
    
    do  
    {
        trocou = 0;
    for (i=tamanho; i > 0; i--)//Para cada vez que uma vari�vel for maior que a outra, ela passa a ser maior que a anterior (utilizando-se de uma vari�vel auxiliar)
    {   
        if (pontuacao[i] > pontuacao[i-1]) 
        {   
            int pAux;
            char nAux[255];
            pAux = pontuacao[i];
            strcpy(nAux, nomes[i]);
            pontuacao[i] = pontuacao[i-1];
            strcpy(nomes[i], nomes[i-1]);
            pontuacao[i-1] = pAux;
            strcpy(nomes[i-1], nAux);
            trocou = 1;
        }   
    }   

    }while (trocou);
}   

//Escreve a pontua��o no arquivo e mostra o ranking
void ranking(int* pontos, char* player)//Passagem de par�metros por refer�ncia
{  
  int qualquer;//Vari�vel qualquer apenas para fazer a an�lise dos nomes contidos no ranking
	printf("\n");      
	printf("\n");
  printf("\n####### Ranking de Jogadores #######\n");
  printf("  \n");
  printf(" NOME     -     PONTOS \n");
  printf("  \n");

    FILE * pont_arq;//Cria um ponteiro de arquivo
    pont_arq = fopen("data.txt", "r");//Abre o arquivo de texto para grava��o e leitura. Os dados ser�o adicionados no fim do arquivo se ele j� existir
    char nomes[10][255];//Cria uma matriz para 10 nomes e array de pontua��es
    int pontuacoes[10];//Vari�vel que ir� receber a pontua��o
    char nome[255];//Vari�vel que ir� receber o nome no arquivo
    int pontuacao;//Vari�vel que ir� receber a pontuacao no arquivo
    int tamanho = 0;
    int verifica = 0;
    
    while(!feof(pont_arq)) //L� do arquivo a pontua��o e nome dos jogadores
    //EOF ("End Of File") indica o fim de um arquivo. (Se o arquivo chegou ao fim, o loop termina)
    {  
      
      fscanf(pont_arq, "%s %d\n", nome, &qualquer);
      if(strcmp(nome, player) == 0 || strcmp(nome, "") == 0){//Compara os nomes j� existentes no arquivo para n�o os repetir sempre que o ranking for atualizado 
        verifica = 1;
        strcpy(nomes[tamanho],player);//Copia o nome do arquivo para a vari�vel que det�m o nome que est� no ranking
        pontuacoes[tamanho] = *pontos;
        }
        
        else{
        strcpy(nomes[tamanho],nome);
        pontuacoes[tamanho] = qualquer;
        }
      tamanho++;
    }

    if(verifica == 0){//Se o nome do arquivo for igual ao do nome digitado pelo jogador, isso significa que ele est� jogando novamente. Logo, sua pontua��o ser� incrementada (caso ele ganhe)
      strcpy(nomes[tamanho],player);
      pontuacoes[tamanho] = *pontos;
    }
    else{
      tamanho--;
    }

   bubbleSort(pontuacoes, nomes, tamanho);//Ordena a pontua��o
    printf("\n");  
    for(int i=0; i<=tamanho; i++){
    printf("%s %d\n", nomes[i], pontuacoes[i]);
     }
  
   fclose(pont_arq);
   pont_arq = fopen("data.txt", "w");//Abre o arquivo do ranking e somente escreve as pontua��es
        
   //Imprime os nomes com suas respectivas pontua��es 
   for(int i=0; i<=tamanho; i++){
    fprintf(pont_arq,"%s %d\n", nomes[i], pontuacoes[i]);
     }

  fclose(pont_arq);
}