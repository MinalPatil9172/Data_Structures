/*1. Write a program which search first occurrence of particular element from
     singly linear linked list.
     Function should return position at which element is found.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int Data;
   struct Node * Next;
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;
void InsertFirst(PPNODE Head,int iNo)
{
   PNODE Newn;
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
        printf("|%d|\t",Head->Data);
         Head=Head->Next;
         
   }
   
   printf("|NULL|\n");

}
void Posi(PNODE Head,int Value)
{
     int pos=0;
   while(Head!=NULL)
   {    
         pos++;

      if((Head->Data)==Value)
        {
            printf("First position of %d=%d\n",Value,pos);
             return;
        }    
    
         Head=Head->Next;
         
   }
   if(Head==NULL)
   {
       printf("Not valid keyword\n");
   }
   printf("\n");

}

int main()
{ 
   PNODE First=NULL,value;
   InsertFirst(&First,11);
   InsertFirst(&First,21);
   InsertFirst(&First,11);
    InsertFirst(&First,41);
     InsertFirst(&First,19);
   
   Display(First);
   printf("Enter value");
   scanf("%d",&value);
   Posi(First,value);
   return 0;
}
