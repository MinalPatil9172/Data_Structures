/*5. Write a program which return smallest element from singly linear linked
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

int SmallElement(PNODE Head)
{      
    int Temp=Head->Data;
    while(Head!=NULL)
      {
           
        if((Head->Data)<Temp)
        {
            Temp=Head->Data;
        }
        Head=Head->Next;
        
      }
      return Temp;
}
int main()
{    int iValue=0,ret=0;
     PNODE First=NULL;
     InsertFirst(&First,61);
     InsertFirst(&First,10);
     InsertFirst(&First,61);
     InsertFirst(&First,20);
     InsertFirst(&First,91);
     InsertFirst(&First,37);
     Display(First);
     ret=SmallElement(First);
     printf("\n Smallest lement in LL= %d\n",ret);


    //  printf("%d",ret);
     return 0;
}
