#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

void toh(int n,char from,char to,char aux)
{
    if(n==0)
    {
        printf("No disks available\n");
        return;
    }
    if(n==1)
    {
        printf("\nMove disc 1 from rod %c to %c ",from,to);
        return;
    }
    else{
    toh(n-1,from,aux,to);  // a b c
    printf("\nMove disc %d from rod %c to %c",n,from,to);
    toh(n-1,aux,to,from); // b c a
    }
}

int main()
{
    int n;
    char a,b,c;
    printf("\nEnter Number of Rods: ");
    scanf("%d",&n);
    toh(n,'a','c','b');
    return 0;
}

