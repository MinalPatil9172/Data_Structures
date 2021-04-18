/*3. Write a program which display product of all digits of all element from
singly linear linked list. (Don’t consider 0)
Function Prototype :
void DisplayProduct( PNODE Head);
Input linked list : |11|->|20|->|32|->|41|
Output : 1 2 6 4*/


#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int Data;
  struct Node* Next;
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;
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
    printf("|NULL|\n");

}

void ProductOfDigit(PNODE Head)
{    int Rem=0,Mul=1;
       printf("Multiplication of Digits:\n");
      while(Head!=NULL)
      {
           while ((Head->Data)!=0)
           {
               Rem=(Head->Data)%10;
               Mul=Mul*Rem;
               Head->Data=(Head->Data)/10;
           }
            printf("%d\t",Mul);
           Mul=1;
          Head=Head->Next;
      }

    
}
int main()
{
    PNODE First=NULL;
    InsertFirst(&First,11);   
    InsertFirst(&First,44);
    InsertFirst(&First,28);
    InsertFirst(&First,151);
    InsertFirst(&First,17);
    InsertFirst(&First,787);

    Display(First);
    ProductOfDigit(First);
    return 0;
}



