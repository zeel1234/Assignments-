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

void Print(struct node *root, int v1, int v2)
{
	if ( NULL == root )
		return;
	if ( v1 < root->data )
		Print(root->left, v1, v2);
	if ( v1 <= root->data && v2 >= root->data )
		printf("%d ", root->data );
	if ( v2 > root->data )
		Print(root->right, v1, v2);
}

//read data from file
void read_from_file()
{
    FILE *in_file;
    int n;
    in_file = fopen("BSTtree.txt","r");
    if(in_file == NULL)
    {
        printf("error \n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
		root=insert(root,n);
    }
    fclose(in_file);
}

void Display(struct node* root)
{
    if(root != NULL)
    {
        printf("%d \t",root->data);
        Display(root->left);
        Display(root->right);
    }
}

int main()
{
    int v1,v2;
	read_from_file();
	printf("\nBinary Tree : \n");
	Display(root);
	printf("\n\nEnter First Number : ");
	scanf("%d",&v1);
	printf("\nEnter second Number : ");
	scanf("%d",&v2);
	printf("\n");
	printf("Possible Keys Range Between %d and %d \n",v1,v2);
	printf("\n");
	Print(root,v1,v2);
	printf("\n\n");
}

