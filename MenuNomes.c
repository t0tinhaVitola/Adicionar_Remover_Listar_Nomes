#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
==================================================================
AdicionarNomes

    A função adiciona nomes dentro de uma string por ponteiro e
deixa-os concatenados. Ex: OtavioRobertoLeonard...
==================================================================
*/
void AdicionarNome(char** nome){
    char* tempNome;
    tempNome = (char*)malloc(sizeof(char) * 30);
    scanf("%s", tempNome);

    if(*nome == NULL){
        *nome = (char*)malloc(sizeof(char) * strlen(tempNome) + 1);
        strcpy(*nome, tempNome);
    }else{
        *nome = realloc(*nome, (strlen(*nome) + strlen(tempNome) + 1));
        strcat(*nome, tempNome);
    }
    
    free(tempNome);
    return;
}
/*
=============================================================
RemoverNome

    Localiza e remove o nome dentro da string utilizada
para armazena-lo;
=============================================================    
*/
void RemoverNome(char** nome){
    char* tempNome;
    tempNome = (char*)malloc(sizeof(char) * 30);
    scanf("%s", tempNome);

    char* posicaoRemover = strstr(*nome, tempNome);

    if(strstr(*nome, tempNome) != NULL){
        memmove(posicaoRemover, posicaoRemover + strlen(tempNome), strlen(posicaoRemover + strlen(tempNome)) + 1);
        *nome = realloc(*nome, strlen(*nome) + 1);
    }
    if(strlen(*nome) == 0){
        nome = NULL;
    }
    free(tempNome);
    return;
}
/*
============================================================
Menu

    Menu simples, criado para o usuário escolher qual
função do programa ele irá utilizar até finalizar o
programa.
============================================================
*/
int Menu(int escolha, char** nome){
    switch(escolha){
        case 1:
            AdicionarNome(nome);
            break;
        case 2:
            RemoverNome(nome);
            break;
        case 3: 
            if(*nome != NULL){
                printf("%s\n", *nome);
            }else{
                printf("Nenhum nome registrado!\n");
            }
            break;
        case 4:
            return escolha;
        default:
            printf("Escolha invalida. Tente novamente!\n");
        }
    return escolha;
}

int main(){
    char *nome = NULL;
    int escolha;
    printf("Selecione [1] para Adicionar Nome;\nSeleciona [2] para Remover Nome;\nSelecione [3] para Listar Nomes registrados;\nSeleciona [4] para Sair.\n");
    while(escolha != 4){
        scanf("%d", &escolha);
        Menu(escolha, &nome);
    }
    printf("Finalizando programa...\n");
    if(nome != NULL){
        free(nome);
    }
    return 0;
}