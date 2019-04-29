#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 10

void push(int);
void pop();
void display();
void write_file();
void read_file();
int stack[SIZE], top = -1;

void main()
{
   int value, choice;
   //clrscr();
   while(1){
      printf("\n\n***** MENU *****\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Read Data\n5. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 push(value);
		 break;
	 case 2: pop();
		 break;
	 case 3: display();
		 break;
     case 4: read_file();
          break;
	 case 5: exit(0);
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}
void push(int value){
   if(top == SIZE-1)
      printf("\nStack is Full!!! Insertion is not possible!!!");
   else{
      top++;
      stack[top] = value;
      printf("\nInsertion success!!!");
      write_file();
   }
}
void pop(){
   if(top == -1)
      printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted : %d", stack[top]);
      top--;
   }
}
void display(){
   if(top == -1)
      printf("\nStack is Empty!!!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=top; i>=0; i--)
	 printf("%d\n",stack[i]);
   }
}

void write_file()
{
    //printf("write_into_file()\n");
	FILE *out_file;

    out_file = fopen("stack.txt","w");

    if(out_file == NULL)
    {
        printf("error\n");
    }
    int i=0;
    for(i=top;i>=0;i--)
    {
        fprintf(out_file,"%d\n",stack[i]);
        printf("\n Write Data in file !!");
    }
    fclose(out_file);
}

//read data from file
void read_file()
{
    int info;
    FILE *ptr;
    int n;

    ptr = fopen("stack.txt","r");

    if(ptr == NULL)
    {
        printf("error\n");
    }
     while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        top++;
        stack[top]=info;
    }

    printf("\nData Read !");
    fclose(ptr);
}
