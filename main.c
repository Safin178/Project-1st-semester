#include<stdio.h>
#include<string.h>
FILE *fp;
FILE *fd;
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
{//ekon just update data te formality korte hobe
    getdata();
  
    
    scanf("%[^\n]", a[i].name);
    scanf(" %s ", a[i].username);
    scanf(" %s ", a[i].pnum);
    scanf(" %s", a[i].password);
     n++;
    writedata();
    fclose(fp);
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
    scanf(" %[^\n] ", f[l].foodname);
    scanf("%d", &f[l].price);
    l++;
    writefood();//baji eta temporary er theke beshi shohoz plus kom code..

    fclose(fd);
}










//                   end of Food                    //
//                        hehe                      //
//           login part of a Customer               //

void login()//formalities baki..
{
    getdata();
    char tuser[50];
    char tpass[24];
    scanf("%s", tuser);
    
    for(i = 0; i < n; i++)
    {
        if(strcmp(a[i].username, tuser) == 0 )
        {
            scanf("%s", tpass);
            if(strcmp(a[i].password, tpass) == 0)
            {
                printf("found you\n");
                return;
            }
            else
            {
                printf("Not found\n");
                return;
            }
        }
    }
    printf("Invalid username\n");





}





















//              End of login part                //
int main()
{
 
 
         //showdata();
         //updatedata();
           //updatefood();
       //getfood();
     
        login();

    return 0;
}



