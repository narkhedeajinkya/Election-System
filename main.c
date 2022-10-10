#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "votingbooth.c"
int main()
{
    int uid,byear;
    int e,B;
    char *name;
    char *party;
    CreateCandidateList();
    CreateVoterList();
    {
        printf("\n\n\n");
        printf("\t            ****** WELCOME TO THE ONLINE VOTINy PORTAL ******        \n\n");

        printf("\t           ***************************************************        \n\n\n\n\n");
        printf("        \t *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");
    }
    int begin;
    scanf("%d", &begin);
    int c;
    while (1)
    {
        if (begin == 1)
        {
            system("cls");
            printf("\n\n\n");
            printf("        \t\t\t1. FOR VOTE ENTRY     \n");
            Sleep(300);
            printf("        \t\t\t2. FOR ADMIN PANEL    \n");
            Sleep(300);
            printf("        \t\t\t3. FOR WINNER         \n");
            Sleep(300);
            printf("        \t\t\t4. EXIT          \n");
            printf("Enter proper choice=>");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
            {
                printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CANNOT    \n\n\n");
                Sleep(500);
                printf("    \t ********So Plz Enter Your UID********\n\n\n");
                VerifyVoter();
                break;
            }
            case 2:
            {
                printf("**********Welcome to the Admin Panel**********\n");
                printf("\t\t\t\t\tEnter Your Password To Unlocx The Admin Panel=>");
                scanf("%d", &B);
                if (B == 9999)
                {
                    system("cls");
                    printf("Enter the operation you want to perform=>\n 1)Add New Voter \n 2)Remove Existing Voter \n 3)Add new Candidate \n 4)Remove Existing Candidate\n ");
                    scanf("%d",&e);
                    switch (e)
                    {
                    case 1:
                        printf("Enter the UID of the New Voter=>\n");
                        scanf("%d", &uid);
                        printf("Enter the Name of the New Voter=>\n");
                        scanf("%s", name);
                        printf("Enter the Birth Year of the New Voter=>\n");
                        scanf("%d", &byear);
                        AddNewVoter(uid, name, byear);
                        printf("New Voter Added Successfully\n");
                        Sleep(1500);
                        break;
                    case 2:
                        printf("Enter the UID of the Voter you want to Remove=>\n");
                        scanf("%d", &uid);
                        Remove(uid);
                        printf(" Voter Removed Successfully\n");
                        Sleep(1500);
                        break;
                    case 3:
                        printf("Enter the UID of the New Candidate=>\n");
                        scanf("%d", &uid);
                        printf("Enter the Name of the New Candidate=>\n");
                        scanf("%s", &name);
                        printf("Enter the Party symbol for New Candidate=>\n");
                        scanf("%s", &party);
                        AddNewCandidate(uid, name, party);
                        printf("New Canidate Added Successfully\n");
                        Sleep(1500);
                        break;
                    case 4:
                        printf("Enter the UID of the Voter you want to Remove=>\n");
                        scanf("%d", &uid);
                        Remove(uid);
                        printf("Candidate Removed Successfully\n");
                        Sleep(1500);
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    printf("Wrong Password...Try again!\n");
                }
                break;
            }
        case 3:
        {
            printf("***********************The Final Result **********************\n");
            ShowCandidatesWithVotes();
            Sleep(15000);
            break;
        }
        case 4:
        {
            exit(1);
            break;
        }
        default:
        {
            printf("Invalid choice!");
        }
        }
    }
};
return 0;
}