#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int Data;
    struct Node *Next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head ,PPNODE Tail,int no)
{
   PNODE newn=NULL;
   newn=(PNODE)malloc(sizeof(NODE));
   newn->Data=no;
   newn->Next=NULL;
   
   
   if((*Head==NULL)&&(*Tail==NULL))
   {
     *Head=newn;
      *Tail=newn;
      newn->Next=newn;

   }

   else
   {
     newn->Next=*Head;
     *Head=newn;
     (*Tail)->Next=newn;
  
   }

}

void Display(PNODE Head ,PNODE Tail)
{
  do
  {
     printf("|%d| ",Head->Data);
     Head=Head->Next;

  } while (Head!=Tail->Next);
  
}

int  Count(PNODE Head ,PNODE Tail)
{
   int count=0;
  do
  {
     count++;
     Head=Head->Next;

  } while (Head!=Tail->Next);

            return count;
  
}

void InsertLast(PPNODE HeadF,PPNODE TailF,int iNo)
{   
   PNODE newn=NULL;
   newn=(PNODE)malloc(sizeof(NODE));
   newn->Data=iNo;
   newn->Next=NULL;

   if(*HeadF==NULL)
   {
      *HeadF=newn;
      *TailF=newn;
     newn->Next=newn;
   

   }
   else 
   {
        newn->Next=*HeadF;
        (*TailF)->Next=newn;
        *TailF=newn;
   }

}

void DeleteFirst(PPNODE HeadF,PPNODE TailF)
{
   if((*HeadF==NULL)&&(*TailF==NULL))
    {
       return;
    }
    else if(*HeadF==*TailF)
    {
      free(*HeadF);
      *HeadF=NULL;
      *TailF=NULL;

    }
    else
    {
           *HeadF=(*HeadF)->Next;
           free((*TailF)->Next);
           (*TailF)->Next=*HeadF;

    }

}

void DeleteLast(PPNODE HeadF,PPNODE TailF)
{
   if((*HeadF==NULL)&&(*TailF==NULL))
    {
       return;
    }
    else if(*HeadF==*TailF)
    {
      free(*HeadF);
      *HeadF=NULL;
      *TailF=NULL;

    }
    else
    {
         PNODE temp=*HeadF;
         while((temp->Next)!=(*TailF))
         {
            temp=temp->Next;
         }
         free(temp->Next);
         *TailF=temp;
         temp->Next=*HeadF;

    }

}

void InsertAtPos(PPNODE HeadF,PPNODE TailF,int iNo,int iPOS)
{

    PNODE temp=*HeadF;
    int i=0;

    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->Data=iNo;
    newn->Next=NULL;
    if((*HeadF==NULL)&&(*TailF==NULL))
   {
      InsertFirst(HeadF,TailF,iNo);    
   }
   else
   {
    for(i=1;i<iPOS-1;i++)
    {
        temp=temp->Next;

    }
    newn->Next=temp->Next;
    temp->Next=newn;
   }

}


void DeleteAtPos(PPNODE HeadF,PPNODE TailF,int iPOS)
{

    if((*HeadF==NULL)&&(*TailF==NULL))
     {
            return;
     }
     else if(*HeadF==*TailF)

     {
        return;

     }
     else
     {   
         int i=0;
           PNODE  temp=*HeadF;
           PNODE Target;
           for(i=1;i<iPOS-1;i++)
           {
                temp=temp->Next;

           }
              Target=temp->Next;
              temp->Next=Target->Next;
               free(Target);
           }
}
int main()
{
   PNODE Head=NULL;
   PNODE Tail=NULL;
  
   int iChoice=1,ino=0,iret=0,ipos=0;

   while(iChoice !=0)
    {
    printf("\nEnter the LINKEd List\n");
    printf("1: Insert Element in LL\n");
    printf("2: Display The LL\n");
    printf("3: Count  Element in LL\n");
    printf("4: Insert Last in LL\n");
    printf("5: Delete first  LL\n");
    printf("6: Delete Last  LL\n");
    printf("7: Insert At Position LL\n");
    printf("8: Delete At Position LL\n");
    printf("Enter case\n");
    scanf("%d",&iChoice);
    
    switch(iChoice)
    {
        
         case 1: 
        printf("Enter Element\n");
        scanf("%d",&ino);
        InsertFirst(&Head,&Tail,ino);
        break;


        case 2:
        Display(Head,Tail);
        break;

        case 3:
        iret=Count(Head,Tail);
        printf("%d",iret);
        break;

        case 4:
        printf("Enter Element\n");
        scanf("%d",&ino);
        InsertLast(&Head,&Tail,ino);
        break;

        case  5:
        DeleteFirst(&Head,&Tail);
        break;

        case  6:
        DeleteLast(&Head,&Tail);
        break;

        case  7:
        printf("Enter element\n");
        scanf("%d",&ino);
        printf("Enter position of element\n");
        scanf("%d",&ipos);
        InsertAtPos(&Head,&Tail,ino,ipos);
        break;



        case  8:
        printf("Enter position of element\n");
        scanf("%d",&ino);
        DeleteAtPos(&Head,&Tail,ino);
        break;

    }
    }
    return 0;
}

