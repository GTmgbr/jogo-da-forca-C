#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

//Protótipos das funções
void load_menu(int* pontos, char*  player);//Carregar o menu
void jogar(int* pontos);//Iniciar o jogo
void instrucoes(void);//Ler as instruções
void devs(void);//Nome dos desenvolvedores
void sobre(void);//Mais informações sobre o jogo
void ranking(int* pontos, char* player);//Ranking de jogadores 
void bubbleSort(int* pontuacao, char nomes[10][255], int tamanho);//Ordenar a maior pontuação
//bubbleSort = compara repetidamente pares de pontuações adjacentes, e troca suas posições se estiverem na ordem errada 
void geraPalavra(char* nome_arq, char* destino);//Sortear palavra

//Desenha o boneco na forca para cada número de erros até 6
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

//Função para limpar a tela e esconder a palavra secreta
void limpa_tela(){
  for(int i=0; i<30; i++){//Pula 30 linhas
    printf("\n");
    } 
  }

//Função main
int main(int argc, char** argv) {//Indica a quantidade de argumentos que foram passados ao chamar o programa
                                 //Parâmetro argc = número de parâmetros na linha de comando que lançou a execução
                                 //Parâmetro argv = vetor de strings que contém os argumentos de linha de comando, finalizado por um ponteiro 
//Passagem de parâmetros com ponteiro para ponteiro pois a variável "argv" guarda o endereço de outra variável
								 
  srand(time(NULL));//Recebe um argumento do tipo inteiro sem sinal e gera palavras aleatórias
 
  int pontos = 0;//Quantidade de pontos começa zerada
  char player[30];//Variável para armazenar o nome do jogador 
  
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

//Selecionar cada opção do menu
void load_menu(int* pontos, char* player)//Função chama os ponteiros referentes às variáveis "pontos" e "player" declaradas na main
{
	int escolha;//Variável para armazenar a escolha de tema digitada pelo jogador 

	do//Garante que o bloco de instruções seja executado no mínimo uma vez
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
		scanf("%d",&escolha);//Passagem por referência, pois está passando o endereço da variável "escolha"

		switch(escolha)//Inicia a função a depender do que foi digitado pelo jogador no menu em cada um dos casos
		{
			case 1: jogar(pontos);//O jogo começa através da função "jogar", e chama a variável referente à pontuação do jogador (que está inicialmente zerada)
				break;
			case 2: instrucoes();
				break;
      case 3: devs();
				break;
			case 4: sobre();
			  break;
			case 5: 
      ranking(pontos, player);//Escreve no arquivo do ranking o nome e a pontuação do jogador
        break;
        exit(0);
      case 6: printf("Fechando o programa!\n");
				exit(0);//Fecha o programa
				break;
			default: printf("Escolha invalida!\n");//Qualquer número sem ser entre 1 e 6, é invalido 
				break;
		}

	} while (escolha != 7);//Enquanto a escolha for diferente de 7, não encerra o programa
}

