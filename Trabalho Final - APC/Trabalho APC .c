#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int quantidade_part = 0;

typedef struct jogador{
    int id;
    char nome[50];
    char posicao[4];
    int idade;
    int pontuacao_jog;
}Jogador;

typedef struct time{
    int id_jog;
    Jogador jogadores[5];
    char nome[50];
    char nome_tecnico[50];
}Time;
Time time;

typedef struct jogadores_partida{
    int num_assistencias;
    int num_mortes;
    int num_kills;
}JogadorPartida;

typedef struct resultados{
    int assistencias;
    int kills;
    int melhorpontuacao;
    int piorpontuacao;
}resultados;
resultados Resultados;


typedef struct partida{
    char MVP_nome[50], MVP_posicao[4];
    int total_kills_time;
    int total_kills_adversario;
    char vitoria;
    int total_torres_destruidas_time;
    int total_torres_destruidas_adversario;
    JogadorPartida jogadores_partida[5];
}Partida;
Partida partida[100];

void imprimi_menu() {
    printf("\n                       MENU\n");
    printf("[1] - Cadastrar time\n");
    printf("[2] - Listar time\n");
    printf("[3] - Editar time\n");
    printf("[4] - Cadastrar partida\n");
    printf("[5] - Listar partidas\n");
    printf("[6] - Pesquisar jogador\n");
    printf("[7] - Mostrar número total de kills e assistências\n");
    printf("[8] - Mostrar jogador com menor pontuação\n");
    printf("[9] - Mostrar jogador com maior pontuação\n");
    printf("[10] - Sair\n\n");
}
// procedimento usado para cadastrar os times
void cadastramento() {
    printf("                  CADASTRAR TIME\n");
    getchar();
    printf("Informe o nome do time: ");
    scanf("%[^\n]s", time.nome);
    getchar();
    printf("Informe o nome do técnico: ");
    scanf("%s", time.nome_tecnico);
    getchar();
// for usado para armazenar nome dos 5 jogadores e suas respectivas lanes
    for (int i = 0; i < 5; i++) {
        time.jogadores[i].id=i+1;
        printf("Informe o nome do jogador: \n");
        scanf("%s", time.jogadores[i].nome);

        printf("Informe a posição do jogador: \n");
        scanf("%s", time.jogadores[i].posicao);
// while usado para ler e aceitar a posição do jogador
        while ((strcmp(time.jogadores[i].posicao, "ADC") != 0) &&
               (strcmp(time.jogadores[i].posicao, "SUP") != 0) &&
               (strcmp(time.jogadores[i].posicao, "MID") != 0) &&
               (strcmp(time.jogadores[i].posicao, "TOP") != 0) &&
               (strcmp(time.jogadores[i].posicao, "JG") != 0) &&
               (strcmp(time.jogadores[i].posicao, "adc") != 0) &&
               (strcmp(time.jogadores[i].posicao, "sup") != 0) &&
               (strcmp(time.jogadores[i].posicao, "mid") != 0) &&
               (strcmp(time.jogadores[i].posicao, "top") != 0) &&
               (strcmp(time.jogadores[i].posicao, "jg") != 0)){
            printf("Erro! Tente novamente!");
            printf("Digite a posição do jogador: \n");
            scanf("%s", time.jogadores[i].posicao);
        }
        printf("Informe a idade do jogador: \n");
        scanf("%d", &time.jogadores[i].idade);

        while (time.jogadores[i].idade < 0 || time.jogadores[i].idade>150) {
            printf("Erro! Tente novamente! ");
            printf("Informe a idade do jogador: \n");
            scanf("%d", &time.jogadores[i].idade);
        }
    }


}
// procedimento usado para exibir uma lista dos times cadastrados
void listatimes() {
    printf("\n                   LISTA DO TIME\n\n");
    printf("Nome do Time: %s\n", time.nome);
    printf("Nome do Técnico: %s\n", time.nome_tecnico);
    printf("Jogadores:\n");
    printf("ID Nome Posição\n");
// for usado para armazenar o ID o NOME e a POSIÇÃO do jogador
    for (int i = 0; i < 5; i++) {
        printf("%d - ", time.jogadores[i].id);
        printf("%s - ", time.jogadores[i].nome);
        printf("%s \n", time.jogadores[i].posicao);
    }
}

