#include<stdio.h>
#include<conio.h>
#include<windows.h>

//Ignore THIS PART....
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//  this part is copied from Google..

FILE *fin;
FILE *fout;
char user[50];
char pass[10];

void login()
{
    system("CLS");
    printf("Please Enter Your Username and Password(no spaces) -- >\n");

    printf("Username : ");
    scanf("%s", user);
    fprintf(fout, "%s ", user);
    printf("\nPassword : ");
    scanf("%s", pass);
    fprintf(fout , "%s\n", pass);









}

void admin()
{

}
void sign()
{

}






int  main()
{

    fout = fopen("login.txt", "a");



    int choice;
    system("CLS");
    printf("1 . Login\n\n");
    printf("2 . Sign up\n\n");
    printf("3 . Admin \n\n");
    printf("4 . Exit\n\n");
    printf("Please Enter a Command > ");
    
    scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            sign();
            break;
        case 3:
            admin();
            break;
        }

    system("CLS");
    //fprintf(fout, "%d\n", choice);
























    return 0;
}
