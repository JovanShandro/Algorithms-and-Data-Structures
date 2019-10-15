#include <iostream>
#include <cstdlib>

/*
    I have implemented a linked list 
    of integers using a struct to illustrate
    the function that reverses the list in 
    linear time
*/

struct list
{
    int info;
    struct list *next;
};
//adds one element to the front of the list 
struct list * push_front ( struct list * my_list , int value ) ;
//adds one element to the back of the list 
struct list * push_back ( struct list * my_list , int value ) ;
//reverses the list in linear time
void reverse_the_list(struct list **my_list);
//frees the memory allocated for the list
void dispose_list (struct list* my_list);
//prints the list
void print_list(struct list* my_list);

int main()
{
    char a;
    bool done = false;
    int n;
    struct list *my_list = NULL;
    std::cout<<"Problem 7.2 point A"<< std::endl;
    do
    {
        a = getchar();
        switch(a)
        {
            case 'a':
                scanf("%d",&n);
                getchar();
                my_list = push_back(my_list,n);
                break;
            case 'b':
                scanf("%d",&n);
                getchar();
                my_list= push_front(my_list,n);
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'e':
                dispose_list(my_list);
                done = true;
                break;
            case 'r':
                reverse_the_list(&my_list);
                break;
        }
    } while(!done);
 
    return 0;
}
 //the reversing algorithm
void reverse_the_list(struct list **my_list)
{

    /*  
        The algorithm performs in linear time as it has only one 
        loop that iterates over every element of the list
        It is in-situ as the only auxilliary memory it uses 
        is that of 3 struct pointers so it has O(1) space compl.
    */

    //previous stores previous node as the name suggests, 
    //cursor the current and temph stores the temporary head of the list
    struct list *temph, *previous=NULL, *cursor = *my_list;
    while(cursor != NULL)
    {
        temph         = cursor->next; //advance by one 
        cursor->next = previous;      //next becomes the previous for all nodes
        previous     = cursor;        //present now is previous 
        cursor       = temph;         //move the cursor to the next node
    }
    /*
    Basicly in each iteration of the loop the list has a 
    temporary head which is not in the end of beginning and
    this head is linked to the left elements and the others are on 
    the right. As the loop ends, together with the next line,
    the head is what once was the last struct of the list and 
    the order based on the links has been reversed
    */
    *my_list = previous;
}
 
struct list * push_front ( struct list * my_list , int value ) 
{
    struct list * newel ;
    newel = ( struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel -> info = value ;
    newel -> next = my_list;
    return newel;
}
 
struct list * push_back ( struct list * my_list , int value ) 
{
    struct list * cursor , * newel ;
    cursor = my_list ;
    newel = ( struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
 
    newel -> info = value ;
    newel -> next = NULL ;
    if ( my_list == NULL )
        return newel ;
    while ( cursor -> next != NULL )
        cursor = cursor -> next ;
    cursor -> next = newel ;
    return my_list ;
}
 
void dispose_list (struct list* my_list)
{
    struct  list *nextelem;
    while(my_list != NULL)
    {
        nextelem = my_list -> next;
        free(my_list);
        my_list = nextelem;
    }
}
 
void print_list(struct list* my_list)
{
    struct list *p;
    for(p = my_list; p; p = p->next)
    {
        printf("%d ",p->info);
    }
    printf("\n");
}
