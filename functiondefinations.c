#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int uid;
    char *name;
    int birth_year;
    int voteattempt;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
void AddNewVoter(int uid, char *name, int birth_year)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newnode->uid = uid;
    newnode->name = name;
    newnode->birth_year = birth_year;
    newnode->voteattempt=1;
    newnode->next = NULL;
    ptr->next = newnode;
    newnode->prev = ptr;
}

void CreateVoterList()
{
    head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    struct Node *fourth = malloc(sizeof(struct Node));
    struct Node *fifth = malloc(sizeof(struct Node));
    struct Node *sixth = malloc(sizeof(struct Node));
    struct Node *seventh = malloc(sizeof(struct Node));
    struct Node *eighth = malloc(sizeof(struct Node));
    struct Node *nineth = malloc(sizeof(struct Node));
    struct Node *tenth = malloc(sizeof(struct Node));
    struct Node *eleventh = malloc(sizeof(struct Node));
    struct Node *twelveth = malloc(sizeof(struct Node));
    head->uid = 101;
    head->name = "Virat";
    head->birth_year = 1993;
    head->voteattempt = 1;
    head->prev = NULL;
    head->next = second;
    second->uid = 102;
    second->name = "Rohit";
    second->birth_year = 1978;
    second->voteattempt = 1;
    second->prev = head;
    second->next = third;
    third->uid = 103;
    third->name = "Mohit";
    third->birth_year = 1999;
    third->voteattempt = 1;
    third->prev = second;
    third->next = fourth;
    fourth->uid = 104;
    fourth->name = "Irfaan";
    fourth->birth_year = 2000;
    fourth->voteattempt = 1;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->uid = 105;
    fifth->name = "Ram";
    fifth->birth_year = 2002;
    fifth->voteattempt = 1;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->uid = 106;
    sixth->name = "Kajol";
    sixth->birth_year = 1995;
    sixth->voteattempt = 1;
    sixth->prev = fifth;
    sixth->next = seventh;
    seventh->uid = 107;
    seventh->name = "Neeta";
    seventh->birth_year = 2001;
    seventh->voteattempt = 1;
    seventh->prev = sixth;
    seventh->next = eighth;
    eighth->uid = 108;
    eighth->name = "Rekha";
    eighth->birth_year = 1992;
    eighth->voteattempt = 1;
    eighth->prev = seventh;
    eighth->next = nineth;
    nineth->uid = 109;
    nineth->name = "Preeti";
    nineth->birth_year = 1990;
    nineth->voteattempt = 1;
    nineth->prev = eighth;
    nineth->next = tenth;
    tenth->uid = 110;
    tenth->name = "John";
    tenth->birth_year = 1976;
    tenth->voteattempt = 1;
    tenth->prev = nineth;
    tenth->next = eleventh;
    eleventh->uid = 111;
    eleventh->name = "Bella";
    eleventh->birth_year = 1978;
    eleventh->voteattempt = 1;
    eleventh->prev = tenth;
    eleventh->next = twelveth;
    twelveth->uid = 112;
    twelveth->name = "Zara";
    twelveth->birth_year = 1983;
    twelveth->voteattempt=1;
    twelveth->prev = eleventh;
    twelveth->next = NULL;
}
void DisplayVoter()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\t %s\t \t%d\n", ptr->uid, ptr->name, ptr->birth_year);
        ptr = ptr->next;
    }
}

int Pos(int uid)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 1;
    ptr = head;
    while (ptr->uid != uid)
    {
        i++;
        ptr = ptr->next;
    }
    return i;
}
void Remove(int uid)
{
    int pos = Pos(uid);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    ptr = head;
    while (i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    if (head == NULL || ptr == NULL)
        return;
    if (head == ptr)
        head = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    free(ptr);
    return;
}
void PrintReverse()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    do
    {
        printf("Element: %d\n", ptr->uid);
        ptr = ptr->prev;
    } while (ptr != head);
    printf("Element: %d\n", ptr->uid);
}
void Search(char uid)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->uid != uid)
    {
        ptr = ptr->next;
    }
    printf("The voter is found\n");
    printf("Name: %s\n", ptr->name);
    printf("Birth Year: %d\n", ptr->birth_year);
}
int Find(int uid)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->uid != uid)
    {
        if(ptr!=NULL){
        ptr = ptr->next;
        }
        else{
            break;
        }
    }
    if(ptr->uid==uid){
        return ptr->birth_year;
    }
    else{
        return -1;
    }
    
}
int CheckAttempts(int uid)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->uid != uid)
    {
        if(ptr!=NULL){
        ptr = ptr->next;
        }
        else{
            break;
        }
    }
    if(ptr->uid==uid){
        return ptr->voteattempt;
    }
    else{
        return -1;
    }
    
}
void Voted(int uid)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr->uid != uid)
    {
        if(ptr!=NULL){
        ptr = ptr->next;
        }
        else{
            break;
        }
    }
    if(ptr->uid==uid){
        ptr->voteattempt=0;
    }
}
