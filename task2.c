#include <stdio.h>
#include <cstring>
using namespace std;

typedef union active{
     bool flag = true;
};
struct newUser{
    char username[50];
    char password[16];
    active test;
};

struct newUser users[500];
int idx = 0;

void Register(){
    char name[50], pass[16], flag[16];
    printf("\nEnter username:\n");
    scanf("%s", &name);
    printf("\nEnter password:\n");
    scanf("%s", &pass);
    printf("\nActive or not! (true || false) or (1 || 0):\n");
    scanf("%s", &flag);
    strcpy(users[idx].username, name);
    strcpy(users[idx].password, pass);
    if(!strcmp(flag, "1") || !strcmp(flag, "true")){
        users[idx].test.flag = 1;
    }
    else if(!strcmp(flag, "0") || !strcmp(flag, "false")){
        users[idx].test.flag = 0;
    }
    else{
        while(true){
            printf("\nPlease Enter (true || false) or (1 || 0)\n");
            if(!strcmp(flag, "1") || !strcmp(flag, "true")){
                users[idx].test.flag = 1;
                break;
            }
            else if(!strcmp(flag, "0") || !strcmp(flag, "false")){
                users[idx].test.flag = 0;
                break;
            }
        }
    }
    printf("\nDone\n\n");
    idx++;
}

void Login(){

    char name[50], pass[16];
    printf("\nEnter username:\n");
    scanf("%s", &name);
    printf("\nEnter password:\n");
    scanf("%s", &pass);

    bool flag = false, status;
    for(int i = 0; i < idx; ++i){
        char currName[50], currPass[16];
        strcpy(currName, users[i].username);
        strcpy(currPass, users[i].password);
        if(!strcmp(currName, name) && !strcmp(currPass, pass)){
            flag = true;
            status = users[i].test.flag;
            break;
        }
    }
    if(!status){
        printf("\nInactive account\n");
    }
    else{
        flag?printf("\nLogin Successfully\n\n"):printf("\nTry again!\n\n");
    }
}

int main(){
    while(true){
        printf("\nLogin -> 1\nRegister -> 2\nExit -> 3\n\n");
        int num;
        scanf("%d", &num);
        if(num == 1){
            Login();
        }
        else if(num == 2){
            Register();
        }
        else if(num == 3){
            return 0;
        }
        else{
            printf("\nInvalid choice\n\n");
        }
    }
}
