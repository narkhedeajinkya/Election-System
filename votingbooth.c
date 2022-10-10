#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "functiondefinations.c"
#include "functionforcandidates.c"
void CastVote()
{
    int uid, votes = 0;
    DisplayCandidate();
    printf("(Please Enter the uid number of the candidate in the voting section)\n");
    printf("Voting Section :-\n");
    printf("Enter the serial number:");
    scanf("%d", &uid);
    IncrementVote(uid);
    Sleep(800);
    printf("Your Vote is successfully casted\n");
    Sleep(2000);
}
int k;
int g;
void VerifyVoter()
{
    int uid, birth_year, c;
    printf("\t\t\t\tVoter Verification\n");
    printf("Enter your uid:");
    scanf("%d", &uid);
    k = Find(uid);
    g = CheckAttempts(uid);
    Sleep(1000);
    printf("****************************************************************\n");
    if (k > 1000)
    {
        printf("Enter your birth year:");
        scanf("%d", &birth_year);
        if (birth_year == k && g == 1)
        {
            CastVote();
            Voted(uid);
        }
        else if (g != 1)
        {
            printf("You have already voted\n");
            Sleep(5000);
        }
        else
        {
            printf("Wrong Birth Year Entered\n");
            printf("Try Again\n");
        }
    }
}

// int main()
// {
//     CreateCandidateList();
//     CreateVoterList();
//     VerifyVoter();
//     return 0;
// }
// int main()
// {
//     int n;
//    printf("\t\t\t\tDIGITAL VOTING SYSTEM\n");
//    printf("Welcome to our Voting Portal\n");
//    printf("Choose Options:\n");
//    printf("(Choose the index number of each option)\n");
//    printf("1.Voting Booth\n");
//    printf("2.Admin Panel\n");
//    printf("3.Exit\n");
//    printf("Enter your choice:");
//    scanf("%d",&n);
//    if (n==1)
//    {
//        printf("Please Cast your Vote\n");
//        CreateVoterList();
//        VerifyVoter();
//    }
//    else if(n==2){
//        printf("Welcome to Admin Panel\n");

//    }
//    else if(n==3){
//        printf("Thanks for vistingthe portal\n");
//        printf("Dont have a good day, Have a great day\n");
//        return 0;
//    }
//    else{
//        printf("Invalid choice\n");
//    }
//     return 0;
// }