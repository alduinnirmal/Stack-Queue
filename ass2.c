#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct linked_list
{
    int number;
    char name[20];
    float mark;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;

void create_linked_list();
void print_linked_list();
void insert_at_last(int value,char *name,float mark);
void insert_at_first(int value,char *name,float mark);
void insert_after(int key, int value,char *name,float mark);
void delete_item(int value);
void search_item(int value);
void sortList();

int main()
{
    int key, value,ch;
    char Name[20];
    float Mark;

    //Create a linked list
    printf("Create Linked List\n");
    create_linked_list();
    print_linked_list();

    do
    {
    printf("Menu\n 1.Insert\n 2.Delete\n 3.Search\n 4.Sort \n5.Exit\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch)
    {
        int choice;
    case 1://insertion
        printf("Enter RollNo:");
        scanf("%d",&value);
        printf("Enter Name:");
        scanf("%s",Name);
        printf("Enter Total Mark:");
        scanf("%f",&Mark);
        printf("Insertion Options\n1.Insert at front\n2.Insert at last\n3.Insert at random position\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1://front insertion
            printf("\nInserted new node at front\n");
            insert_at_first(value,Name,Mark);
            print_linked_list();
            break;
        case 2://last insertion
            printf("\nInserted new node at last\n");
            insert_at_last(value,Name,Mark);
            print_linked_list();
            break;
        case 3: //random insertion
            printf("\nEnter a KEY (existing item of List), after that you want to insert a value\n");
            scanf("%d", &key);
            printf("\nInserted new item after %d KEY\n", key);
            insert_after(key, value,Name,Mark);
            print_linked_list();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid choice\n");
            break;
        }
        break;

    case 2://deletion
        printf("\nEnter a value, which you want to delete from list\n");
        scanf("%d", &value);
        delete_item(value);
        print_linked_list();
        break;

    case 3: //search
        printf("\nEnter an item to search it from List\n");
        scanf("%d", &value);
        search_item(value);
        break;

    case 4://sort
        printf("Before sorting:");
        print_linked_list();
        sortList();
        printf("After sorting:");
        print_linked_list();
        break;

    case 5://exit
        exit(1);

    default:
        printf("\nInvalid choice\n");
    }
    }while(ch!=5);

    return 0;
}


/*
    User Defined Functions
*/
void create_linked_list()
{
    int val;
    char nam[20];
    float mar;

    while(1)
    {
        printf("Enter roll number(Enter -1 to exit):");
        scanf("%d", &val);
        if(val==-1)
            break;
        printf("Enter Name:");
        scanf("%s",nam);
        printf("Enter Total Mark:");
        scanf("%f",&mar);
        insert_at_last(val,nam,mar);
    }

}


void insert_at_last(int value,char *name,float mark)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    strcpy(temp_node->name,name);
    temp_node->mark=mark;
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}


void insert_at_first(int value,char *name,float mark)
{
    node *temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    strcpy(temp_node->name,name);
    temp_node->mark=mark;
    temp_node->next = head;

    head = temp_node;
}

void insert_after(int key, int value,char *name,float mark)
{
    node *myNode = head;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->number = value;
            strcpy(newNode->name,name);
            newNode->mark=mark;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("%d is inserted after %d\n", value, key);

            flag = 1;


            break;
        }
        else
            myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");

}


void delete_item(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}


void search_item(int value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->number==value)
        {
            printf("%d is present in this list. Memory address is %x\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}


void print_linked_list()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);
        printf("%s ",myList->name);
        printf("%7.2f\n",myList->mark);
        myList = myList->next;
    }
    printf("->");
}

 //sortList() will sort nodes of the list in ascending order
    void sortList() {
        //Node current will point to head
        struct linked_list *current = head, *index = NULL;
        int tempNum;
        float tempMark;
        char tempName[20];
        if(head == NULL) {
            return;
        }
            while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

                while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(current->number > index->number) {
                        tempNum = current->number;
                        current->number = index->number;
                        index->number = tempNum;
                        strcpy(tempName,current->name);
                        strcpy(current->name,index->name);
                        strcpy(index->name,tempName);
                        tempMark = current->mark;
                        current->mark = index->mark;
                        index->mark = tempMark;

                    }
                    index = index->next;
                }
                current = current->next;
            }
    }
