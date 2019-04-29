#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
int c=0;
void insert(int data)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
    }
    temp=head;
    while(temp != NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}
int length()
{
    struct node *temp;
    temp=head;
    while(temp != NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void powerset(struct node *v, struct node *up)
{
    if(v != NULL)
    {
            printf("%d",head->data);
            head=head->next;
    }
    else
    {
        struct node *t,*q;
        t=v->next;
        q=up->next;
        powerset(t,q);
        powerset(t,q);
    }
}

void main()
{
    insert(10);
    insert(20);
    //display();
    printf("\n\n");
    struct node *list;
    list=head;
    int n;
    n=length();
    powerset(list,head);
}
