#include<stdio.h>
#include<string.h>

int checkPassword();
int Candidate_Voter();
int candidateReg();
int avaSym();
char symbol();
int voterReg();
int vote();
int electionResults();
int indexVoter = 0;
int indexCandidate = 0;

struct candidate
{
char name[10];
int age;
char gender;
char nationality[10];
char symbol;
int sym_num;
int votes;
}c[10];

struct voter
{
char name[10];
int age;
char gender;
char nationality[10];
int voteGiven;
char votedCandidate[10];
}v[10];



int main()
{

    //START SCREEN
    printf("\n*********Welcome to the elections 2023***********\n");

    int result = checkPassword();
    if(result)
    {
        Candidate_Voter();
        vote();
        electionResults();
    }
}



//PASSWORD TO ENTER PORTAL
int checkPassword()
{
    char password[6],pass[6] = "nigama";
    //ADMIN PAGE
    printf("Enter admin's password:  ");
    for(int i = 0; i<6;i++)
    {
        scanf("%c",&password[i]);
    }

    //PASSWORD AUTHENTICATION
    for(int i =0; i<6;i++)
    
    {
        if(password[i] == pass[i])
        {
        continue;
            if(i == 5)
                return 1;
        }
        else
        {
            printf("Incorrect Password");
            break;
        }       
    }
}



// CANDIDATE OR VOTER
int Candidate_Voter()
{
    printf("\n******CANDIDATE REGISTRATION PORTAL*********\n");
        while(indexCandidate<10)
        {
            char candChoice[2];
            candidateReg();
            indexCandidate++;
            printf("*********\tDo youw want to continue\t ***********\n");
            scanf("%s",candChoice);
            if (strcmp("yes",candChoice) == 0) 
                continue;
            else
                break;
        }
    printf("\n******VOTER REGISTRATION PORTAL*********\n");
        while(indexVoter<10)
        {
            char voterChoice[2];
            voterReg();
            indexVoter++;
            printf("*********\tDo youw want to continue\t ***********\n");
            scanf("%s",voterChoice);
            if (strcmp("yes",voterChoice) == 0) 
                continue;
            else
                break;
        }
}



//CANDIDATE REGISTRATION
int candidateReg()
{
    printf("Name:\t\t");              scanf("%s",c[indexCandidate].name);
    printf("Age:\t\t");               scanf("%d",&c[indexCandidate].age);
    printf("Gender(M or F):\t");      scanf("%s",&c[indexCandidate].gender);
    printf("Nationality:\t");       scanf("%s",c[indexCandidate].nationality);

    if(c[indexCandidate].age >= 20) //|| c[i].nationality == "INDIAN"))
    {
        c[indexCandidate].symbol = symbol();
        for(int i=0; i<indexCandidate; i++)
        {
            if(c[indexCandidate].symbol == c[i].symbol)
            {
                printf("\nSorry it is already taken \nPlease another symbol\n");
                return symbol();
            }
        }
        printf("Name: \t%s\nAge: \t%d\nGender: \t%c\nNationality: %s\nSymbol: \t%c",c[indexCandidate].name,c[indexCandidate].age,c[indexCandidate].gender,c[indexCandidate].nationality,c[indexCandidate].symbol);
        printf("\n");
    }
    else
        printf("\nSorry not eligible to register\n");
}



//symbol selection
char symbol()
{
    char symbols[15] = {'!', '@', '#', '$', '^', '&', '*', '~', '+', ';', '<', '>', '?', '/', '|'};
    int n,i;
    for(i=0 ; i<15 ;i++)
    {
        printf("%c --- %d \n",symbols[i],i+1);
    }

    printf("Choose your symbol number: ");
    scanf("%d",&n);
    c[indexCandidate].sym_num = n;
    return symbols[n-1];
}



//VOTER REGISTRATION
int voterReg()
{
    printf("Name:\t\t");              scanf("%s",v[indexVoter].name);
    printf("Age:\t\t");               scanf("%d",&v[indexVoter].age);
    printf("Gender(M or F):\t");      scanf("%s",&v[indexVoter].gender);
    printf("Nationality:\t");       scanf("%s",v[indexVoter].nationality);

    if((v[indexVoter].age) < 18)
    {
        printf("Sorry dear.\nYou are not eligible to vote \n");
        return 0;
    }

    v[indexVoter].voteGiven = avaSym();
}

//Available symbols
int avaSym()
{
    int i,n;
    printf("\nAvailable symbols are:\n");
    for(i=0; i<indexCandidate; i++)
    {
        printf("%c---%d\n",c[i].symbol,c[i].sym_num);
    }
    printf("Please choose the number you want to vote to");
    scanf("%d",&n);

    return n;
}

//VOTING
int vote()
{
    int i, j, k, found = 0;
    char voteChoice[10];
    for(i = 0; i < indexCandidate; i++)
    {

        for(j = 0; j < indexVoter; j++)
        {
            if(c[i].sym_num == v[j].voteGiven)
            {
                c[i].votes++;
            }
        }
    }
}

//ELECTION RESULTS
int electionResults()
{
    int i,max=0;
    printf("\n\nELECTION RESULTS\n");

    /*for(i = 0; i < indexVoter; i++)
    {
        if(v[i].voteGiven != 0)
        {
            printf("Voter: %s\n", v[i].name);
            printf("Voted for: %d\n\n", v[i].voteGiven);
        }
        else
        {
        printf("Voter: %s\n", v[i].name);
        printf("Did not vote\n");
        }
    }*/

    for(int i=0; i<indexCandidate; i++){
        if(c[max].votes < c[i].votes){
            max = i;
        }
    }

    printf("**CONGRATULATIONS**\n");
    printf("\nWinning Candidate Details:\n");

    printf("Name: \t\t%s\nAge: \t\t%d\nGender:\t\t %c\nNationality:\t %s\nSymbol:\t\t %c\nVotes:\t\t %d\n\n",c[max].name,c[max].age,c[max].gender,c[max].nationality,c[max].symbol,c[max].votes);
    printf("%s won by %d votes",c[max].name,c[max].votes);
}
