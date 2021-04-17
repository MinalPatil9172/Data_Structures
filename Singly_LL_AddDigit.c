/*5. Write a program which display addition of digits of element from singly
linear linked list.*/
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
    printf("|NULL|\n");

}
void  AddDigit(PNODE Head)
{   int rem=0,sum=0;
      printf("Addition of Digits:\n");
     while(Head!=NULL)
     {      sum=0;
           while((Head->Data)!=0)
           {
             rem=(Head->Data)%10;
             sum=sum+rem;  
             Head->Data=Head->Data/10;
           }
           
           printf("%d\t",sum);
         Head=Head->Next;
     }

}
int main()
{    int ret=0;
     PNODE First=NULL;
     InsertFirst(&First,1);
     InsertFirst(&First,63);
     InsertFirst(&First,19);
     InsertFirst(&First,11);
     InsertFirst(&First,12);
     
     Display(First);
     AddDigit(First);


     return 0;
}
