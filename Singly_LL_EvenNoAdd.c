/*3. Write a program which returns addition of all even element from singly
linear linked*/
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
int EvenNumberAdd(PNODE Head)
{ 
    int sum=0;
     while(Head!=NULL)
     {
           if((Head->Data)%2==0)
             {
                  sum=sum+(Head->Data);
             }
            Head=Head->Next;
     } 
     return sum; 
    
}
int main()
{     int ret=0;
     PNODE First=NULL;
     InsertFirst(&First,1);
     InsertFirst(&First,6);
     InsertFirst(&First,13);
     InsertFirst(&First,11);
     InsertFirst(&First,12);
     
     Display(First);
     ret=EvenNumberAdd(First);
      printf("\nAddition of even numbers=%d\n",ret);

     return 0;
}
