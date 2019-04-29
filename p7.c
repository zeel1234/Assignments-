#include<stdio.h>
#include<stdlib.h>
struct tnode{
    int data;
    struct tnode *lchild;
    struct tnode *rchild;
};
struct tnode *Create(struct tnode *p,int value)
{
    struct tnode *temp,*temp1;
    if(p == NULL)
    {
        p=(struct tnode*)malloc(sizeof(struct tnode));
        if(p == NULL)
        {
            printf("Error : Allocating Memory \n");
            exit(0);
        }
        else
        {
            p->data = value;
            p->rchild=NULL;
            p->lchild=NULL;
        }
    }
    //if Root Node Exit
    else
    {
        temp=p;
        while(temp != NULL)
        {
            temp1=temp;
            if(temp1->data > value)
            {
                temp=temp->lchild;
            }
            else
            {
                temp=temp->rchild;
            }
        }

        if(temp1->data > value)
        {
            temp1->lchild=(struct tnode*)malloc(sizeof(struct tnode));
            temp1=temp1->lchild;
            if(temp1 == NULL)
            {
                printf("Error : Allocating Memory \n");
                exit(0);
            }
            else
            {
                temp1->data=value;
                temp1->rchild=temp1->lchild=NULL;
            }
        }
        else
        {
            temp1->rchild=(struct tnode*)malloc(sizeof(struct tnode));
            temp1=temp1->rchild;
            if(temp1 == NULL)
            {
                printf("Error : Allocating Memory \n");
                exit(0);
            }
            else
            {
                temp1->data=value;
                temp1->rchild=temp1->lchild=NULL;
            }
        }
    }
    return(p);
}
int findADepth(struct tnode *node)
{
   int d = 0;
   while (node != NULL)
   {
      d++;
      node = node->lchild;
   }
   return d;
}
int isPerfectRec(struct tnode* root, int d, int level)
{
    if (root == NULL)
        return 1;
    if (root->lchild == NULL && root->rchild == NULL)
        return (d == level+1);
    if (root->lchild == NULL || root->rchild == NULL)
        return 0;
    return isPerfectRec(root->lchild, d, level+1) &&
           isPerfectRec(root->rchild, d, level+1);
}


int isPerfect(struct tnode *root)
{
   int d = findADepth(root);
   return isPerfectRec(root,d,0);
}
struct tnode *root;
//read data from file
void read_from_file()
{
    FILE *in_file;
    int n;
    in_file = fopen("e:\\BSTtree.txt","r");
    if(in_file == NULL)
    {
        printf("error\n");
    }
    printf(" Binary Tree  : \n\n");
    while(fscanf(in_file,"%d",&n) != EOF)
    {
        printf("%d\t",n);
        root=Create(root,n);
    }
    fclose(in_file);
}
void  main()
{
    read_from_file();
    printf("\n\n");
    if (isPerfect(root))
        printf("This Binary Tree is Perfect : \n");
    else
        printf("This Binary Tree is Not Perfect  : \n");
    printf("\n");
}
