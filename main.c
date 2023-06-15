#include<stdio.h>
#include<string.h>
#include<windows.h>
FILE *fp;
FILE *fd;
//Ignore THIS PART....
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//  this part is copied from Google..
 void getdata();
 void writedata();
void updatedata();
void showdata();
void getfood();
void writefood();
void updatefood();
void showfood();
void deletefood();
void login();
void credit();
struct customer
{
    char name[24];
    char username[24];
    char pnum[24];//phone number
    char password[24];//password max20 , minimum 8 char

};
struct food
{
    char foodname[50];
    int price;
};

struct customer a[1000];
struct food f[1000];
int i, n,l;
void getdata()
 {

      fp = fopen("login.txt", "r");
      fscanf(fp, "%d ", &n);
      for(i = 0 ; i < n ; i++)
      {
        fscanf(fp,"%[^\n]", a[i].name);
        fscanf(fp," %s ", a[i].username);
        fscanf(fp," %s ", a[i].pnum);
        fscanf(fp," %s ", a[i].password);
      }

      fclose(fp);
 }
void writedata()
{

    fp = fopen("login.txt", "w");
    fprintf(fp,"%d\n", n);
    for(i = 0 ; i < n; i++)
      {
        fprintf(fp, "%s\n", a[i].name);
        fprintf(fp,"%s\n", a[i].username);
        fprintf(fp,"%s\n", a[i].pnum);
        fprintf(fp,"%s\n", a[i].password);
      }


}
void updatedata()
{
    system("CLS");
    getdata();
    char temp;
    printf("Please Enter these info == >\n");
    printf("Name: ");
    scanf(" %[^\n]", a[n].name);
    printf("\nUsername: ");
    scanf("%s", a[n].username);
    printf("\nPhone Number: ");
    scanf("%s", a[n].pnum);
    printf("\nPassword: ");
    scanf("%s", a[n].password);
     n++;
    writedata();
    fclose(fp);
    printf("\n\nSign Up Done\n\n");

         printf("Press Any key and Enter to get back\n");
        scanf(" %c", &temp); 
}

void showdata()
{
    system("CLS");
    getdata();
     printf("We have total %d Customer ->\n\n", n);
     for(i = 0 ; i < n; i++)
      {
        printf("Customer No.%d\n\n", i+1);
        printf("Name: %s\n", a[i].name);
        printf("Username: %s\n", a[i].username);
        printf("Phone Number: %s\n", a[i].pnum);
        printf("Password: %s\n", a[i].password);
        printf("\n<------------->\n\n");
      }

}
void deletedata()
{
    int d;
    system("CLS");
    showdata();

    
    printf("Which Number do you Want to delete: ");
    scanf("%d", &d);
    d--;
    fp = fopen("login.txt", "w");
    fprintf(fp,"%d\n", n-1);
    for(i = 0 ; i < n; i++)
      {
        if(i == d)continue;
        fprintf(fp, "%s\n", a[i].name);
        fprintf(fp,"%s\n", a[i].username);
        fprintf(fp,"%s\n", a[i].pnum);
        fprintf(fp,"%s\n", a[i].password);
      }
      fclose(fp);
      system("CLS");
      printf("Updated New Data\n");
      showdata();
}
//                       Food                      //

void getfood()
{
    fd = fopen("foodmenu.txt", "r");
      fscanf(fd, "%d", &l);
      for(i = 0 ; i < l ; i++)
      {
        fscanf(fd," %[^\n] ", f[i].foodname);
        fscanf(fd,"%d", &f[i].price);

      }


      fclose(fd);
}
void writefood()
{
   fd = fopen("foodmenu.txt", "w");
    fprintf(fd,"%d\n", l);
    for(i = 0 ; i < l; i++)
      {
        fprintf(fd, "%s\n", f[i].foodname);
        fprintf(fd,"%d\n", f[i].price);
      }
}

void updatefood()
{
    getfood();
    int m;
    system("CLS");
    showfood();
    printf("How many items do you want to add: ");
    scanf("%d", &m);
    for(i = 0; i < m ; i++)
    {
        printf("Item Name: ");
        scanf(" %[^\n]", f[l+i].foodname);
        printf("Item Price: ");
        scanf("%d", &f[l+i].price);
    }
    l+=m;
    writefood();

    fclose(fd);
}

void add2cart()
{
    int j, itemnumber, sum = 0, number;
   
    printf("How many items do you want to buy: ");
    scanf("%d", &itemnumber);
    printf("Please write the numbers of those items[separately with spaces]: ");
    for(i = 0, j= 2 ; i < itemnumber; i++, j+=2)
    {
        
        scanf("%d", &number);
        sum += f[number-1].price;
    }
    
    printf("\nyou will have to pay: %d tk [cash on delivery]\n",sum);
    printf("\nYou will recieve your order to your google map location in a few minutes(Superfast)\n");
    
}

void showfood()
{
    system("CLS");
    getfood();
    printf("This is our Menu : \n");
    for(i = 0; i < l; i++)
    {
        printf("%d. %s",i+1,f[i].foodname);
        gotoxy(50 , i+1);
        printf("%d tk(%d)\n", f[i].price, i+1);
    }
     printf("--------------\n");
}

