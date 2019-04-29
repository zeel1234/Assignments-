
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL;

void insert(int n)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=NULL;
    }
}
//read data from file
void read_file()
{
    FILE *in_file;
    int n;
    in_file = fopen("Link_list.txt","r");
    if(in_file == NULL)
    {
        printf("error\n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
       // fscanf(in_file,"%d",&n1);
       insert(n);
    }
    fclose(in_file);
}
void write_file()
{
	FILE *out_file;
    out_file = fopen("Link_list.txt","w");

    if(out_file == NULL)
        printf("error\n");
    struct node * temp;
    temp=head;
    while(temp != NULL)
    {
        fprintf(out_file,"%d\n",temp->data);
        temp=temp->next;
    }
    fclose(out_file);
}
void find_duplicate()
{
    struct node *temp ,*temp1 ,*dup;
    temp=head;
    while(temp != NULL)
    {
         temp1=temp;
         while(temp1->next != NULL)
         {
             if(temp->data == temp1->next->data)
             {
                 dup=temp1->next;
                 temp1->next=temp1->next->next;
                 free(dup);
             }
             else
             {
                 temp1=temp1->next;
             }
         }
         temp=temp->next;
    }
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    temp=head;
    while(temp != NULL)
    {
         printf("| %d | -> ",temp->data);
         temp=temp->next;
    }
}
void main()
{
   read_file();
   printf("Link List : \n");
   display();
   find_duplicate();
   write_file();
   printf("\nAfter Removing The Duplicate Entry :\n");
   display();
}
