/*write a program which reverse each element of singly linked list.
Function Prototype :
void Reverse( PNODE Head);
Input linked list : |11|->|28|->|17|->|41|->|6|->|89|
Output : |11|->|82|->|71|->|14|->|6|->|98|*/
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

void RevEle(PNODE Head)
{    int Rem=0,Rev=0;
     while(Head!=0)
     {
           while((Head->Data)!=0)
            {    
                Rem=(Head->Data)%10;
                Rev=Rev*10+Rem;
                Head->Data=(Head->Data)/10;
            }
               
              printf("%d\t",Rev);
                Head=Head->Next;
                Rev=0;
         
     }
    
}
int main()
{
    PNODE First=NULL;
    InsertFirst(&First,11);   
    InsertFirst(&First,13);
    InsertFirst(&First,28);
    InsertFirst(&First,11);
    InsertFirst(&First,17);
    InsertFirst(&First,49);

    Display(First);
    RevEle(First);
    return 0;
}