void deletefood()
{
    int d;
    system("CLS");
    showfood();//showfood ei getfood ase..

  
    printf("Which Number do you Want to delete: ");
    scanf("%d", &d);
    d--;
    fd = fopen("foodmenu.txt", "w");
    fprintf(fd,"%d\n", l-1);
    for(i = 0 ; i < l; i++)
      {
        if(i == d)continue;
        fprintf(fd, "%s\n", f[i].foodname);
        fprintf(fd,"%d\n", f[i].price);
      }
      fclose(fd);
      system("CLS");
      showfood();
}
//                   end of Food                    //





//           login part of a Customer               //

void login()//formalities baki..
{
    system("CLS");
    getdata();
    char tuser[50];
    char tpass[24], temp;
    int c2, c3;
    while(1)
    {
        system("CLS");
        printf("Please login == >\n");
        printf("Username: ");
        scanf("%s", tuser);

        for(i = 0; i < n; i++)
        {
            if(strcmp(a[i].username, tuser) == 0 )
            {
                while(1)
                {
                    system("CLS");
                    printf("We Found Your Username\n");
                    printf("Username: %s\n", tuser);
                    printf("Password: ");
                    scanf("%s", tpass);
                    if(strcmp(a[i].password, tpass) == 0)
                    {
                        //printf("found you\n");
                        showfood();
                        add2cart();
                        printf("\nPress Any key and Enter to get back OR press 0 to Exit\n");
                        scanf(" %c", &temp); 
                        if(temp == '0') {credit();}
                        return;
                        

                    }
                    else
                    {
                         printf("Wrong Password\n");
                         printf("Do you want to :\n");
                         printf("\t1. Try again\n");
                         printf("\t2. Exit\n");
                         printf("Please choose your command -> ");
                         scanf("%d",&c3);
                             if(c3 == 2)
                             {
                                return;
                             }

                    }
                }
            }
        }
         printf("\nInvalid username\n\n");
         printf("Do you want to :\n");
         printf("\t1. Try again\n");
         printf("\t2. Sign UP\n");
         printf("Please choose your command -> ");
         scanf("%d",&c2);
         if(c2 == 2)
         {
            updatedata();
         }





    }
}
//              End of login part                //
void admin()
{
     int c2,c3;
     char temp;
     char p[26];
     while(1)
     {
        system("CLS");
        printf("Please, Give Your Password[Admin]: ");
        scanf("%s", p);
        if(strcmp(p,"admin123") == 0)
        {
            break;
        }
        else{
             printf("Wrong Password\n");
                printf("Do you want to :\n");
                printf("\t1. Try again\n");
                printf("\t2. Exit\n");
                printf("Please choose your command -> ");
                scanf("%d",&c3);
                if(c3 == 2)
                {
                    return;
                }
        }
     }
    while(1)
    {
        system("CLS");
       
        printf("Assalamualaikum , Admin\n");
        printf("\nWhat can i do for you?\n");
        printf("\n1.Show food menu\n");
        printf("\n2.Add new Item\n");
        printf("\n3.Delete any item\n");
        printf("\n4.Show all customer info\n");
        printf("\n5.Delete a customer info\n");
        printf("\n0.Get back\n");

        printf("\nPlease choose your command -> ");
             scanf("%d",&c2);
             if(c2 == 1)
             {
                showfood();
                printf("Press Any key and Enter to get back\n");
               scanf(" %c", &temp); 
             }
             else if(c2  == 2)
             {
                updatefood();
                printf("Updated\n");
                printf("Press Any key and Enter to get back\n");
               scanf(" %c", &temp); 
             }
             else if(c2 == 3)
             {
                deletefood();
               printf("Press Any key and Enter to get back\n");
               scanf(" %c", &temp); 
             }
             else if(c2 == 4)
             {
                showdata();
                printf("Press Any key and Enter to get back\n");
               scanf(" %c", &temp); 
             }
             else if(c2 == 5)
             {
                deletedata();
                printf("\nUpdated Data\n");
                printf("Press Any key and Enter to get back\n");
               scanf(" %c", &temp); 
             }
             else if(c2 == 0)
             {
                return;
             }
    }

}
void credit()
{
    system("CLS");
    printf("\t\t\t\tThank You for using our service.\n\n\n");
    printf("\t\t\t\tA Project by :\n\n");
    printf("\t\t\t\tAfrin Hasan Safin\n\t\t\t\t\tRoll: C231062\n\n");
    printf("\t\t\t\tMASRUR AHMED CHOWDHURY\n\t\t\t\t\tRoll: C231080\n\n");
    printf("\t\t\t\tAMMAR BIN MANJUR\n\t\t\t\t\tRoll: C231046\n\n");
    printf("\t\t\t\tAlbar Hasan\n\t\t\t\t\tRoll: C231073\n\n");

    exit(0);



}


int main()
{


    int choice;
    //char c;
    while(1)
    {
            system("CLS");
        
        printf("WelCome to FOOD ENGINE\n\n");

        printf("<=========================>\n");
        printf("You Have 4 option: \n\n");
        printf("1. Login\n");
        printf("2. Sign Up\n");
        printf("3. Admin\n");
        printf("0. Exit\n\n");
        printf("Please choose your command -> ");
        scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                login();
                break;
            case 2:
                updatedata();
                break;
            case 3:
                admin();//pass:admin123
                break;
            case 0:
                credit();
                return 0;
            }
    }
    


    return 0;
}



