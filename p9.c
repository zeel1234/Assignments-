#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

FILE *ptr,*ft;
void insert(int);
void delete();
void display();
void read();

void main()
{
   int choice, value;
  // clrscr();
   printf("\n:: Queue Implementation using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Read Data \n5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: delete(); break;
	 case 3: display(); break;
	 case 4: read(); break;
	 case 5: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void insert(int value)
{
    ptr=fopen("queue_linked_list.txt","a");
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is Success!!!\n");
    fprintf(ptr,"%d\n",value);
    printf("\nData written !");
    fclose(ptr);
}
void delete()
{
    int data,info;
    if(front==NULL)
        printf("\nQueue is empty !");
    else
    {
        struct Node* temp;
        temp=front;

        data=temp->data;
        ptr=fopen("queue_linked_list.txt","r");
        ft=fopen("tempdata.txt","w+");
        rewind(ptr);
        while(fscanf(ptr,"%d\n",&info)!=EOF)
        {
            if(info!=data)
            {
                fprintf(ft,"%d\n",info);
            }
        }
        fclose(ptr);
        fclose(ft);
        remove("queue_linked_list.txt");
        rename("tempdata.txt","queue_linked_list.txt");

        front=front->next;

        printf("\n Deleted %d ",temp->data);
        free(temp);
    }
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
void read()
{
    ptr=fopen("queue_linked_list.txt","r");

    int info;

    struct Node* temp;
    temp=front;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            delete();
        }
    }
    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=info;
        newnode->next=NULL;
        if(front==NULL)
        {
            front=rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }

    printf("\nData Read !");
    fclose(ptr);
}
