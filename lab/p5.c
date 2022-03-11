#include <stdio.h>

void toh(int n,char from,char to,char aux)
{
    if(n==0)
    {
        printf("\nNo Disks Available");
        return;
    }
    if(n==1)
    {
        printf("\nMove disk 1 from %c to %c ",from,to);
        return;
    }
    else{
        toh(n-1,from,aux,to);
        printf("\nMove disk %d from %c to %c ",n,from,to);
        toh(n-1,aux,to,from);
    }
}

int main()
{
    int n;
    char a,b,c;
    printf("\nEnter Number of  Disks: ");
    scanf("%d",&n);
    toh(n,'a','b','c');
    return 0;
}
