#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <unistd.h> // para piscar

char europa[49][50] = {"Albânia", "Andorra", "Armênia", "Áustria", "Bielorrússia", "Bélgica", "Bósnia_e_Herzegovina", "Bulgária", "Croácia", "Chipre", "República_Tcheca", "Dinamarca", "Estônia", "Finlândia", "França", "Geórgia", "Alemanha", "Grécia", "Hungria", "Islândia", "Irlanda", "Itália", "Kosovo", "Letônia", "Liechtenstein", "Lituânia", "Luxemburgo", "Malta", "Moldávia", "Mônaco", "Montenegro", "Holanda", "Macedônia_do_Norte", "Noruega", "Polônia", "Portugal", "Romênia", "Rússia", "San_Marino", "Sérvia", "Eslováquia", "Eslovênia", "Espanha", "Suécia", "Suíça", "Turquia", "Ucrânia", "Reino_Unido", "Vaticano"};

char africa[53][50] = {"Argélia", "Angola", "Benin", "Botsuana", "Burkina_Faso", "Burundi", "Camarões", "Cabo_Verde", "República_Centro-Africana", "Chade", "Comores", "Congo", "Costa_do_Marfim", "Djibuti", "Egito", "Guiné_Equatorial", "Eritreia", "Eswatini", "Etiópia", "Gabão", "Gâmbia", "Gana", "Guiné", "Guiné-Bissau", "Quênia", "Lesoto", "Libéria", "Líbia", "Madagascar", "Malawi", "Mali", "Mauritânia", "Maurícia", "Marrocos", "Moçambique", "Namíbia", "Níger", "Nigéria", "Ruanda", "São_Tomé_e_Príncipe", "Senegal", "Seychelles", "Serra_Leoa", "Somália", "África_do_Sul", "Sudão_do_Sul", "Sudão", "Tanzânia", "Togo", "Tunísia", "Uganda", "Zâmbia", "Zimbábue"};

char americaCentralNorte[23][50] = {"Antígua_e_Barbuda", "Bahamas", "Barbados", "Belize", "Canadá", "Costa_Rica", "Cuba", "Dominica", "República_Dominicana", "El_Salvador", "Granada", "Guatemala", "Haiti", "Honduras", "Jamaica", "México", "Nicarágua", "Panamá", "São_Cristóvão_e_Nevis", "Santa_Lúcia", "São_Vicente_e_Granadinas", "Trinidad_e_Tobago", "Estados_Unidos"};

char americaSul[12][50] = {"Argentina", "Bolívia", "Brasil", "Chile", "Colômbia", "Equador", "Guiana", "Paraguai", "Peru", "Suriname", "Uruguai", "Venezuela"};

char asia[46][50] = {"Afeganistão", "Azerbaijão", "Bahrein", "Bangladesh", "Bhutan", "Brunei", "Camboja", "China", "Timor-Leste", "Índia", "Indonésia", "Irã", "Iraque", "Israel", "Japão", "Jordânia", "Cazaquistão", "Coreia_do_Sul", "Kuwait", "Quirguistão", "Laos", "Líbano", "Malásia", "Maldivas", "Mongólia", "Myanmar", "Nepal", "Omã", "Paquistão", "Palestina", "Filipinas", "Catar", "Arábia_Saudita", "Cingapura", "Sri_Lanka", "Síria", "Rússia", "Taiwan", "Tajiquistão", "Tailândia", "Turquia", "Turcomenistão", "Emirados_Árabes_Unidos", "Uzbequistão", "Vietnã", "Iêmen"};

char oceania[13][50] = {"Austrália", "Fiji", "Ilhas_Marshall", "Micronésia", "Nauru", "Nova_Zelândia", "Palau", "Papua_Nova_Guiné", "Samoa", "Ilhas_Salomão", "Tonga", "Tuvalu", "Vanuatu"};

typedef struct Node{
  char pais[50];
  struct Node *prox;
}Node;

void inserir(Node **head, char *pais);
void randPaises(int indice, Node **head);
void randContinentes(Node **head1, Node **head2, Node **head3, Node **head4, int indices[]);
void printList(Node *head);
char *returnNode(Node *head, int index);
void shuffle(char geral[][50], int tamanho);
void generateRandomNumbers(int numbers[], int limit);
void bubbleSort(Node **head, int len);
void listaResposta(Node **head, char pais1[50], char pais2[50], char pais3[50], char pais4[50]);
int verificacao(Node *resposta, Node *head1, Node *head2, Node *head3, Node *head4);
void substituir(char *pais, char geral[][50], int tamanho);
char *achar_continente(char *pais);

