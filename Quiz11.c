#include <stdio.h>
#include <string.h>
#define MAX 50
void registernum();
void allprint();
void personalprint();
typedef struct phonenumeber{
    char name[20];
    char number[20];
    struct phonenumeber *next;
} PHONE;
PHONE book[MAX];
PHONE *ptr = book;
int i=0;
int size=0;

int main(void)
{   static int count_pw = 0;
    char pw[10];
    char realpw[10]={"qwer1234"};
    int service = 0;
    do {
    if (service==5) 	break;
    printf("\n <<< 1. Register  2. Print all 3. Find certain number 4. Delete certain number 5. Exit>>>\n");
    printf("Choose your service number\n");
    scanf("%d",&service);
        switch( service ) {
            case 1:
                while(count_pw<3){
                    printf("Input PW : ");
                    scanf("%s", pw);
                    if (strcmp(pw,realpw)!=0){
                        count_pw++;
                        printf("Incorrect password %d/3\n", count_pw);
                    }
                    else {
                        registernum();
                        count_pw = 0;
                        break;
                    }
                }
                if (count_pw == 3) {
                    printf("You cannot register!\n");
                    service = 4;
                }
                break;
            case 2:
                allprint();
                break;
            case 3:
                personalprint();
                break;
            case 4:
                deletenum();
                break;
        }
    } while (1);
    printf("Exiting program...\n");
    return 0;
}

void registernum(){

    printf("name :");
    scanf("%s",book[size].name);
    printf("phonenumeber :");
    scanf("%s",book[size].number);
    printf("Register completed!\n");
    size++;
}

void allprint(){
    printf("<< read phonebook >>\n");
    int i=0;
    while (i<size) {
         printf("[%s : %s]\n", book[i].name, book[i].number);
             i++;
    }
}
void personalprint(){
    static char buff[20];
    int i;

    printf("Type the person's name you wanna find : ");
    scanf("%s", buff);
    for (i=0;i<size;i++){
        if(strcmp((*(ptr+i)).name,buff)==0){
        printf("[%s : %s]\n", book[i].name, book[i].number);
        }
    }
}
void deletenum(){
    static char buff[20];
    int i,j ;
    printf("Type the person's name you wanna delete : ");
    scanf("%s", buff);
    for (i=0;i<size;i++){
        if(strcmp((ptr+i)->name,buff)==0){
            for(j=i;j<size-1;j++){
            book[j]=book[j+1];
            }
            size--;
        }
    }
    printf("Information of %s deleted successfully!\n", buff);

}

