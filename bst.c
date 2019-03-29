#include "bst.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

BST_NODE* BST_insert(BST_NODE* root, data_t key){
    if(root == NULL){
        root = (BST_NODE*) malloc(sizeof(BST_NODE));
        root->key = key;
        root->left = root->right = NULL;
        return root;
    }

    if(key < root->key){
        root->left = BST_insert(root->left, key);
    } else {
        root->right = BST_insert(root->right, key);
    }

    return root;
}

BST_NODE* BST_remove(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    BST_NODE* preOut = NULL;
    BST_NODE* out = NULL;
    if(root->key == key){
        //encontra o maior elemento da esquerda se puder
        if(root->left != NULL){   
            out = root->left;
            while(out->right != NULL){
                preOut = out;
                out = out->right;
            }
        }
        //Apenas apenas nao acontece com 2 filhos
        if(!((root->right != NULL) && (root->left != NULL))){
            if(out != NULL){
                if(preOut != NULL) {
                    preOut->right = out->left;
                    out->left = root->left;
                }
            } else
                out = root->right;
            free(root);
            return out;
        }
        //teoricamente sempre verdadeiro por causa do if anterior que se nao ouvece 2 filhos, nao chegaria aqui
        if(out != NULL){
            memcpy(&root->key, &out->key, sizeof(data_t));
            root->left = BST_remove(root->left, out->key);
        }else{
            //teoricamente impossivel
            root = NULL;
        }
        return root;
    }
    if(key < root->key && root->left != NULL){
        root->left = BST_remove(root->left, key);
    }else if(key > root->key && root->right != NULL){
        root->right = BST_remove(root->right, key);
    }
    return root;

}

BST_NODE* BST_remove2(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if(root->key == key){
        BST_NODE* aux = NULL;
        BST_NODE* out = NULL;
        if(root->left != NULL){
            out = root->left;
            while(out->right != NULL){
                aux = out;
                out = out->right;
            }
            if(aux != NULL){
                aux->right = NULL;
            }
            out->right = root->right;

            aux = out;
            while(aux->left != NULL){
                aux = aux->left;
            }
            if(root->left != aux){
                aux->left = root->left;
            } else {
                aux->left = NULL;
            }
            
        } else if(root->right != NULL) {
            out = root->right;
        }
        free(root);
        return out;
    }else if( key < root->key && root->left != NULL){
        root->left = BST_remove2(root->left, key);
    }else if( key > root->key && root->right != NULL){
        root->right = BST_remove2(root->right, key);
    }
    return root;
}

BST_NODE* BST_remove3(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if(root->key == key){
        BST_NODE* preOut = NULL;
        BST_NODE* out = NULL;
        if(root->left != NULL){
            out = root->left;
            while(out->right != NULL){
                preOut = out;
                out = out->right;
            }
            if(preOut != NULL){
                preOut->right = out->left;
                out->left = root->left;
            }
            out->right = root->right;
        } else if(root->right != NULL) {
            out = root->right;
        }
        free(root);
        return out;
    }else if( key < root->key && root->left != NULL){
        root->left = BST_remove3(root->left, key);
    }else if( key > root->key && root->right != NULL){
        root->right = BST_remove3(root->right, key);
    }
    return root;
}

BST_NODE* BST_search(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if(root->key == key){
        return root;
    } else if(key < root->key && root->left != NULL){
        return BST_search(root->left, key);
    } else if(key > root->key && root->right != NULL){
        return BST_search(root->right, key);
    }
    return NULL;
}

BST_NODE* BST_searchFather(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if((root->left != NULL && root->left->key == key) || (root->right != NULL && root->right->key == key)){
        return root;
    } else if(key < root->key && root->left != NULL){
        return BST_searchFather(root->left, key);
    } else if(key > root->key && root->right != NULL){
        return BST_searchFather(root->right, key);
    }
    return NULL;
}

BST_NODE* BST_searchNext(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if(root->key == key){
        if(root->right != NULL){
            BST_NODE* aux = root->right;
            while (aux->left != NULL){
                aux = aux->left;
            }
            return aux;
        }
        return root;
    } else if(key < root->key && root->left != NULL) {
        BST_NODE* aux = BST_searchNext(root->left, key);
        if(aux != NULL && aux->key == key){
            return root;
        }else{
            return aux;
        }
    } else if(key > root->key && root->right != NULL){
        return BST_searchNext(root->right, key);
    }
    return NULL;
}

BST_NODE* BST_searchPrevious(BST_NODE* root, data_t key){
    if(root == NULL) return root;
    if(root->key == key){
        if(root->left != NULL){
            BST_NODE* aux = root->left;
            while (aux->right != NULL){
                aux = aux->right;
            }
            return aux;
        }
        return root;
    } else if(key < root->key && root->left != NULL){
        return BST_searchPrevious(root->left, key);
    } else if(key > root->key && root->right != NULL){
        BST_NODE* aux = BST_searchPrevious(root->right, key);
        if(aux != NULL && aux->key == key){
            return root;
        }else{
            return aux;
        }
    }
    return NULL;
}

void BST_print(BST_NODE* root, int stade){
    if(root == NULL) return;

    if(stade == BST_PRE){
        printf("[%d]", root->key);
    }

    if(root->left != NULL){
        BST_print(root->left, stade);
    }

    if(stade == BST_IN){
        printf("%c", root->key);
    }

    if(root->right != NULL){
        BST_print(root->right, stade);
    }
    
    if(stade == BST_POS){
        printf("[%d]", root->key);
    }
}

void BST_slimPrint(BST_NODE* root){
    if(root == NULL) printf("-1");
    else printf("[%d]", root->key);
}

BST_NODE* BST_clear(BST_NODE* root){
    if(root == NULL) return root;

    if(root->left != NULL){
        BST_clear(root->left);
    }

    if(root->right != NULL){
        BST_clear(root->right);
    }
    
    free(root);
    return NULL;
}

BST_NODE* BST_maxNode(BST_NODE* root){
    if(root == NULL) return root;
    BST_NODE* out = root;
    while(out->right != NULL){
        out = out->right;
    }
    return out;
}

BST_NODE* BST_minNode(BST_NODE* root){
    if(root == NULL) return root;
    BST_NODE* out = root;
    while(out->left != NULL){
        out = out->left;
    }
    return out;
}

size64_t BST_height(BST_NODE* root){
    if(root == NULL) return 0;
    size64_t height = 1;
    
    if(root->left == NULL && root->right == NULL){
        return height;
    }
    size64_t leftHeight = BST_height(root->left);
    size64_t rightHeight = BST_height(root->right);

    if(leftHeight >= rightHeight){
        height += leftHeight;
    }else{
        height += rightHeight;
    }
    return height;
}