void printColor(char *message, char *color) {
  printf("\033[%sm%s\033[0m", color, message);
}

void printConexo() {
  printColor("  _____  ______   ____    _____   ____   _   _  ______ __   __  ____  \n", "35"); //roxo
  printColor(" / ____||  ____| / __ \\  / ____| / __ \\ | \\ | ||  ____|\\ \\ / / / __ \\ \n", "35"); //roxo
  printColor("| |  __ | |__   | |  | || |     | |  | ||  \\| || |__    \\ V / | |  | |\n", "35"); //roxo
  printColor("| | |_ ||  __|  | |  | || |     | |  | || . ` ||  __|    > <  | |  | |\n", "35"); //roxo
  printColor("| |__| || |____ | |__| || |____ | |__| || |\\  || |____  / . \\ | |__| |\n", "35"); //roxo
  printColor(" \\_____||______| \\____/  \\_____| \\____/ |_| \\_||______|/_/ \\_\\ \\____/ \n", "35"); //roxo
  printColor("                                                                       \n", "35"); //roxo
  printColor("                                                                       \n", "35"); //roxo
}

void print_voceganhou() {
  printColor("__      __  ____    _____  ______     _____            _   _  _    _   ____   _    _ \n", "35"); //roxo
  printColor("\\ \\    / / / __ \\  / ____||  ____|   / ____|    /\\    | \\ | || |  | | / __ \\ | |  | |\n", "35"); //roxo
  printColor(" \\ \\  / / | |  | || |     | |__     | |  __    /  \\   |  \\| || |__| || |  | || |  | |\n", "35"); //roxo
  printColor("  \\ \\/ /  | |  | || |     |  __|    | | |_ |  / /\\ \\  | . ` ||  __  || |  | || |  | |\n", "35"); //roxo
  printColor("   \\  /   | |__| || |____ | |____   | |__| | / ____ \\ | |\\  || |  | || |__| || |__| |\n", "35"); //roxo
  printColor("    \\/     \\____/  \\_____||______|   \\_____|/_/    \\_\\|_| \\_||_|  |_| \\____/  \\____/ \n", "35"); //roxo
  printf("                                                                                      \n"); //roxo
  printf("                                                                                      \n"); //roxo
}

void clearScreen() {
  system("clear");
}

void EsperePeloEnter() {
  printColor("Pressione Enter para começar...\n", "34"); // Azul
  while (getchar() != '\n'); // Aguarda até que o usuário pressione Enter
  system("clear"); // Limpa a tela
}


