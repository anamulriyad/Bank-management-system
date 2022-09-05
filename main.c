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
    FILE *fp;
    char filename[50],phone[50],pword[50];
    int opt;


    printf("\n What do you want to do?");
    printf("\n\n 1.Register an account");
    printf("\n 2.Login to account");

    printf("\n\n Your choice:\t");
    scanf("%d",&opt);

    if(opt==1){
        system("clear");
        printf("Enter your account number:\t");
        scanf("%s",usr.ac);
        printf(" Enter your phone number:\t");
        scanf("%s",usr.phone);
        printf(" Enter your new password:\t");
        scanf("%s",usr.password);
        usr.balance=0;
        strcpy(filename,usr.phone);
        fp=fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite!=0){
            printf("\n\n Account successfully registered ");
        }else{
        printf("\n\n something went wrong please try again");
        }
        fclose(fp);
    }
    if("opt==2"){
        system("clear");
        printf("\n phone number:\t");
        scanf("%s",phone);
        printf("password:\t");
        scanf("%s",pword);
        strcpy(filename,phone);
        fp=fopen(strcat(filename,".dat"),"r");
        if(fp==NULL){
            printf("\n Account number not registered");
        }
        else{
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            printf("\n password matched");
        }
        else{
            printf("\n invalid password");
        }
    }
    }


    return 0;
}
