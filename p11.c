 #include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int queue[SIZE];
int front=-1;
int rear=-1;
void insert(int);

int write()
{
   int num;
   FILE *fptr;
   fptr = fopen("e:\\numbers.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");
      return;
   }

   int i;
    for(i=front;i<=rear;i++)
        fprintf(fptr,"| %d | ",queue[i]);
    printf("\n");

   fclose(fptr);

}

int read()
{
	int num;
   FILE *fptr;

   if ((fptr = fopen("numbers.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

   while(fscanf(fptr,"%d",&num) == 1)
			insert(num);
   fclose(fptr);
}



void insert(int data)
{

    if(rear == -1)
        front=0;

    if(rear > SIZE)
        printf("\tQueue is Overflow  : \n");
    else
    {
        rear++;
        queue[rear]=data;
    }
}
void Delete()
{
    if(front > rear)
        printf("\tQueue is Underflow : \n");
    else
    {
        printf("\tDelete : %d\n",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(rear == -1 || front > rear)
        printf("\tQueue is Empty \n");
    //printf("Rear : %d\n",rear);
    //printf("Front : %d\n",front);
    printf("\t");
    for(i=front;i<=rear;i++)
        printf("| %d | ",queue[i]);
    printf("\n");
}
void main()
{
read();
	printf("\nData in file : ");
	display();
 int ch;
int data;
    	printf("\t*******MENU********\n");
             printf("\t 1. INSERT\n");
  	printf("\t 2. DELETE\n");
  	 printf("\t 3. DISPLAY\n");
  	 printf("\t 4. EXIT\n");
 do{
       		 printf("\tEnter Your Choice : ");
         		scanf("%d",&ch);
        		switch(ch)
     		   {
            			case 1:
    				printf("\t Enter Data : ");
    				scanf("%d",&data);
    		   	             insert(data);
             		 	write();
                         			 break;
            			case 2:
               			 Delete();
               			 write();
				break;
            			case 3:
                			display();
               			 break;
            			case 4:
                			return;
          			  default:
               	 		printf("\tEnter Proper Choice \n");
           			   	 break;
       		 }
    	}while(ch !=4);
}
