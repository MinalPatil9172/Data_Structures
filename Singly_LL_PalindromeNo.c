/*2. Write a program which display all palindrome elements of singly linked
list.
Function Prototype :
void DisplayPallindrome( PNODE Head);
Input linked list : |11|->|28|->|17|->|414|->|6|->|89|
Output : 11 6 414 */


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

void PalindromeNo(PNODE Head)
{    int Rem=0,Rev=0;
      printf("Palindrome Numbers are:\n");
     while(Head!=0)
     {     int Rem=0,Rev=0,No;
          No=Head->Data;
         while((Head->Data)!=0)
         {
              Rem=Head->Data%10;
              Rev=Rev*10+Rem;
              Head->Data=(Head->Data)/10;
         }
          if(No==Rev) 
           {
              printf("%d\t",No);

           }
        
         Head=Head->Next;
     }
     printf("\n");
    
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
    PalindromeNo(First);
    return 0;
}


