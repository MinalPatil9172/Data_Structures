/*4. Write a program which return second maximum element from singly linear
linked list.*/
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
int SecMaxNo(PNODE Head)
{ 
    int sum=0,Temp=0,New=0;
     while(Head!=NULL)
     {    
           
            if((Head->Data)>Temp)
            {
                  New=Temp;
                  Temp=Head->Data;
            }
            Head=Head->Next;
           
     } 
    return New;
    
    
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
     ret= SecMaxNo(First);
    printf("\nSecond Largest  Number= |%d| \n",ret);

     return 0;
}
