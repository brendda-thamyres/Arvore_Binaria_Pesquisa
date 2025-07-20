/*abp.c
implementação das funções
-Brendda Thamyres
*/

#define _ABP_C_
#include "abp.h"
#include <stdlib.h>
#include <string.h>

//cria a árvore
t_node *abpCreate(void *data)
{
    //alocando espaço para a árvore
    t_node *t = (t_node*)malloc(sizeof(t_node));

    if(t!= NULL) {
        //cria a raiz sozinha
        t->data = data; 
        t->l = NULL;
        t->r = NULL;

        return t;
    }   
    return NULL;
}

//visitação pos ordsem
void posOrdem(t_node *t, void(*visit)(void*))
{
    if(t!=NULL) {
        posOrdem(t->l, visit); //visita o nó da esquerda
        posOrdem(t->r, visit); //visita o nó dá direita
        visit(t->data); //visita o nó da raiz
    }
}

//consultar um elemento
void *abpQuery(t_node *t, void *key, int(*cmp)(void*,void*))
{
    int stat;
    if (t!=NULL) {
        stat = cmp(key, t->data);
        if(stat == 0) { //a chave e o campo data são iguais
            return t->data;
        } else {
            if(stat == -1) { //a chave é menor que o campo data
                return abpQuery(t->l, key, cmp); //avança para o lado esquerdo da arvore
            } else { //cmp = 1 (a chave é maior que o campo data)
                return abpQuery(t->r, key, cmp); //avança para o lado direito da arvore
            }
        }
    }
    return NULL; //nap achou nenhum valor igual a chave
}

//inserir um nó na arvore
t_node *abpInsert(t_node *t, void *data, int(*cmp)(void*, void*))
{
    t_node *newnode; //cria o novo nó a ser inserido;
    
    if (t!=NULL) {
        if(cmp(data, t->data) < 0) { //se o valor novo for menor que o data da arvore
            t->l = abpInsert(t->l, data, cmp); //desce no sentido esquerdo
            return t;
        } else {
            t->r = abpInsert(t->r, data, cmp); //se o valor novo for maior ou igual ao campo data, desce no sentido direito
            return t;
        }
    }
    newnode = (t_node*)malloc(sizeof(t_node)); //o novo nó é alocado
    if(newnode != NULL) {
        newnode->data = data;
        newnode->l = NULL;
        newnode->r = NULL;
        return newnode;
    }
    return NULL;

}

//acha o maior elemento da arvore esquerda
t_node *abpFindMax(t_node *t) {
    if (t == NULL) return NULL;
    while (t->r != NULL) {
        t = t->r;
    }
    return t;
}

//remove um no
void *abpRemove(t_node **t, void *key, int(*cmp)(void*, void*))
{
    if (*t != NULL) {
        int stat = cmp(key, (*t)->data);
        
        if (stat < 0) {
            return abpRemove(&((*t)->l), key, cmp);
        } else if (stat > 0) {
            return abpRemove(&((*t)->r), key, cmp);
        } else {
            // Nó encontrado , salva os dados antes de remover
            void *removedData = (*t)->data;
            t_node *nodeToRemove = *t;
            
            if ((*t)->l == NULL && (*t)->r == NULL) {
                // nó folha
                *t = NULL;
                free(nodeToRemove);
                return removedData;
            } else if ((*t)->l == NULL) {
                // só tem filho direito
                *t = (*t)->r;
                free(nodeToRemove);
                return removedData;
            } else if ((*t)->r == NULL) {
                // só tem filho esquerdo
                *t = (*t)->l;
                free(nodeToRemove);
                return removedData;
            } else {
                // tem dois filhos
                // Encontra o maior da subárvore esquerda
                t_node *max = abpFindMax((*t)->l);
                // Substitui o data 
                (*t)->data = max->data;
                // Remove o nó que foi copiado 
                abpRemove(&((*t)->l), max->data, cmp);
                return removedData;
            }
        }
    }
    return NULL;
}

//esvazia a árvore
int abpFree(t_node **t)
{
    if(*t != NULL) {
        abpFree(&((*t)->l));
        abpFree(&((*t)->r));

        if((*t)->data != NULL) {
            free((*t)->data);
        }
        free(*t);
        *t = NULL;

        return 1; //deu certo
    }
    return -1; //erro
}
//destrói a árvore;
void abpDestroy(t_node *t) {
    if(t != NULL) {
        abpDestroy(t->l);
        abpDestroy(t->r);
        if(t->data != NULL) {
            free(t->data);
        }
        free(t);
    }
}
