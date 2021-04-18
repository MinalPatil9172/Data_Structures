/*4. Write a program which display smallest digits of all element from singly
linear linked list.
Function Prototype :
void DisplaySmall( PNODE Head);
Input linked list : |11|->|250|->|532|->|415|
Output : 1 0 2 1*/


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

void SmallestDigit(PNODE Head)
{    int Rem=0,Mul=1,Temp=9;
       printf("Smallst Digits from LL:\n");
      while(Head!=NULL)
      {
           while ((Head->Data)!=0)
           {
               Rem=(Head->Data)%10;
               if(Rem<Temp)
               {
                   Temp=Rem;
               }
               Head->Data=(Head->Data)/10;
           }
           printf("%d\t",Temp);  

          Head=Head->Next;
          Temp=9;
      }

    
}
int main()
{
    PNODE First=NULL;
    InsertFirst(&First,11);   
    InsertFirst(&First,34);
    InsertFirst(&First,28);
    InsertFirst(&First,150);
    InsertFirst(&First,57);
    InsertFirst(&First,87);

    Display(First);
    SmallestDigit(First);
    return 0;
}



