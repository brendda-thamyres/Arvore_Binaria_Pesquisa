
/*-----------------------------------------
abp.h
Arquivo com a especificação para o TAD Arvore Binaria de Pesquisa,
tipo de dado para uma coleção genérica.
Exemplo do curso: Estrutura de Dados I
___________________________________________
Autora: Brendda Thamyres Mendes Rodrigues
Data: Julho/2025
Professor: Anselmo Cardoso de Paiva (ACP)
------------------------------------------*/



#ifndef ABP_H
#define ABP_H
#define capacidade 10


typedef struct _tnode_ {
    void *data;
    struct _tnode_ *l;
    struct _tnode_ *r;
} t_node;



//funções:

t_node *abpCreate(void *data);
void posOrdem(t_node *t, void(*visit)(void*));
void *abpQuery(t_node *t, void *key, int(*cmp)(void*,void*));
t_node *abpInsert(t_node *t, void *data, int(*cmp)(void*, void*));
void *abpRemove(t_node **t, void *key, int(*cmp)(void*, void*));
int abpFree(t_node **t);
void abpDestroy(t_node *t);

#else
    extern t_node *abpCreate(void *data);
    extern void posOrdem(t_node *t, void(*visit)(void*));
    extern void *abpQuery(t_node *t, void *key, int(*cmp)(void*,void*));
    extern t_node *abpInsert(t_node *t, void *data, int(*cmp)(void*, void*));
    extern void *abpRemove(t_node **t, void *key, int(*cmp)(void*, void*));
    extern int abpFree(t_node **t);
    extern void abpDestroy(t_node *t);

#endif

/*_____________________________________________________________
abpCreate: cria a arvore
posOrdem: caminhamento da árvore
abpQuery: Consultar um dado
abpInsert: inserir um dado
abpRemove: remover um dado especifico
abpFree: esvazia a arvore
abpDestroy: destroi a arvore

*/

