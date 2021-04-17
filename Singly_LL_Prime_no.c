/*2. Write a program which displays all elements which are prime from singly
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
    printf("|NULL|");

}
void PrimeNumber(PNODE Head)
{   
    printf("\nprime numbers are:\n");
     while(Head!=NULL)
     {    if(Head->Data==1)
             {
                    printf("%d neither prime nor composite\n",Head->Data);
             }
           
          else if(Head->Data==2)
          {
               printf("%d\n",Head->Data);
          }
          else
          {
          for(int i=2;i<=(Head->Data)/2;i++)
          {
               if((Head->Data)%i==0)
               {
                   // printf("\n not a prime number %d\n",Head->Data);
                    break;
               }

               if(i==(Head->Data)/2)
               {
                      printf("\n%d\n",Head->Data);
               }
          }
          }
            Head=Head->Next;
     }


}
int main()
{  
     PNODE First=NULL;
     InsertFirst(&First,1);
     InsertFirst(&First,2);
     InsertFirst(&First,3);
     InsertFirst(&First,9);
     InsertFirst(&First,13);
     InsertFirst(&First,11);
     InsertFirst(&First,7);
     InsertFirst(&First,2);
     Display(First);
     PrimeNumber(First);


     return 0;
}
