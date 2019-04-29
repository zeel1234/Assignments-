#include<stdio.h>
#include<string.h>
int number[2];
void swap (int *num1, int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}
void palindrome (int num1)
{
    int n1=num1;
    int d=0;
    printf ("value of num1 : %d\n", num1);
    while (num1  != 0)
    {
        d = d * 10;
        d = d + num1%10;
        num1= num1/10;
    }
    if (n1 == d)
    {
        printf (" %d is Palindrome \n", n1);
    }
    else
    {
        printf (" %d is not palindrome \n", n1);
    }
}
void read()
{
    FILE *fptr;
    int n;

    fptr = fopen("swap.txt","r");
    if(fptr == NULL)
    {
        printf("error\n");
    }

    int i=0;
    while (fscanf (fptr, "%d", &n)!= EOF)
    {
      	 number[i]=n;
 		 i++;
      }
    fclose(fptr);
}

int main()
{
    int num1, num2;
    read();
    num1=number [0];
    num2=number [1];
    void (*p) (int, int) =&swap;
    (*p) (&num1, &num2);
    printf("\n");
    printf ("Check This Two numbers are palindrome or not:\n");
    printf ("Number 1: \n");
    palindrome(num1);
    printf("\n");
    printf ("Number 2: \n");
    palindrome(num2);
}
