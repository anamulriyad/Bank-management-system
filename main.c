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
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50];
    int opt,choice;
    char cont='y';
    float amount;


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
                printf("\n\t welcome %s",usr.phone);
            while(cont=='y'){
                system("clear");
                printf("\n press 1 for balance inquiry");
                printf("\n press 2 for depositing cash");
                printf("\n press 3 for cash withdraw");
                printf("\n press 4 for transfer the balance");
                printf("\n press 5 for password change");
                printf("\n\n your choice:\t");
                scanf("%d",&choice);

                switch(choice){
            case 1:
                printf("\n Your current balance is Rs.%.2f",usr.balance);
                break;
            case 2:
                printf("\n Enter the amount:\t");
                scanf("%f",&amount);
                usr.balance +=amount;
                fp=fopen(filename,"w");
                fwrite(&usr,sizeof(struct user),1,fp);
                if(fwrite != NULL) printf("\n Successfully deposited.");
                fclose(fp);
                break;
            case 3:
                  printf("\n Enter the amount:\t");
                scanf("%f",&amount);
                usr.balance -=amount;
                fp=fopen(filename,"w");
                fwrite(&usr,sizeof(struct user),1,fp);
                if(fwrite != NULL) printf("\n you have withdrawn Rs.%.2f",amount);
                fclose(fp);
                break;
            case 4:
                printf("\n please enter the phone number to transfer the balance:\t");
                scanf("%s",phone);
                printf("\n please enter the amount to transfer:\t");
                scanf("%f",&amount);
                 strcpy(filename,phone);

                fp=fopen(strcat(filename,".dat"),"r");
                if(fp==NULL) printf("\n account number not registered");
                else{
                fread(&usr1,sizeof(struct user),1,fp);
                fclose(fp);

                if(amount>usr.balance) printf("\n Insufficient balance");
                else{


                    fp=fopen(filename,"w");
                    usr1.balance += amount;
                    fwrite(&usr1,sizeof(struct user),1,fp);

                    fclose(fp);
                    if(fwrite != NULL){
                        printf("\n you have successfully transfered Rs.%.2f to %s",amount,phone);
                        strcpy(filename,usr.phone);
                        fp=fopen(strcat(filename,".dat"),"w");
                        usr.balance-=amount;
                        fwrite(&usr,sizeof(struct user),1,fp);
                        fclose(fp);
                    }
                }
                break;
            case 5:
                printf("\n please enter your new password:\t");
                scanf("%s",pword);
                fp=fopen(filename,"w");
                strcpy(usr.password,pword);
                fwrite(&usr,sizeof(struct user),1,fp);
                if(fwrite != NULL)
                    printf("\n password successfully changed");
                }
                break;
            default:
                printf("\n Invalid option");
                }
                printf("\n Do you want to continue the transaction [y/n] ");
                scanf("%s",&cont);
            }
        }
        else{
            printf("\n invalid password");
        }
    }
    }


    return 0;
}
