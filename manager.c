#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KEY 3

struct Entry {
    char name[50];
    char password[50];
};

struct Entry vault[100];
int count = 0;

void add_password();
void show_passwords();
void save_passwords();
void load_passwords();
void encrypt(char *text, int key);

int main(void){
    char master[50];
    printf("Master password: ");
    scanf("%s", master);
    if(strcmp(master, "1234") != 0){
        printf("Wrong password\n");
        return 1;
    }
    load_passwords();
    int choice;
    while(1){
        printf("\n1 = add, 2 = show, 3 = exit\n");
        scanf("%d", &choice);
        if(choice == 1){
            add_password();
        }
        else if(choice == 2){
            show_passwords();
        }
        else if(choice == 3){
            save_passwords();     
            break;
        }
        else{
            printf("choose the valid numbers\n");
        }
    }
}

void add_password(){
    printf("tell us your name\n");
    scanf("%s", vault[count].name);
    printf("tell us your password\n");
    scanf("%s", vault[count].password);
    ++count;
}

void show_passwords(){
    for(int i = 0; i < count; ++i){
        printf("%s: %s\n", vault[i].name, vault[i].password);
    }
}

void save_passwords(){
    FILE *file = fopen("password.txt", "w");
    for(int i = 0; i < count; ++i){
        encrypt(vault[i].name, KEY);         
        encrypt(vault[i].password, KEY);    
        fprintf(file, "%s %s\n", vault[i].name, vault[i].password);
    }
    fclose(file);
}

void load_passwords(){
    FILE *file = fopen("password.txt", "r");
    if(file == NULL){
        return;
    }
    while(fscanf(file, "%s %s", vault[count].name, vault[count].password) == 2){
        encrypt(vault[count].name, -KEY);       
        encrypt(vault[count].password, -KEY);    
        count++;
    }
    fclose(file);
}

void encrypt(char *text, int key){
    for(int i = 0; text[i] != '\0'; ++i){
        text[i] += key;
    }
}
