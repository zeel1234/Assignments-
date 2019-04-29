
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* root;
struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->data = data;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if(data < r->data){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;
}

void Preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("[ %d ] -> ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
//read data from file
void read_from_file()
{
    FILE *in_file;
    int n;
    in_file = fopen("BSTtree.txt","r");
    if(in_file == NULL)
    {
     	   printf("error101\n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
	   root=insert(root,n);
    }
    fclose(in_file);
}

int queue[100];
int front=0;
int rear=-1;

void enQueue(struct node *new_node)
{
	queue[rear++] = new_node;
}

struct node *deQueue()
{
	if(front == rear)
   	 {
     	   return NULL;
  	  }
  	  else
  	  {
  	      return queue[front++];
      }
}
void printLevelOrder(struct node* root)
{
	struct node *temp_node = root;
	enQueue(root);
	while (temp_node != NULL)
	{
		printf("[ %d ] - > ", temp_node->data);

		if (temp_node->left != NULL)
      	 	{
          			  enQueue(temp_node->left);
    		}
		if (temp_node->right != NULL)
      	           {
            enQueue(temp_node->right);
        		}
		temp_node = deQueue();
	}
}

int main()
{
	read_from_file();
	printf("\n PreOrder Binary Tree : \n");
	Preorder(root);
	printf("\n\n");
	printf("\n Level Binary Tree : \n");
	printLevelOrder(root);
	printf("\n\n");
}
