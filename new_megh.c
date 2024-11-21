#include<stdio.h>
#include<string.h>

#define MAX_VOTERS 10
#define MAX_CANDIDATES 10

struct candidate
{
char name[10];
int age;
char gender;
char nationality[10];
char symbol;
int votes;
}c[MAX_CANDIDATES];

struct voter
{
char name[10];
int age;
char gender;
char nationality[10];
int voteGiven;
char votedCandidate[10];
}v[MAX_VOTERS];

int checkPassword();
int candidateReg();
char symbol();
int voterReg();
void vote();
void electionResults();

int main()
{
printf("Welcome to the elections 2023**\n");

if(checkPassword())
{
    printf("******CANDIDATE REGISTRATION PORTAL*********\n");
    candidateReg();
    voterReg();
    vote();
    electionResults();
}
}

int checkPassword()
{
char password[7];
char pass[7] = "nigama";

printf("Enter admin's password:");
scanf("%s",password);

if(strcmp(password, pass) == 0)
    return 1;
else
{
    printf("Incorrect Password\n");
    return 0;
}
}

int candidateReg()
{
int i = 0;
while(i < MAX_CANDIDATES)
{
printf("Enter details of candidate %d:",i+1);
scanf("%s %d %c %s",c[i].name,&c[i].age,&c[i].gender,c[i].nationality);
c[i].symbol = symbol();
i++;
}
}

char symbol()
{
char symbols[10] = {'!', '@', '#', '$', '^', '&', '*', '~', '+' };
int n;

printf("Choose your symbol number {'!', '@', '#', '$', '^', '&', '*', '~', '+' }:");
scanf("%d",&n);

return symbols[n];
}

int voterReg()
{
for(int i = 0; i < MAX_VOTERS; i++)
{
printf("Enter details of voter %d:",i+1);
scanf("%s %d %c %s",v[i].name,&v[i].age,&v[i].gender,v[i].nationality);
}
}

void vote()
{
char voteChoice[10];

for(int i = 0; i < MAX_VOTERS; i++)
{
    printf("Voter: %s\n", v[i].name);
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", voteChoice);

    for(int j = 0; j < MAX_CANDIDATES; j++)
    {
        if(strcmp(voteChoice, c[j].name) == 0)
        {
            v[i].voteGiven = 1;
            strcpy(v[i].votedCandidate, voteChoice);
            c[j].votes++;
            break;
        }
    }
}
}

void electionResults()
{
printf("\n\nELECTION RESULTS\n");

for(int i = 0; i < MAX_VOTERS; i++)
{
    printf("Voter: %s\n", v[i].name);
    printf("Voted for: %s\n", v[i].votedCandidate);
}

printf("\nCandidate details:\n");

for(int i = 0; i < MAX_CANDIDATES; i++)
{
    printf("Name: %s\n Age: %d\n Gender: %c\n Nationality: %s\n Votes: %d\n\n",c[i].name,c[i].age,c[i].gender,c[i].nationality,c[i].votes);
}
}