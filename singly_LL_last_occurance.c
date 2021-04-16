/*2. Write a program which search last occurrence of particular element from
singly linear linked list.
Function should return position at which element is found.*/
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
int LastOccure(PPNODE Head,int iNo)
{   
    PNODE Temp=*Head;
    int pos=0,Var=0;
     while(Temp!=NULL)
     {
        pos++;
        if(Temp->Data==iNo)
        {
            if(pos>Var)
            {
                Var=pos;
            }
            
        }
         Temp=Temp->Next;

     }
     return Var;

}
int main()
{    int iValue=0,ret=0;
     PNODE First=NULL;
     InsertFirst(&First,61);
     InsertFirst(&First,51);
     InsertFirst(&First,61);
     InsertFirst(&First,31);
     InsertFirst(&First,51);
     InsertFirst(&First,61);
     Display(First);
     printf("\nEnter Number\t");
     scanf("%d",&iValue);
     ret=LastOccure(&First,iValue);
      printf("Last occurance of %d is: %d\n",iValue,ret);

     return 0;
}
