#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
char phone [50];
char ac[50];
char password[50];
float balance;
};
int main()
{
    struct user usr;
    int opt;


    printf("\n What do you want to do?");
    printf("\n\n 1.Register an account");
    printf("\n 2.Login to account");

    printf("\n\n Your choice:\t");
    scanf("%d",&opt);

    if(opt==1){
        system("clear");
        printf("Enter your account no:\t");
        scanf("%s",usr.ac);
        printf(" Enter your phone no:\t");
        scanf("%s",usr.phone);
        printf(" Enter your new password:\t");
        scanf("%s",usr.password);
        usr.balance=0;
    }
    return 0;
}
