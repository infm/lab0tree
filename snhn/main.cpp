#include "tree.h"

#include <stdio.h>

int main(){
    Tree* tree = new Tree();

    printf("Enter capacity of the tree: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int val;
        scanf("%d", &val);
        if (!(tree -> find(val))){
            if (!(tree -> insert(val)))
                printf("Error adding\n");
        } else {
            printf("Collision!\n");
        }
        tree -> traverse();
        printf("\n");
    }

    printf("Enter num of elements you wanna remove: ");
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int val;
        scanf("%d", &val);
        Node* candidate = tree -> find(val);
        if (candidate){
            tree -> remove(candidate);
            tree -> traverse();
            printf("\n");
        } else {
            printf("Tree doesn't have such a key\n");
        }
    }
    return 0;
}
