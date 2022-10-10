#include<stdio.h>
#include<stdlib.h>
struct Node1
{
    int uid;
    char *name;
    char *party;
    int vote;
    struct Node1 *prev;
    struct Node1 *next;
};
struct Node1 *start = NULL;
void AddNewCandidate(int uid, char *name, char *party)
{
    struct Node1 *newNode1 = (struct Node1 *)malloc(sizeof(struct Node1));
    struct Node1 *ptr = (struct Node1 *)malloc(sizeof(struct Node1));
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode1->uid = uid;
    newNode1->name = name;
    newNode1->party= party;
    newNode1->vote=0;
    newNode1->next = NULL;
    ptr->next = newNode1;
    newNode1->prev = ptr;
}
void CreateCandidateList()
{
    start = malloc(sizeof(struct Node1));
    struct Node1 *second = malloc(sizeof(struct Node1));
    struct Node1 *third = malloc(sizeof(struct Node1));
    struct Node1 *fourth = malloc(sizeof(struct Node1));
    struct Node1 *fifth = malloc(sizeof(struct Node1));
    struct Node1 *sixth = malloc(sizeof(struct Node1));
    start->uid = 101;
    start->name = "Modi";
    start->party = "BJP";
    start->vote = 0;
    start->prev = NULL;
    start->next = second;
    second->uid = 102;
    second->name = "Rohit";
    second->party = "INC";
    second->vote = 0;
    second->prev = start;
    second->next = third;
    third->uid = 103;
    third->name = "Mohit";
    third->party = "AAP";
    third->vote = 0;
    third->prev = second;
    third->next = fourth;
    fourth->uid = 104;
    fourth->name = "Irfaan";
    fourth->party = "JDU";
    fourth->vote = 0;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->uid = 105;
    fifth->name = "Ram";
    fifth->party = "NCP";
    fifth->vote = 0;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->uid = 106;
    sixth->name = "Kale";
    sixth->party = "IND";
    sixth->vote = 0;
    sixth->prev = fifth;
    sixth->next = NULL;
}
void DisplayCandidate()
{
    struct Node1 *ptr = (struct Node1 *)malloc(sizeof(struct Node1));
    ptr = start;
    while (ptr != NULL)
    {
        printf("Element: %d\t %s\t \t%s\n", ptr->uid, ptr->name, ptr->party);
        ptr = ptr->next;
    }
}
void SearchCandidate(char uid)
{
    struct Node1 *ptr = (struct Node1 *)malloc(sizeof(struct Node1));
    ptr = start;
    while (ptr->uid != uid)
    {
        ptr = ptr->next;
    }
    printf("The Candidate is found\n");
    printf("Name: %s\n", ptr->name);
    printf("Party: %d\n", ptr->party);
}
int invalid=0;
void IncrementVote(char uid)
{
    struct Node1 *ptr = (struct Node1 *)malloc(sizeof(struct Node));
    ptr = start;
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
        ptr->vote++;
    }
    else{
        invalid++;
    }
    
}
void ShowCandidatesWithVotes()
{
    struct Node1 *ptr = (struct Node1 *)malloc(sizeof(struct Node1));
    ptr = start;
    while (ptr != NULL)
    {
        printf("Element: %d\t %s\t \t%s \t %d\n", ptr->uid, ptr->name, ptr->party,ptr->vote);
        ptr = ptr->next;
    }
}