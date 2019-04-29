#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*top=NULL;

FILE *ptr,*ft;

void insert()
{
    int info;
    ptr=fopen("stack_linked_list.txt","a");

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&info);

    newnode->data=info;
    newnode->next=NULL;

    newnode->next=top;
    top=newnode;

    printf("\n INSERTED  !");

    fprintf(ptr,"%d\n",info);
    printf("\nData written into file !");
    fclose(ptr);

}



void pop()
{
    int data,info;
    if(top==NULL)
        printf("\nStack is empty !");
    else
    {
        struct node* temp;
        temp=top;

        data=temp->data;
        ptr=fopen("stack_linked_list.txt","r");
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
        remove("stack_linked_list.txt");
        rename("tempdata.txt","stack_linked_list.txt");

        printf("\nDeleted %d!",temp->data);
        top=temp->next;
        free(temp);
    }
}

void read()
{
    ptr=fopen("stack_linked_list.txt","r");

    int info;

    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=info;
        newnode->next=NULL;

        newnode->next=top;
        top=newnode;
    }

    printf("\nData Read !");
    fclose(ptr);
}

void Display()
{
    struct node* temp;

    temp=top;

    while(temp!=NULL)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice;

    while(choice!=5)
    {

        printf("*****MENU******\n");
        printf("\n1.Push\n2.Pop\n3.display\n4.read from file\n5.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            read();
            break;
        case 5:
            break;
        }
    }
}

