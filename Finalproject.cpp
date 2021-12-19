#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define BKSP 8

typedef struct Store
{
    signed int acno ; char name[20]; int balance;int pin ;struct Store *link;
}Store;
Store *root=NULL;
Store store[3];


FILE *fp,*ftemp;

void SWAP_REC()
{
    Store *temp=root;

    fp=fopen("Bank_management.txt","w");
    ftemp=fopen("Temporary.txt","r");
    while (fread(temp,sizeof(Store),1,ftemp))
    {
        fwrite(temp,sizeof(Store),1,fp);
    }
    fclose(fp);
    fclose(ftemp);
    
}


void Insert()
{
     int dh;
    Store * temp;
    temp=(Store*)malloc(sizeof(Store));
    printf("\nEnter The details of coustomer:");
    while((dh=getchar())!='\n')
    ;
    d:
    char pwd[5];
    fflush(stdin);
    int accno;
    printf("\nAccount Number: ");
    scanf("%d",&accno);
    bool found=false;
    fp=fopen("Bank_management.txt","r");
    while (fread(temp,sizeof(Store),1,fp))
    {
        if(temp->acno==accno)
        {
            found=true;
        }
    }
    if(found==true)
    {
        printf("\nAccount Number already exsist ");
        fflush(stdin);
        char ch;
        printf("\nDo you want to create new  account?(Y/N) ");
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            goto d;
        }
        else
        {
            return;
        }
        
    }
    else{
        temp->acno=accno;
    }
    fclose(fp);
    fflush(stdin);
    printf("\nName: ");
    gets(temp->name);
    printf("\nCreate Your pin(5 digit): ");
    int i=0;
    fflush(stdin);
    char ch;
    while(1)
    {
        ch=getch();
        if(ch==ENTER ||ch==TAB)
        {
            pwd[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
                i--;
                printf("\b \b");
         if(i<0)
         i=0;   
        }
        else
        {
            pwd[i]=ch;
            i++;
            printf("*  \b");
        }
    }
    int getpass=0;
    for(int i=0;i<5;i++)
    {
        getpass=getpass*10+(pwd[i]-'0');
    }
    temp->pin=getpass;
    printf("\nBalance: ");
    scanf("%d",&temp->balance);
    temp->link=NULL;

    if(root==NULL)
    root=temp;
    else
    {
        Store *p;
        p=root;
    
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    fp=fopen("Bank_management.txt","a");
        fwrite(temp,sizeof(Store),1,fp);  

    fclose(fp);
}
 

void Delete_rec()
{
    Store *temp;
    temp=root;
    int account_number;
    int money;
    
    bool found = false;
    z:
     fp=fopen("Bank_management.txt","r");
    printf("\nEnter Your Account Number: ");
    scanf("%d",&account_number);
    
    while (fread(temp,sizeof(Store),1,fp))
    {
        if (temp->acno==account_number)
        {
            found=true;
            break;
        }
        
    }

    if(found==false)
    {
        printf("\nAccount Number Not found");
        char ch;
        y:
        printf("\nDo you wish to continue:(Y/N) ");
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        goto z;
        else if(ch=='N'||ch=='n')
        return;
        else
        {
            printf("\nWrong Choice entered");
            goto y;
        }

    }
    else{
    fflush(stdin);
    char ch;
    x:
    printf("\nDo you want To Delete This account Permanently!!!");
    printf("\nType Y for Yes and N for No: ");
    scanf("%c",&ch);
     temp=root;
     fp=fopen("Bank_management.txt","r");
     ftemp=fopen("Temporary.txt","w");

        if(ch=='y'||ch=='Y')
        {
       
        while(fread(temp,sizeof(Store),1,fp))
        {
            if(temp->acno!=account_number)
            {
                fwrite(temp,sizeof(Store),1,ftemp);
            }
            
        }
        }
        else if (ch=='n'|| ch=='N')
        {
         return ;  
        }
        else
        {
            printf("\nWrong Choice Entered");
            goto x;
        }
        fclose(ftemp);
        fclose(fp);
        SWAP_REC();
    }
}


void No_of_records()
{
    Store *temp;
    temp=root;
    fp=fopen("Bank_management.txt","r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(Store);
    printf("\nNo of records in Databse are: %d",n);
    fclose(fp);
}


void Display()
{   
    char user[11]="pranjal@23";
    int pass=2303;
    char user_enter[11];
    int pass_enter=2303;
    int attempt=0;
    x:
    fflush(stdin);
    printf("\n\nEnter The Admins User Name: ");
    scanf("%s",&user_enter);
    printf("\nEnter The Password: ");
    scanf("%d",&pass_enter);
    if(strcmp(user_enter,user) && (pass_enter==pass))
    {
        //
    int dh;
    Store * temp;
    temp=(Store*)malloc(sizeof(Store));
    fp=fopen("Bank_management.txt","a");
    temp->acno=001;
    temp->balance=0;
    temp->link=NULL;

    if(root==NULL)
    root=temp;
    else
    {
        Store *p;
        p=root;
    
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
        fwrite(temp,sizeof(Store),1,fp);  

    fclose(fp);
    //
    temp=root;
     fp=fopen("Bank_management.txt","r");
     ftemp=fopen("Temporary.txt","w");
    while(fread(temp,sizeof(Store),1,fp))
        {
            if(temp->acno!=001)
            {
                fwrite(temp,sizeof(Store),1,ftemp);
            }
            
        }
        fclose(ftemp);
        fclose(fp);
        SWAP_REC();
    
    //

     printf("\nDetails Of all Entry Available: ");

        fp=fopen("Bank_management.txt","r");
     
        while(fread(temp,sizeof(Store),1,fp))
        {
            printf("\n%-30s \t %-20d \t %-20d\t%-20d\n",temp->name,temp->acno,temp->balance,temp->pin);
        } 
       
        fclose(fp);
    }
    
    else
    {
        attempt++;
        printf("\nwrong user name or password");
        if(attempt>=3)
        {
            printf("\nPermision Denied");
            exit (0);
        }
        goto x;
    }    
}


void  Transaction() 
{
    Store *temp;
    temp=root;
    int account_number;
    int money;
    
    bool found = false;
    z:
     fp=fopen("Bank_management.txt","r");
    printf("\nEnter Your Account Number: ");
    scanf("%d",&account_number);
    int pincode;
    printf("Enter Your Pin: ");
    scanf("%d",&pincode);
    
    while (fread(temp,sizeof(Store),1,fp))
    {
        if (temp->acno==account_number && temp->pin==pincode)
        {
            found=true;
            break;
        }
        
    }

    if(found==false)
    {
        printf("\nAccount Number Not found or Entered Pin is Wrong");
        char ch;
        y:
        fflush(stdin);
        printf("\nDo you wish to continue:(Y/N) ");
        scanf("%c",&ch);
       
        if(ch=='y'||ch=='Y')
        goto z;
        else if(ch=='N'||ch=='n')
        return;
        else
        {
            printf("\nWrong Choice entered");
            goto y;
        }

    }
    else{
    fflush(stdin);
    
    fflush(stdin);
    char ch;
    x:
    printf("\nDo you want Depsite or Widraw");
    printf("\nType D for Deposit and W for Widrawl: ");
    scanf("%c",&ch);
     temp=root;
     fp=fopen("Bank_management.txt","r");
     ftemp=fopen("Temporary.txt","w");

        if(ch=='d'||ch=='D')
        {
            printf("\nEnter the amount you want to Deposite: ");
            scanf("%d",&money);
       
        while(fread(temp,sizeof(Store),1,fp))
        {
            if(temp->acno==account_number && temp->pin==pincode)
            {
                
                temp->balance+=money;
                printf("\n%-30s \t %-20d \t %-20d\n",temp->name,temp->acno,temp->balance);
            }
            fwrite(temp,sizeof(Store),1,ftemp);
        }
        }
        else if (ch=='w'|| ch=='W')
        {
            printf("\nEnter the amount you want to Widraw: ");
            scanf("%d",&money);
          
     
        while(fread(temp,sizeof(Store),1,fp))
        {
            if(temp->acno==account_number && temp->pin==pincode)
            {
                if(((temp->balance)-money)<100)
                {
                    printf("Transation not Posible! Low Balance %d",temp->balance);
                }
                else
                {
                temp->balance-=money;
                printf("\n%-30s \t %-20d \t %-20d\n",temp->name,temp->acno,temp->balance);
                
                }
            
            }
            
        fwrite(temp,sizeof(Store),1,ftemp);
          
        }
        }
        else
        {
            printf("\nWrong Choice Entered");
            goto x;
        }
        fclose(ftemp);
        fclose(fp);
        SWAP_REC();
    }
}


void Search()
{
     Store *temp;
    temp=root;
     printf("\nEnter Account Number Of The User: ");
     int acount_number;
     scanf("%d",&acount_number);

        fp=fopen("Bank_management.txt","r");
     
        while(fread(temp,sizeof(Store),1,fp))
        {
            if(temp->acno==acount_number)
            printf("\n%-30s \t %-20d \t %-20d\n",temp->name,temp->acno,temp->balance);
        }
     
       
        fclose(fp);
}


void Shortlistbymoney()
{
     Store *temp;
    temp=root;
    printf("\nEnter Account for Sort listing: ");
    int money;
    scanf("%d",&money);
    fflush(stdin);
    char ch;
    x:
    printf("\nDo you want records Smaller Fromm Entered Amount Or Greter");
    printf("\nType S for Smaller and G for Greater: ");
    scanf("%c",&ch);
        if(ch=='g'||ch=='G')
        {
        fp=fopen("Bank_management.txt","r");
     
        while(fread(temp,sizeof(Store),1,fp))
        {
             if(temp->balance>=money)
            printf("\n%-30s \t %-20d \t %-20d\n",temp->name,temp->acno,temp->balance);
        }
        }
        else if (ch=='s'|| ch=='S')
        {
             fp=fopen("Bank_management.txt","r");
     
        while(fread(temp,sizeof(Store),1,fp))
        {
             if(temp->balance<=money)
            printf("\n%-30s \t %-20d \t %-20d\n",temp->name,temp->acno,temp->balance);
        }
        }
        else
        {
            printf("\nWrong Choice Entered");
            goto x;
        }
        
       
        fclose(fp);
}


int main()
{
 int choice;
while(1)
{
                printf("\nChoose the option:");
                printf("\n\n1.Insert Data\n");
                printf("2.Display all records of database\n");
                printf("3.Perform A Transaction\n");
                printf("4.Search By Acount Number\n");
                printf("5.Short List by Money \n");
                printf("6.Delete A record\n");
                printf("7.Number Of records\n");
                printf("8.exit\n");
                printf("Your choice: ");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    Insert();
                    break;
                case 2:
                    Display();
                    break;
                case 3:
                    Transaction();
                    break;
                case 4:
                    Search();
                    break;
                case 5:
                    Shortlistbymoney();
                    break;   
                case 6:
                    Delete_rec();
                    break;                      
                case 7:
                    No_of_records(); 
                      break;  
                case 8:
                    exit (0);
                   break;        
                default:
                    printf("wrong choise entered");
                    break;
                }
}

return 0;
}