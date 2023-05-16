#include <stdio.h>
#include <string.h>

int hash_function(int h) {
    return (h * 19) % 101;
}

int add(char my_map[][25], char key[]) {
    int h, hash, new_hash;
    h = 0;
    for(int i=0; i<strlen(key); i++) {
        h += (int)key[i]*(i+1);
    }
    hash = hash_function(h);
    if(strcmp(my_map[hash], key) == 0) {
        return 0;
    } else {
        for(int j=1; j<=19; j++) {
            new_hash = (hash+(23*j)+(j*j))%101;
            if(strcmp(my_map[new_hash], key) == 0) {
                return 0;
            }
        }
    }
    if(strcmp(my_map[hash], "") == 0) {
        strcpy(my_map[hash], key);
        return 1;
    }
    for(int j=1; j<=19; j++) {
        new_hash = (hash+(j*j)+(23*j))%101;
        if(strcmp(my_map[new_hash], "") == 0) {
            strcpy(my_map[new_hash], key);
            return 1;
        }
    }
    return 0;
}

int del(char my_map[][25], char key[]) {
    for(int i=0; i<101; i++) {
        if(strcmp(my_map[i], key) == 0) {
            strcpy(my_map[i], "");
            return 1;
        }
    }
    return 0;
}

int main() {
    int N, m, number_of_entries;
    char op[25], key[25];
    char my_map[101][25];
    scanf("%d", &N);
    for(int testcase=0; testcase<N; testcase++) {
        scanf("%d", &m);
        number_of_entries = 0;
        for(int i=0; i<101; i++) {
            strcpy(my_map[i], "");
        }
        for(int operation=0; operation<m; operation++) {
            scanf("%s", op);
            if(strncmp(op, "ADD", 3) == 0) {
                strcpy(key, &op[4]);
                if(add(my_map, key)) {
                    number_of_entries += 1;
                }
            } else if(strncmp(op, "DEL", 3) == 0) {
                strcpy(key, &op[4]);
                if(del(my_map, key)) {
                    number_of_entries -= 1;
                }
            }
        }
        printf("%d\n", number_of_entries);
        for(int i=0; i<101; i++) {
            if(strcmp(my_map[i], "") != 0) {
                printf("%d:%s\n", i, my_map[i]);
            }
        }
    }
    return 0;
}