int main(void) {
  Node *head1 = NULL, *head2 = NULL, *head3 = NULL, *head4 = NULL, *resposta = NULL;
  char geral[16][50], corretos[20][50] = {""};
  int nums[4];
  int acertos = 0, id = 0;
  char entrada[200];
  char pais1[50], pais2[50], pais3[50], pais4[50];

  generateRandomNumbers(nums, 6);
  randContinentes(&head1, &head2, &head3, &head4, nums);

  for (int i = 0; i < 16; i++){
    if (i < 4){
      strcpy(geral[i], returnNode(head1, i));
    }
    else if (i < 8){
      strcpy(geral[i], returnNode(head2, i - 4));
    }
    else if (i < 12){
      strcpy(geral[i], returnNode(head3, i - 8));
    }
    else{
      strcpy(geral[i], returnNode(head4, i - 12));
    }
  }

  shuffle(geral, 16);

  bubbleSort(&head1, 4);
  bubbleSort(&head2, 4);
  bubbleSort(&head3, 4);
  bubbleSort(&head4, 4);

  clearScreen();
  printConexo();
  EsperePeloEnter();

  while(acertos<4){
    int c = 0;
    int cor = 0;
    for (int i = 0; i < 20; i++){
      if (strcmp(corretos[i], "") != 0){
        if(cor == 0){
          printColor(corretos[i], "34");
        }else if (cor==1){
          printColor(corretos[i], "35");
        }else if (cor==2){
          printColor(corretos[i], "33");
        }else if (cor==3){
          printColor(corretos[i], "32");
        }
        c++;
      }

      if (c == 5){
        printf("\n");
        c = 0;
        cor++;
      }

      else if(c > 1){
        printf(", ");
      }
    }

    printf("\n");

    c = 0;
    for (int i = 0; i < 16; i++){
      if (strcmp(geral[i], "") != 0){
        printf("[%s] ", geral[i]);
        c++;
      }

      if (c == 4){
        printf("\n");
        c = 0;
      }
    }
    printf("\n");

    printf("Insira sua Resposta: \n");
    fgets(entrada, sizeof(entrada), stdin);
    sscanf(entrada, "%s %s %s %s", pais1, pais2, pais3, pais4);

    // printf("%s %s %s %s", pais1, pais2, pais3, pais4);
    printf("\n\n");

    listaResposta(&resposta, pais1, pais2, pais3, pais4);
    bubbleSort(&resposta, 4);

    system("clear");

    // printList(head1);
    // printList(head2);
    // printList(head3);
    // printList(head4);
    // printf("\n");

    if (verificacao(resposta, head1, head2, head3, head4)){
      acertos++;
      if(acertos<=3){
        printColor("Acertou! Parabéns\n\n", "32");
      }

      substituir(pais1, geral, 16);
      substituir(pais2, geral, 16);
      substituir(pais3, geral, 16);
      substituir(pais4, geral, 16);

      strcpy(corretos[id], achar_continente(pais1));
      strcpy(corretos[id+1], pais1);
      strcpy(corretos[id+2], pais2);
      strcpy(corretos[id+3], pais3);
      strcpy(corretos[id+4], pais4);
      id += 5;
    }
    else{
      printColor("Errou! Tente de novo\n\n", "31");
    }
  }

  print_voceganhou();

  int c = 0;
  int cor = 0;
  for (int i = 0; i < 20; i++){
    if (strcmp(corretos[i], "") != 0){
      if(cor == 0){
        printColor(corretos[i], "34");
      }else if (cor==1){
        printColor(corretos[i], "35");
      }else if (cor==2){
        printColor(corretos[i], "33");
      }else if (cor==3){
        printColor(corretos[i], "32");
      }
      c++;
    }

    if (c == 5){
      printf("\n");
      c = 0;
      cor++;
    }

    else if(c > 1){
      printf(", ");
    }
  }

  return 0;
}

void inserir(Node **head, char *pais){
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL){
    strcpy(novo->pais, pais);
    novo->prox = *head;
    *head = novo;
  }
}

void randPaises(int indice, Node **head){
  int nums[4];

  if (indice == 0){
    generateRandomNumbers(nums, 49);

    for (int i = 0; i < 4; i++){
      inserir(head, europa[nums[i]]);
    }
  }

  else if (indice == 1){
    generateRandomNumbers(nums, 53);

    for (int i = 0; i < 4; i++){
      inserir(head, africa[nums[i]]);
    }
  }

  else if (indice == 2){
    generateRandomNumbers(nums, 23);

    for (int i = 0; i < 4; i++){
      inserir(head, americaCentralNorte[nums[i]]);
    }
  }

  else if (indice == 3){
    generateRandomNumbers(nums, 12);

    for (int i = 0; i < 4; i++){
      inserir(head, americaSul[nums[i]]);
    }
  }

  else if (indice == 4){
    generateRandomNumbers(nums, 46);

    for (int i = 0; i < 4; i++){
      inserir(head, asia[nums[i]]);
    }
  }

  else if (indice == 5){
    generateRandomNumbers(nums, 13);

    for (int i = 0; i < 4; i++){
      inserir(head, oceania[nums[i]]);
    }
  }
}

void randContinentes(Node **head1, Node **head2, Node **head3, Node **head4, int indices[]){
  srand(time(NULL));

  // indices = {4, 2, 1, 0}

  for (int i = 0; i < 4; i++){
    if (i == 0){
      randPaises(indices[0], head1);
    }
    else if (i == 1){
       randPaises(indices[1], head2);
    }
    else if (i == 2){
       randPaises(indices[2], head3);
    }
    else if (i == 3){
       randPaises(indices[3], head4);
    }
  }
}

void printList(Node *head){
  while(head != NULL){
    printf("[%s] -> ", head->pais);
    head = head->prox;
  }
  printf("NULL\n");
}

