/*4.Write a program which return largest element from singly linear linked
list.*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int Data;
  struct Node* Next;
};
  typedef struct Node NODE;
  typedef struct Node *PNODE;
  typedef struct Node **PPNODE;
void InsertFirst(PPNODE Head,int iNo)
{
   PNODE Newn=NULL;   
   Newn=(PNODE)malloc(sizeof(NODE));
   Newn->Data=iNo;
   Newn->Next=NULL;
   if(*Head==NULL)
   {
       *Head=Newn;
   }
   else
   {
      Newn->Next=*Head;
      *Head=Newn;
   }
}
void Display(PNODE Head)
{  
    while(Head!=NULL)
    {
         printf("|%d|->\t",Head->Data);
         Head=Head->Next;
    } 
    printf("|NULL|");

}

int LargeElement(PNODE Head)
{   int sum=0,temp=0;
    while(Head!=NULL)
    {
         if((Head->Data)>temp)
         {
             temp=Head->Data;
         }
         Head=Head->Next;

    } 
return temp;
}
int main()
{    int iValue=0,ret=0;
     PNODE First=NULL;
     InsertFirst(&First,61);
     InsertFirst(&First,51);
     InsertFirst(&First,61);
     InsertFirst(&First,31);
     InsertFirst(&First,91);
     InsertFirst(&First,61);
     Display(First);
     ret=LargeElement(First);
     printf("\n Laggest lement in LL= %d\n",ret);


    //  printf("%d",ret);
     return 0;
}
