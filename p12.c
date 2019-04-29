
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 int write()
{
   char c[25];
   FILE *fptr;
   fptr = fopen("e:\\string.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   int i;
   while(stack[i] != '\0')
   {
	printf("%c",stack[i]);
	i++;
   }
   fclose(fptr);
}
int read()
{
	char c[25],b;
	int i;
   FILE *fptr;

        if ((fptr = fopen("e:\\string.txt","r")) == NULL){
      	 printf("Error! opening file");
exit(1);
   }
 while(fscanf(fptr,"%c",&c) == 1)
                push(c);
 fclose(fptr);
}
void display()
{
	int i=0;
	char c[25];
	while(stack[i] != '\0')
	{
		printf("%c",stack[i]);
		i++;
    }

}
void main()
{
	read();
	printf("\nString in file : ");
	display();
  int i, choice;
   	 char s[MAX], b;
  	  while (1)
    	{
       		 printf("\n1-read string\n2-exit\n");
        		printf("enter your choice\n");
        		scanf("%d", &choice);
        		switch (choice)
       		 {
        			case 1:
          				for (i = 0;s[i] != '\0';i++)
            				{
               				 b = s[i];
               				 push(b);
               				 write();
           				}
            				for (i = 0;i < (strlen(s) / 2);i++)
            				{
                			if (stack[top] == stack[front])
                			{
                   				 pop();
                    				front++;
                    				write();
                			}
               			 else
               			 {
                    					printf("%s is not a palindrome\n", s);
                   					 break;
               			 }
            			}
            			if ((strlen(s) / 2)  ==  front)
               			 printf("%s is palindrome\n",  s);
            			front  =  0;
          			  top  =  -1;
           			 break;
        		case 2:
            			exit(0);
        		default:
            			printf("enter correct choice\n");
        	}
    }
}
void push(char a)
{
    top++;
    stack[top]  =  a;
}

void pop()
{
    top--;
}
