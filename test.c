
#include<stdio.h>
FILE *fp;
struct customer
{

    char pnum[20];
};
int main()
{
    /*


    */
    fp = fopen("login.txt", "r");
    struct customer a[5];
    fscanf(fp,"%[^\n]", a[0].pnum);
    printf("%s", a[0].pnum);











    return 0;
}