//Iniciar o jogo
void jogar(int* pontos)//Passagem de parâmetro por referência
{
  int tema;//Variável para definir qual o tema escolhido pelo jogador
  
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
  char palavra_sec[100];//Variável que armazena a palavra secreta
  printf("\n");
  printf("Jogador:\n");

	switch(tema)//Inicia a forca a depender do tema escolhido pelo jogador
	{//Em cada um dos casos, o programa irá sortear uma palavra dentre as que estão no arquivo do tema selecionado, e copiar para a variável que armazena a palavra secreta
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
	
  printf("A palavra tem %d caracteres:",  strlen(palavra_sec)); //strlen = Retorna a quantidade de caracteres existentes em uma string. Inicia contando menos um, para não incluir o enter

  limpa_tela();//Chama a função que limpa a tela

  char palavra_tela[100];//Variável referente à palavra que aparece na tela
  strcpy(palavra_tela, palavra_sec);//strcpy = Função que copia o conteúdo de uma string para outra string. No caso, copia o conteúdo da palavra tela para a palavra secreta

  
  for(size_t i=0; i<strlen(palavra_tela); i++){//Adiciona um underscore para cada letra da palavra escolhida
    palavra_tela[i]='_';
  }
  
  int erros = 0;//Número de erros começa zerado
  
  while(1){//Roda o programa indefinidamente até alguma condicional acontecer

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

    int sera_que_errou=1;//Variável para identificar qual letra digitada acertou e qual errou

	//Verifica se a letra está correta
    for(size_t i=0; i<strlen(palavra_tela); i++){
      if(letra==palavra_sec[i]){//Se estiver correto
        palavra_tela[i]=letra;//Palavra escrita fica na tela 
        sera_que_errou=0;//Sem erros 
        }
    }

  if(sera_que_errou==1){//Se o jogador errar a letra, incrementa um erro 
    erros++;
    }

  //Verifica se a palavra secreta é igual a palavra da tela
  if(strcmp(palavra_tela, palavra_sec)==0){//strcmp = Função que compara o conteúdo de duas strings e devolve um valor
  (*pontos)++;//Se a palavra for igual, o jogador acertou, e então ele ganha um ponto

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

//Exibir as instruções do jogo
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

//Exibir mais informações sobre o jogo
void sobre(void)
{
	printf("\n");
	printf("Jogo tradicional de forca. O objetivo deste jogo eh descobrir qual eh a palavra oculta. O jogador recebe a informacao da quantidade de letras da palavra a ser descoberta, e deve tentar adivinha-las, escolhendo uma letra por vez.\n");
  printf("\n");
	return;
}

//Sortear uma palavra dentre um dos temas escolhidos
void geraPalavra (char* nome_arq, char* destino)//Passagem de parâmetros por referência, pois possui dois ponteiros. Um referente ao nome do arquivo de tema escolhido e um para o destino da palavra
{
	
	FILE* arq = NULL;
	
	arq = fopen(nome_arq, "r");//Abre o arquivo escolhido e lê o conteúdo. "r" especifica que é para leitura (read)
	
	if (arq == NULL) {//Se houverem problemas na criação do arquivo, uma mensagem de erro é exibida
    printf("Errado");
		return;
	}
	
	int linha = rand() % 10;//Gera palavras aleatórias do arquivo entre 0 e 9
	
	while (fscanf(arq, "%s", destino) != EOF) {//Lê o arquivo enquando não chegar ao fim		
		linha--;
		
		if (linha == 0) {
			break;
		}		
	}
	
	fclose(arq);//Fecha o arquivo
} 

//Ordena a pontuação dos jogadores 
void bubbleSort(int* pontuacao, char nomes[10][255], int tamanho)//Passagem de parâmetros por valor e por referência
{   
    int i;
    int trocou;//Variável que representa a troca de pontuação  
    
    do  
    {
        trocou = 0;
    for (i=tamanho; i > 0; i--)//Para cada vez que uma variável for maior que a outra, ela passa a ser maior que a anterior (utilizando-se de uma variável auxiliar)
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

//Escreve a pontuação no arquivo e mostra o ranking
void ranking(int* pontos, char* player)//Passagem de parâmetros por referência
{  
  int qualquer;//Variável qualquer apenas para fazer a análise dos nomes contidos no ranking
	printf("\n");      
	printf("\n");
  printf("\n####### Ranking de Jogadores #######\n");
  printf("  \n");
  printf(" NOME     -     PONTOS \n");
  printf("  \n");

    FILE * pont_arq;//Cria um ponteiro de arquivo
    pont_arq = fopen("data.txt", "r");//Abre o arquivo de texto para gravação e leitura. Os dados serão adicionados no fim do arquivo se ele já existir
    char nomes[10][255];//Cria uma matriz para 10 nomes e array de pontuações
    int pontuacoes[10];//Variável que irá receber a pontuação
    char nome[255];//Variável que irá receber o nome no arquivo
    int pontuacao;//Variável que irá receber a pontuacao no arquivo
    int tamanho = 0;
    int verifica = 0;
    
    while(!feof(pont_arq)) //Lê do arquivo a pontuação e nome dos jogadores
    //EOF ("End Of File") indica o fim de um arquivo. (Se o arquivo chegou ao fim, o loop termina)
    {  
      
      fscanf(pont_arq, "%s %d\n", nome, &qualquer);
      if(strcmp(nome, player) == 0 || strcmp(nome, "") == 0){//Compara os nomes já existentes no arquivo para não os repetir sempre que o ranking for atualizado 
        verifica = 1;
        strcpy(nomes[tamanho],player);//Copia o nome do arquivo para a variável que detém o nome que está no ranking
        pontuacoes[tamanho] = *pontos;
        }
        
        else{
        strcpy(nomes[tamanho],nome);
        pontuacoes[tamanho] = qualquer;
        }
      tamanho++;
    }

    if(verifica == 0){//Se o nome do arquivo for igual ao do nome digitado pelo jogador, isso significa que ele está jogando novamente. Logo, sua pontuação será incrementada (caso ele ganhe)
      strcpy(nomes[tamanho],player);
      pontuacoes[tamanho] = *pontos;
    }
    else{
      tamanho--;
    }

   bubbleSort(pontuacoes, nomes, tamanho);//Ordena a pontuação
    printf("\n");  
    for(int i=0; i<=tamanho; i++){
    printf("%s %d\n", nomes[i], pontuacoes[i]);
     }
  
   fclose(pont_arq);
   pont_arq = fopen("data.txt", "w");//Abre o arquivo do ranking e somente escreve as pontuações
        
   //Imprime os nomes com suas respectivas pontuações 
   for(int i=0; i<=tamanho; i++){
    fprintf(pont_arq,"%s %d\n", nomes[i], pontuacoes[i]);
     }

  fclose(pont_arq);
}