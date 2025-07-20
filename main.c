/*main.c
arquivo para executar o programa
-Brendda Thamyres*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"

typedef struct Animal {
    char nome[30];
    int idade;
    float peso;
} Animal;

int cmp(void *key, void *data)
{
   Animal *a1 = (Animal*)key;
   Animal *a2 = (Animal*)data;

   return strcmp(a1->nome, a2->nome);
}

void visit(void *data)
{
    if(data != NULL) {
        Animal *animal = (Animal*)data;
        printf("[Nome: %s \t Idade: %d \t Peso: %.2f]\n", animal->nome, animal->idade, animal->peso);
    }
}

//função especificada pra criar novo animal
Animal *criarAnimal(char *nome, int idade, float peso)
{
    Animal *newanimal = (Animal*)malloc(sizeof(Animal));
    if(newanimal != NULL){
        strcpy(newanimal->nome, nome);
        newanimal->idade = idade;
        newanimal->peso = peso;
    }
    return newanimal;
}


//função especificada para ler os dados do animal registrado

Animal *getData() {
    char nome[30];
    int idade;
    float peso;
    
    printf("\n-> Nome: "); scanf("%s", nome);
    printf("\n-> Idade: "); scanf("%d", &idade);
    printf("\n-> Peso: "); scanf("%f", &peso);

    return criarAnimal(nome, idade, peso);
}

//menu
int main()
{
    t_node *animais = NULL;
    int opcao;

    do 
    {
        printf("\n===== MENU =====\n");
        printf("--> Escolha uma opcao: \n");
        printf("1 - Criar arvore de registros\n");
        printf("2 - Cadastrar animal\n");
        printf("3 - Listar animais registrados\n");
        printf("4 - Consultar animal\n"); 
        printf("5 - Remover animal \n");
        printf("6 - Esvaziar registros\n");
        printf("7 - Destruir arvore de registros\n");
        printf("0 - Sair\n");
        printf("_____________________\ndigite: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        /*PRIMEIRO CAASO: CRIAR A ÁRVORE*/
        case 1:
            if(animais != NULL) {
                printf("\n[A arvore de registros já foi criada!]\n");
            } else {
                printf("\n--> Digite os dados do primeiro animal para criar a arvore:\n");
                Animal *a1 = getData();
                if(a1 != NULL) {
                    animais = abpCreate(a1);
                    printf("\n[Arvore de registros criada]\n");
                } else {
                    printf("\n[erro ao criar a arvore...]\n");
                }
            }
            break;

        /*SEGUNDO CASO: CADASTRAR ANIMAL*/
        case 2:
            if(animais == NULL) {
                printf("\n[A arvore esta vazia ou nao foi criada ainda!]\n");
                break;
            } else {
                int quantidade; 
                printf("\n--> Quantidade de animais para cadastrar: "); scanf("%d", &quantidade);
                
                //tratamento de erro para a quantidade
                if(quantidade <= 0 ){
                    printf("\nDigite uma quantidade valida: \n");
                    break;
                }

                int i;
                for(i = 0; i < quantidade; i++) {
                    printf("______%d de %d______", i + 1, quantidade);
                    Animal *newanimal = getData();

                    if(newanimal != NULL) {
                        animais = abpInsert(animais, newanimal, cmp);
                        printf("\n[Animal %d cadastrado]\n", i + 1);
                    } else {
                        printf("\n[Erro ao cadastrar]\n");
                    }
                }

            }

        break;


        /*TERCEIRO CASO: LISTAR ANIMAIS*/
        case 3:
            if(animais == NULL) {
                printf("\n[Erro ao listar - arvore vazia ou nao criada]\n");
            } else {
                printf("\n___Animais registrados:___\n");
                posOrdem(animais, visit);
            }

            break;
        
        /*QUARTO CASO: CONSULTAR ANIMAL*/
        case 4:
            if (animais == NULL) {
                printf("\n[arvore vazia ou nao criada]\n");
            } else {
                char key[30];
                printf("\nDigite o nome do animal: ");
                scanf("%s", key);

                Animal a;
                strcpy(a.nome, key);

                Animal *encontrado = (Animal *)abpQuery(animais, &a, cmp);
                if(encontrado != NULL) {
                    printf("\n [Nome: %s \t Idade: %d \t Peso: %.2f]\n" , encontrado->nome, encontrado->idade, encontrado->peso);
                } else {
                    printf("\n[Animal nao encontrado nos registros]\n");
                }
            }
            break;
        
        /*QUINTO CASO: REMOVER ANIMAL:*/
        case 5:
            if(animais == NULL) {
                printf("\n[Arvore vazia ou nao criada]\n");
            } else {

                char key[30];
                printf("Digite o nome: "); scanf("%s", key);

                Animal a;
                strcpy(a.nome, key);

                Animal *removido = (Animal*)abpRemove(&animais, &a, cmp);
                if(removido != NULL) {
                    printf("\n[Animal removido com sucesso!]\n");
                    printf("\n________________\nDados do animal removido:\n");
                    printf("[Nome: %s \t Idade: %d \t Peso: %.2f]\n", removido->nome, removido->idade, removido->peso);
                    // Libera a memória do animal removido
                    free(removido);
                } else {
                    printf("[Animal nao encontrado!]\n");
                } 

            }
            break;
        /*SEXTO CAS0: ESVAZIAR A ARVORE DE REGISTROS: */
        case 6:
            if(animais == NULL) {
                printf("\n[Arvore ja vazia.]\n");
            } else {
                abpFree(&animais);
                printf("\n[Registros excluidos.]\n");
            }

            break;
        
        /*SETIMO CASO: DESTRUIR A ARVORE*/
        case 7:
            if(animais == NULL) {
                printf("\n[Arvore destruida ou nunca criada]\n");
            } else {
                abpDestroy(animais);
                animais = NULL;
                printf("\n[Arvore de registros excluida]\n");
            }

            break;
        
        /*SAIR DO PROGRAMA*/
        case 0:
            printf("[[Programa finalizado. Obrigada por usar este TAD ABP!]]");
            if(animais != NULL) {
                abpFree(&animais);
            }
            break;
            
        //opcao invalid
        default:
            printf("\n[Opcao invalida, tente novamente]\n");
            break;
        }
    } while (opcao != 0);

    return 0;
    

}