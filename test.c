
#include "bst.h"
#include "stdio.h"
int main(){
    BST_NODE* tree = NULL;
    BST_NODE* aux = NULL;
    int op;
    int aux1;
    int continuos = 1;

    while(continuos == 1){
        scanf("%d", &op);
        switch (op){
            case 1:
                /* inserir */
                scanf("%d", &aux1);
                tree = BST_insert(tree, aux1);
                break;
            case 2:
                /* pre */
                BST_print(tree, BST_PRE);
                printf("\n");
                break;
            case 3:
                /* in */
                BST_print(tree, BST_IN);
                printf("\n");
                break;
            case 4:
                /* pos */
                BST_print(tree, BST_POS);
                printf("\n");
                break;
            case 5:
                /* remove */
                scanf("%d", &aux1);
                tree = BST_remove(tree, aux1);
                break;
            case 6:
                /* max element */
                BST_slimPrint(BST_maxNode(tree));
                printf("\n");
                break;
            case 7:
                /* min element */
                BST_slimPrint(BST_minNode(tree));
                printf("\n");
                break;
            case 8:
                /* height */
                printf("%lu\n", BST_height(tree));
                break;
            case 9:
                /* father */
                scanf("%d", &aux1);
                BST_slimPrint(BST_searchFather(tree, aux1));
                printf("\n");
                break;
            case 10:
                /* next */
                scanf("%d", &aux1);
                aux = BST_searchNext(tree, aux1);
                if(aux->key != aux1 || aux == NULL){
                    BST_slimPrint(aux);
                }else{
                    printf("-1");
                }
                printf("\n");
                break;
            case 11:
                /* previous */
                scanf("%d", &aux1);
                aux = BST_searchPrevious(tree, aux1);
                if(aux == NULL || aux->key != aux1){
                    BST_slimPrint(aux);
                }else{
                    printf("-1");
                }
                printf("\n");
                break;
            case 999:
                continuos = 0;
                break;
        }
    }
    return 0;
}