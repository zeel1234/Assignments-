
#include <stdio.h>
#include <stdlib.h>
 struct node
{
   struct node *prev;
    int n;
    struct node *next;
}*h,*temp,*temp1,*temp2;
int write()
{
   int num;
   FILE *fptr;
   fptr = fopen("e:\\linknum.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");
      return;
   }
    //printf("\n Linked list elements from begining : ");
   temp=h;
    while (temp != NULL)
    {
        fprintf(fptr," %d ", temp->n);
        temp= temp->next;
    }
   // printf(" %d ", temp2->n);


   fclose(fptr);
}
int read()
{
int num;
   	FILE *fptr;
 if ((fptr = fopen("e:\\linknum.txt","r")) == NULL){
      		 printf("Error! opening file");
exit(1);
  	 }
 	while(fscanf(fptr,"%d",&num) == 1)
 	  {
		insert1(num);
   }
   fclose(fptr);
}
void insert1(int);
void insert2(int);
void insert3(int);
void delete();
void display();
 int count = 0;
 void main()
{
	//read();
	//printf("\nData in file : \n");
	//display();
              int ch,n;
 	h = NULL;
temp = temp1 = NULL;
 	printf("\n******MENU******\n");
    	printf("\n 1 - Insert at beginning");
    	printf("\n 2 - Insert at end");
   	 printf("\n 3 - Insert at position i");
   	 printf("\n 4 - Delete at i");
    	printf("\n 5 - Display");
              printf("\n 6 - Exit");
do
    {
   	printf("\n Enter choice : ");
              scanf("%d", &ch);
       	 switch (ch)
        	{
       	 case 1:
        		   printf("\n Enter value to node : ");
		    scanf("%d", &n);
    insert1(n);
           		   write();
           		   break;
       	 case 2:
        		printf("\n Enter value to node : ");
                 	    scanf("%d", &n);
 insert2(n);
           		 write();
		break;
        	case 3:
        		printf("\n Enter value to node : ");
	              scanf("%d", &n);

            		insert3(n);
           		 write();
           		 break;
       	 case 4:
           		 delete();
           		 write();
            		break;
     	case 5:
	  	 display();
	  	 write();
	    	 break;
        	case 6:
            		exit(0);
        	default:
            		printf("\n Wrong choice menu");
        }
    }while(ch!=6);
}

/* TO create an empty node */
void create(int data)
{
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->n = data;
    count++;
}

/*  TO insert at beginning */
void insert1(int x)
{
    if (h == NULL)
    {
        create(x);
        h = temp;
        temp1 = h;
    }
    else
    {
        create(x);
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

/* To insert at end */
void insert2(int x)
{
    if (h == NULL)
    {
        create(x);
        h = temp;
        temp1 = h;
    }
    else
    {
        create(x);
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

/* To insert at any position */
void insert3(int x)
{
    int pos, i = 2;
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create(x);
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create(x);
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
/* To delete an element */
void delete()
{
    int i = 1, pos;
   printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to delete");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error : Empty list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deleted from list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            h = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}
void display()
{
	 temp2 = h;
              if (temp2 == NULL)
    	{
    	    printf("List empty to display \n");
    	    return;
    	}
    	printf("\n Linked list elements from begining : ");
 	while (temp2->next != NULL)
    	{
        		printf(" %d ", temp2->n);
        		temp2 = temp2->next;
    	}
   	 printf(" %d ", temp2->n);
}