char *returnNode(Node *head, int index){
  int cont = 0;

  while(head != NULL && cont != index){
    head = head->prox;
    cont++;
  }

  if (head == NULL){
    return "ERRO";
  }
  else{
    return head->pais;
  }
}

void shuffle(char geral[][50], int tamanho){
  int r;
  char temp[50];

  for (int i = 0; i < tamanho; i++){
    strcpy(temp, geral[i]);
    r = rand() % tamanho;
    strcpy(geral[i], geral[r]);
    strcpy(geral[r], temp);
  }
}

void generateRandomNumbers(int numbers[], int limit){
  srand(time(NULL));

  numbers[0] = rand() % limit; // Gera numero entre 0 e limit-1   ex:limit = 6   0-5
  do {
      numbers[1] = rand() % limit;
  } while (numbers[1] == numbers[0]);
  do {
      numbers[2] = rand() % limit;
  } while (numbers[2] == numbers[0] || numbers[2] == numbers[1]);
  do {
      numbers[3] = rand() % limit;
  } while (numbers[3] == numbers[0] || numbers[3] == numbers[1] || numbers[3] == numbers[2]);
}

void bubbleSort(Node **head, int len) {
  for(int i = 0; i < len; i++) {
    Node *aux =  *head;
    Node *next = aux -> prox;
    for(int j = 0; j < len - i - 1; j++) {
      if(strcmp(aux -> pais, next -> pais) > 0) {
        char temp_nome[50];
        strcpy(temp_nome, aux -> pais);
        strcpy(aux -> pais, next->pais);
        strcpy(next->pais, temp_nome);
      }
      aux =  aux -> prox;
      next = next -> prox;
    }
  }
}

void listaResposta(Node **head, char pais1[50], char pais2[50], char pais3[50], char pais4[50]){
  if(*head == NULL){
    inserir(head, pais4);
    inserir(head, pais3);
    inserir(head, pais2);
    inserir(head, pais1);
  }else{
    strcpy((*head)->pais, pais1);
    strcpy((*head)->prox->pais, pais2);
    strcpy((*head)->prox->prox->pais, pais3);
    strcpy((*head)->prox->prox->prox->pais, pais4);
  }
}

int verificacao(Node *resposta, Node *head1, Node *head2, Node *head3, Node *head4){
  Node *aux_resposta, *aux_continentes;
  int cont;

  for (int i=0; i<4; i++){
    cont = 0;
    aux_resposta = resposta;
    if(i==0){
      aux_continentes = head1;
    }else if(i==1){
      aux_continentes = head2;
    }else if(i==2){
      aux_continentes = head3;
    }else if(i==3){
      aux_continentes = head4;
    }

    for(int j=0; j<4; j++){
      if(strcmp(aux_resposta->pais, aux_continentes->pais) == 0){
        cont++;
        aux_resposta = aux_resposta->prox;
        aux_continentes = aux_continentes->prox;
      }else{
        break;
      }
    }

    if(cont==4){
      break;
    }
  }

  if(cont==4){
    return 1;
  }else{
    return 0;
  }
}

void substituir(char *pais, char geral[][50], int tamanho){
  for (int i = 0; i < tamanho; i++){
    if (strcmp(pais, geral[i]) == 0){
      strcpy(geral[i], "");
    }
  }
}

char *achar_continente(char *pais){
  for (int i = 0; i < 49; i++){

    if (strcmp(pais, europa[i]) == 0){
      return "Europa: ";
    }
  }

  for (int i = 0; i < 53; i++){
    if (strcmp(pais, africa[i]) == 0){
      return "Africa: ";
    }
  }

  for (int i = 0; i < 23; i++){
    if (strcmp(pais, americaCentralNorte[i]) == 0){
      return "America Central/Norte: ";
    }
  }

  for (int i = 0; i < 12; i++){
    if (strcmp(pais, americaSul[i]) == 0){
      return "America do Sul: ";
    }
  }

  for (int i = 0; i < 46; i++){
    if (strcmp(pais, asia[i]) == 0){
      return "Asia: ";

    }
  }

  for (int i = 0; i < 13; i++){
    if (strcmp(pais, oceania[i]) == 0){
      return "Oceania: ";
    }
  }
  return "Erro";
}