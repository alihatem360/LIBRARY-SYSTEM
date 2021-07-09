#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int  id;
    int quantity;
    char name[20];
} status;

void insert_book();
void delete_book_dy_id(int id);
void search_book_by_id (int id);
void search_by_name(char name[]);
void print_books_sorted_by_name();
void print_books();


int main()
{
    char c;

    do {
        printf("\n 1: Add new book \n");
        printf(" 2: Delete book by id \n");
        printf(" 3: search for book by id \n" );
        printf(" 4: search for book by name \n");
        printf(" 5: print books sorted by name \n");
        printf(" 6: print books \n");

        printf("\nEnter the number of option 1,2,3,4,5,6 \n");
        int x;
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        {   printf(" Entre the book id,quantity,name\n ");
            insert_book();
        }
        break;

        case 2:
        {   printf(" Enter the Book ID...:\n");
            int id;
            scanf("%d",&id);
            delete_book_dy_id(id);
        }
        break;

        case 3:
        {   printf(" Enter the Book ID...:\n");
            int id;
            scanf("%d",&id);
            search_book_by_id(id);
        }
        break;

        case 4:
        {   char key[20];
            printf(" Enter the Book name...\n");
            scanf("%s",key);
            search_by_name(key);
        }
        break;

        case 5:
        {   print_books_sorted_by_name();
        }
        break;

        case 6:
        {   print_books();
        }
        break;
        }
    } while( printf("\nAgiane Enter(y/n) ...\n"),(c=getche())=='y');
    return 0;


}

// functions      111111111111111111          ////////////////////////////////////////////////////////////
void search_book_by_id(int id)
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {
        fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    fclose(fptr);

    FILE *sta;
    sta=fopen(" booky.txt","w");

    for(int i=0; i<3; i++)
    {
        if( record[i].id ==id)
        {
             printf("\n\n       id      quantity    name...\n\n");
            printf("%10d%10d%10s\n",record[i].id,record[i].quantity,record[i].name);
            return;
        }

    }
    printf(" \nnot found...\n");

    fclose(sta);

}

///////////////// function 2222222222222   /////////////
void search_by_name(char name[])
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {
        fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    fclose(fptr);

    for(int pass=1; pass<3; pass++) ///////  for 1
    {
        for(int i=0; i<3-pass; i++) //////////// for 2
        {   int x;
            x=strcmp(record[i].name,record[i+1].name);
            if (x>0)  ////  IF START
            {
                {   char tmp[50];
                    strcpy(tmp,record[i].name);
                    strcpy(record[i].name,record[i+1].name);
                    strcpy(record[i+1].name,tmp);
                }

                {
                    int tmp;
                    tmp=record[i].id;
                    record[i].id=record[i+1].id;
                    record[i+1].id=tmp;
                }
                {
                    int tmp;
                    tmp=record[i].quantity;
                    record[i].quantity=record[i+1].quantity;
                    record[i+1].quantity=tmp;
                }
            }  ///// end of if
        } /////end of for 2
    }///////// end of for 1

    int low=0;
    int heigh=3;

    while(low<=heigh)
    {
        int middel=(low+heigh)/2;
        int x=strcmp(name,record[middel].name);

        if (x==0)
        {  printf("\n\n       id      quantity    name...\n\n");
            printf("%10d%10d%10s",record[middel].id,record[middel].quantity,record[middel].name);
            break;
        }
        if(x>0)
        {
            low=middel+1;
        }
        if (x<0)
        {
            heigh=middel -1;
        }
    } ;
    if(low>heigh)
    {
        printf("\n   you entered unavailable name...\n");
    }
}
//////////////////     function    3333333333333333 ///////////////////
void print_books_sorted_by_name()
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {
        fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    fclose(fptr);
    int x;
    for(int pass=1; pass<4; pass++)
    {
        for(int i=0; i<4-pass; i++)
        {
            x=strcmp(record[i].name,record[i+1].name);
            if (x>0)
            {
                {   char tmp[50];
                    strcpy(tmp,record[i].name);
                    strcpy(record[i].name,record[i+1].name);
                    strcpy(record[i+1].name,tmp);
                }
                {
                    int tmp;
                    tmp=record[i].id;
                    record[i].id=record[i+1].id;
                    record[i+1].id=tmp;
                }
                {
                    int tmp;
                    tmp=record[i].quantity;
                    record[i].quantity=record[i+1].quantity;
                    record[i+1].quantity=tmp;
                }
            }

        }
    }
    printf("\n\n       id      quantity    name...\n\n");

    for( int i=0; i<4; i++)
    {
        printf("%10d%10d%10s\n",record[i].id,record[i].quantity,record[i].name);
    }
}
/////////////////////// function 4444444444  //////////
void print_books()
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {   fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    fclose(fptr);
    printf("\n\n       id      quantity    name...\n\n");

    for( int i=0; i<4; i++)
    {
        printf("%10d%10d%10s\n",record[i].id,record[i].quantity,record[i].name);
    }
}
///////////////////// function 5555555555555 ////////////
void delete_book_dy_id( int id)
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {
        fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    rewind(fptr);

    FILE *sta;
    sta=fopen(" booky.txt","w");

    printf("\n\n       id      quantity    name...\n\n");
    for(int i=0; i<4; i++)
    {
        if( record[i].id !=id)
        {
            printf("%10d%10d%10s\n",record[i].id,record[i].quantity,record[i].name);
        }
    }
    fclose(sta);
}
/////////////////////  function 6666666666////////
void insert_book()
{
    status record[40];
    FILE *fptr;
    fptr=fopen("book.txt","r");
    int i=0;
    while( !feof(fptr))
    {
        fscanf(fptr,"%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
        i++;
    }
    fclose(fptr);
    scanf("%d%d%s",&record[i].id,&record[i].quantity,&record[i].name);
    fptr=fopen("book.txt","a");
    fprintf(fptr,"\n%d%6d%8s",record[i].id,record[i].quantity,record[i].name);
    fclose(fptr);

}