// procedimento usado para cadastrar as partidas
void cadastramento_part() {
    int atuacao_jogador, MVP;

    printf("\n                CADASTRAR PARTIDAS\n\n");
// a partir daqui coletamos todas as informações da partida total de mortes total de torres destruídas etc
        printf("Informe a quantidade de kills do time: ");
        scanf("%d", &partida[quantidade_part].total_kills_time);
        while (partida[quantidade_part].total_kills_time < 0) {
            printf("Erro! Tente novamente!");
            printf("Informe a quantidade de kills do time: \n");
            scanf("%d", &partida[quantidade_part].total_kills_time);
        }

        printf("Informe a quantidade de kills do time adversário: ");
        scanf("%d", &partida[quantidade_part].total_kills_adversario);
        while (partida[quantidade_part].total_kills_adversario < 0) {
            printf("Erro! Tente novamente!");
            printf("Informe a quantidade de kills do time adversário: \n");
            scanf("%d", &partida[quantidade_part].total_kills_adversario);
        }
        getchar();
        printf("Venceu a partida? (s/n) ");
        scanf("%c", &partida[quantidade_part].vitoria);
        while (partida[quantidade_part].vitoria != 's' && partida[quantidade_part].vitoria != 'n') {
            printf("Erro! Tente novamente!\n");
            printf("Venceu a partida? (s/n) ");
            scanf("%c", &partida[quantidade_part].vitoria);
        }
        printf("Número de torres destruídas do seu time: ");
        scanf("%d", &partida[quantidade_part].total_torres_destruidas_time);
        while (partida[quantidade_part].total_torres_destruidas_time < 0 || partida[quantidade_part].total_torres_destruidas_time>11) {
            printf("Erro! Tente novamente!\n");
            printf("Número de torres destruídas do seu time: ");
            scanf("%d", &partida[quantidade_part].total_torres_destruidas_time);
        }
        printf("Número de torres destruídas do time adversário: ");
        scanf("%d", &partida[quantidade_part].total_torres_destruidas_adversario);
        while (partida[quantidade_part].total_torres_destruidas_adversario < 0 || partida[quantidade_part].total_torres_destruidas_adversario>11) {
            printf("Erro! Tente novamente!\n");
            printf("Número de torres destruídas do time adversário: ");
            scanf("%d", &partida[quantidade_part].total_torres_destruidas_adversario);
        }
        MVP = 0;

        for (int i = 0; i < 5; i++) {
            printf("Jogador %d\n", i + 1);
            printf("Número de assistência: ");
            scanf("%d", &partida[quantidade_part].jogadores_partida[i].num_assistencias);
            printf("Número de kills: ");
            scanf("%d", &partida[quantidade_part].jogadores_partida[i].num_kills);
            printf("Número de mortes: ");
            scanf("%d", &partida[quantidade_part].jogadores_partida[i].num_mortes);

            Resultados.kills += partida[quantidade_part].jogadores_partida[i].num_kills;
            Resultados.assistencias += partida[quantidade_part].jogadores_partida[i].num_assistencias;
            time.jogadores[i].pontuacao_jog+= partida[quantidade_part].jogadores_partida[i].num_assistencias + (partida[quantidade_part].jogadores_partida[i].num_kills * 3);

            atuacao_jogador = partida[quantidade_part].jogadores_partida[i].num_assistencias + (partida[quantidade_part].jogadores_partida[i].num_kills * 3);
// if utilizado para escolher o jogador que teve a melhor atuação em jogo
            if (atuacao_jogador > MVP) {
                MVP = atuacao_jogador;
                strcpy(partida[quantidade_part].MVP_nome, time.jogadores[i].nome);
                strcpy(partida[quantidade_part].MVP_posicao, time.jogadores[i].posicao);

            }
        }quantidade_part++;
}
// procedimento utilizado para imprimir lista dos jogos na tela
void lista_partida() {
    printf("\n                  LISTAR PARTIDAS\n\n");

// for utilizado para o usuário informar se a partida terminou em vitória ou derrota
    for (int i = 0; i < quantidade_part; i++) {
        if ((partida[i].vitoria == 's') || (partida[i].vitoria == 'S')) {
            printf("VITÓRIA!\n");
        }
        if ((partida[i].vitoria == 'n') || (partida[i].vitoria == 'N')) {
            printf("DERROTA!\n");
        }
        printf("Kills: %d\n", partida[i].total_kills_time);
        printf("Mortes: %d\n", partida[i].total_kills_adversario);
        printf("Torres destruidas pelo time: %d\n", partida[i].total_torres_destruidas_time);
        printf("Torres destruidas pelo adversário: %d\n\n", partida[i].total_torres_destruidas_adversario);
        printf("MVP:\nNome - Posição\n");
        printf("%s   -   %s\n\n\n", partida[i].MVP_nome, partida[i].MVP_posicao);
    }
}
// procedimento usado para encontrar jogador específico
void pesquisar(){
    int i;
    printf("\n                  PESQUISAR JOGADOR\n\n");
    printf("ID do jogador que deseja encontrar: ");
    scanf("%d", &time.id_jog);
    while (time.id_jog < 1 || time.id_jog>5) {
        printf("Erro! Tente novamente!\n");
        printf("Digite o ID do jogador que você deseja editar: ");
        scanf("%d", &time.id_jog);
    }
    i = time.id_jog - 1;

    printf("\n ID - Nome - Posição - Pontuação\n");
    printf(" %d  -  %s  -  %s  - %d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontuacao_jog);
}
// procedimento usado para imprimir resultados dos jogadores na tela
void imprimi_resultados() {
    printf("\n               KILLS E ASSISTÊNCIAS\n\n");
    printf("\nTotal de kills - Total de assistências \n");
    printf("%d                %d\n\n", Resultados.kills, Resultados.assistencias);
}
// procedimento que mostra jogador com pior atuação em jogo
void MVP_inverso() {
    printf("\n           JOGADOR COM MENOR PONTUAÇÃO\n\n");
    int n = 0;
    Resultados.piorpontuacao = time.jogadores[0].pontuacao_jog;
    for (int i = 0; i < 5; i++) {
        if (Resultados.piorpontuacao > time.jogadores[i].pontuacao_jog) {
            Resultados.piorpontuacao = time.jogadores[i].pontuacao_jog;
            n = i;
        }
    }
    printf("\n ID - Nome - Posição - Pontuação\n");
    printf(" %d  -  %s  -  %s  -  %d\n\n", time.jogadores[n].id, time.jogadores[n].nome, time.jogadores[n].posicao, time.jogadores[n].pontuacao_jog);
}
// procedimento que mostra jogador com melhor atuação em jogo
void MVP() {
    printf("\n           JOGADOR COM MAIOR PONTUAÇÃO\n\n");
    int n = 0;
    Resultados.melhorpontuacao = time.jogadores[0].pontuacao_jog;
    for (int i = 0; i < 5; i++) {
        if (Resultados.melhorpontuacao < time.jogadores[i].pontuacao_jog) {
            Resultados.melhorpontuacao = time.jogadores[i].pontuacao_jog;
            n = i;
        }
    }
    printf("\n ID - Nome - Posição - Pontuação\n");
    printf(" %d  -  %s  -  %s  -  %d\n\n", time.jogadores[n].id, time.jogadores[n].nome, time.jogadores[n].posicao, time.jogadores[n].pontuacao_jog);
}

// void usado para editar o time
void edicao() {
    int i;
    char verficar;
    printf("\n                  EDITAR TIME\n\n");
    printf("Informe o ID do jogador: ");
    scanf("%d", &time.id_jog);
// while limitando o ID do jogador entre 1 e 5
    while (time.id_jog < 1 || time.id_jog>5) {
        printf("Erro! Tente novamente!\n");
        printf("Informe o ID do jogador: ");
        scanf("%d", &time.id_jog);
    }
    i = time.id_jog - 1;

    printf("\n ID - Nome - Posição - Pontuação\n");
    printf(" %d  -  %s  -  %s  -  %d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontuacao_jog);
    getchar();
    printf("Você tem certeza? (s/n)  ");
    scanf("%c", &verficar);

    while ((verficar != 's') && (verficar != 'n') && (verficar != 'S') && (verficar != 'N')) {
        printf("Erro! Tente novamente!\n");
        printf("Você tem certeza? (s/n)  ");
        scanf("%c", &verficar);
    }
// if confirmando se o usuário quer realmente fazer uma edição no time
    if ((verficar == 's') || (verficar == 'S')) {
        getchar();
        printf("\nInforme o nome do jogador: ");
        scanf("%[^\n]s", time.jogadores[i].nome);
        printf("Informe a posição do jogador: ");
        scanf("%s", time.jogadores[i].posicao);
        while ((strcmp(time.jogadores[i].posicao, "ADC") != 0) &&
               (strcmp(time.jogadores[i].posicao, "SUP") != 0) &&
               (strcmp(time.jogadores[i].posicao, "MID") != 0) &&
               (strcmp(time.jogadores[i].posicao, "TOP") != 0) &&
               (strcmp(time.jogadores[i].posicao, "JG") != 0)  &&
               (strcmp(time.jogadores[i].posicao, "adc") != 0) &&
               (strcmp(time.jogadores[i].posicao, "sup") != 0) &&
               (strcmp(time.jogadores[i].posicao, "mid") != 0) &&
               (strcmp(time.jogadores[i].posicao, "top") != 0) &&
               (strcmp(time.jogadores[i].posicao, "jg") != 0)) {
            printf("Erro! Tente novamente!\n");
            printf("Digite a posição do jogador: ");
            scanf("%s", time.jogadores[i].posicao);
        }
        printf("Informe a pontuação do jogador: ");
        scanf("%d", &time.jogadores[i].pontuacao_jog);

        printf("\nID - Nome - Posição - Pontuação\n");
        printf("%d  -  %s  -  %s  -  %d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontuacao_jog);
    }
    if ((verficar == 'n') || (verficar == 'N')) {
        printf("\nSem alterações.\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int menu;

    do {
        imprimi_menu();
        printf("Informe o que deseja fazer: ");
        scanf("%d", &menu);
        system("cls");
        switch (menu) {
        case 1:
            cadastramento();
            break;
        case 2:
            listatimes();
            break;
        case 3:
            edicao();
            break;
        case 4:
            cadastramento_part();
            break;
        case 5:
            lista_partida();
            break;
        case 6:
            pesquisar();
            break;
        case 7:
            imprimi_resultados();
            break;
        case 8:
            MVP_inverso();
            break;
        case 9:
            MVP();
            break;
        case 10:
            printf("Tchau, Obrigado!\n");
            break;
        default:
            printf("Erro! Tente novamente!\n");
            break;
        }
    } while (menu != 10);
    return 0;
}
