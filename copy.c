#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>
#include  <windows.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void input();
void writefile();
void search();
void output();

struct date
{
    int month;
    int day;
    int year;
};

struct account
{
    int number;
    char name[100];
    int acct_no;
    float mobile_no;
    char street[100];
    char city[100];
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    struct date lastpayment;
} customer;
int tl,sl,ts;
int main()
{
    int i,n;
    char ch;
    system("CLS");

    printf("   CUSTOMER BILLING SYSTEM:\n\n");
    printf("===============================\n");
    printf("\n1:    to add account on list\n");
    printf("2:    to search customer account\n");
    printf("3:    exit\n");
    printf("\n================================\n");
    do
    {
        printf("\nSelect what do you want to do? -> ");
        ch=getche();
    }
    while(ch<='0' || ch>'3');
    switch(ch)
    {
    case '1':
        system("CLS");
        printf("\nHow many customer accounts? -> ");
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            input();
            if(customer.payment>0)
                customer.acct_type=(customer.payment<0.1*customer.oldbalance)? 'O': 'D';
            else
                customer.acct_type=(customer.oldbalance>0)?'D' : 'C';
            customer.newbalance=customer.oldbalance - customer.payment;
            writefile();
        }
        main();
    case '2':
        system("CLS");
        printf("Search by what?\n");
        printf("\n1 --- search by customer number\n");
        printf("2 --- search by customer name\n");
        search();
        ch=getche();
        main();
    case '3':
        system("CLS");
        delay(3);
        //textcolor(RED);
        //gotoxy(25,25);
        COORD c;
        c.X = 40;
        c.Y = 10;

        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE), c);

        printf("\n\t\t\t\tA PROJECT BY Nusaiba, C223282");
        delay(15);

        exit(1);
    }
}


void input()
{
    FILE *fp=fopen("nusaiba.dat","rb");
    fseek (fp,0,SEEK_END);
    tl=ftell(fp);
    sl=sizeof(customer);
    ts=tl/sl;
    fseek(fp,(ts-1)*sl,SEEK_SET);
    fread(&customer,sizeof(customer),1,fp);
    printf("\ncustomer no: %d\n",++customer.number);
    fclose(fp);
    printf("         Account number: ");
    scanf("%d",&customer.acct_no);
    printf("\n       Name: ");
    scanf("%s",customer.name);
    printf("\n       mobile no: ");
    scanf("%f",&customer.mobile_no);
    printf("         Street: ");
    scanf("%s",customer.street);
    printf("         City: ");
    scanf("%s",customer.city);
    printf("         Previous balance: ");
    scanf("%f",&customer.oldbalance);
    printf("         Current payment: ");
    scanf("%f",&customer.payment);
    printf("         Payment date(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
    return;
}

void writefile()
{
    FILE *fp;
    fp=fopen("nusaiba.dat","ab");
    fwrite(&customer,sizeof(customer),1,fp);
    fclose(fp);
    return;
}

void search()
{
    char ch;
    char nam[100];
    int n,i,m=1;
    FILE *fp;
    fp=fopen("nusaiba.dat","rb");
    do
    {
        printf("\nenter your choice:   ");
        ch=getche();
    }
    while(ch!='1' && ch!='2');
    switch(ch)
    {
    case '1':
        fseek(fp,0,SEEK_END);
        tl=ftell(fp);
        sl=sizeof(customer);
        ts=tl/sl;
        do
        {
            printf("\nChoose customer number: ");
            scanf("%d",&n);
            if(n<=0 || n>ts)
                printf("\nPlease, Enter a correct customer number!\n");
            else
            {
                fseek(fp,(n-1)*sl,SEEK_SET);
                fread(&customer,sl,1,fp);
                output();
            }
            printf("\n\nWant to search again?(y/n) -> ");
            ch=getche();
        }
        while(ch=='y');
        fclose(fp);
        break;
    case '2':
        fseek(fp,0,SEEK_END);
        tl=ftell(fp);
        sl=sizeof(customer);
        ts=tl/sl;
        fseek(fp,(ts-1)*sl,SEEK_SET);
        fread(&customer,sizeof(customer),1,fp);
        n=customer.number;

        do
        {
            printf("\nEnter the customer name: ");
            scanf("%s",nam);
            fseek(fp,0,SEEK_SET);
            for(i=1; i<=n; i++)
            {
                fread(&customer,sizeof(customer),1,fp);
                if(strcmp(customer.name,nam)==0)
                {
                    output();
                    m=0;
                    break;
                }
            }
            if(m!=0)
                printf("\n\nSorry, Expected data doesn't exist!\n");
            printf("\nTry again?(y/n) -> ");
            ch=getche();
        }
        while(ch=='y');
        fclose(fp);
    }
    return;
}



void output()
{
    printf("\n\n    Customer no    :%d\n",customer.number);
    printf("    Name 	   :%s\n",customer.name);
    printf("    Mobile no      :%.f\n",customer.mobile_no);
    printf("    Account number :%d\n",customer.acct_no);
    printf("    Street         :%s\n",customer.street);
    printf("    City           :%s\n",customer.city);
    printf("    Old balance    :%.2f\n",customer.oldbalance);
    printf("    Current payment:%.2f\n",customer.payment);
    printf("    New balance    :%.2f\n",customer.newbalance);
    printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
    printf("    Account status :");
//	   textcolor(128+RED);
    switch(customer.acct_type)
    {
    case 'C':
        printf("CURRENT\n\n");
        break;
    case 'O':
        printf("OVERDUE\n\n");
        break;
    case 'D':
        printf("DELINQUENT\n\n");
        break;
    default:
        printf("ERROR\\n\n");
    }

    return;
}