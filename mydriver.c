
/* ****** error code declaration is remains *** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 20

struct dfaDriver
{
	int states;
	int symbols;
	int transitions[20][20];
	int final[10];
};

char str[MAXSIZE];
char c;

int source,destination,i,unique,finals,length, currstate, startstate = 0, endstate, nextstate;
// above variable minimization is remaining....
int asci = 97, k = 0;

int dfaExecution(struct dfaDriver dfa)
{
  	fgets(str,MAXSIZE,stdin);
	
	fprintf(stdout,"\n");
	
	fprintf(stdout,"This is Your string\n");
 	
	fprintf(stdout,"%s\n",str);
 	
	length = strlen(str) - 1;
	for(i = 0; i < length; i++)
		if(isalpha(str[i]) == 0 )
		{	
			fprintf(stdout,"Incorrect String\n");
			exit(0);
		}
	currstate = startstate;
	
	i = 0;	
	while(i < length)
	{
		c = str[i];
		endstate = c - 'a'; 	
		nextstate = (dfa.transitions[currstate][endstate]);
		currstate = nextstate;
		
		i++;
	}
	
	for(i = 0; i < finals; i++)
	{	
		if((dfa.final[i]) == currstate)
		{
			fprintf(stdout,"Input String Is In Language \n !...ACCEPTED...!\n");
			exit(0);
		}
		
	}
	
	fprintf(stdout,"Input String Is Not In Language \n !....REJECTED...!\n");
	
	return 0;

}

void displayDfaDetails(struct dfaDriver dfa)
{
	fprintf(stdout,"*****------Dispaly The Dfa Details-----******\n\n");

	fprintf(stdout,"Number ofd states is : %d\n",dfa.states);
	
	fprintf(stdout,"Number ofd Symbols is : %d\n",dfa.symbols);
	
	fprintf(stdout,"Transitions Table\n");
	
	for(source  = 0; source < dfa.states; source ++)
	{	
		fprintf(stdout,"{");
		
		for(unique = 0; unique < dfa.symbols; unique ++)
			if(unique == dfa.symbols - 1)
				fprintf(stdout," %d ",dfa.transitions[source][unique]);	
			else 
				fprintf(stdout," %d ,",dfa.transitions[source][unique]);	
		
		fprintf(stdout,"}\n");
	}
	
	fprintf(stdout,"The Final State\n");
	
	for(i = 0; i < finals; i++)
		fprintf(stdout,"%d\n",dfa.final[i]);  	
}

void acceptDfaDetails()
{
	struct dfaDriver dfa; 
	
	fprintf(stdout,"How Many States in Your Dfa\n");

	scanf("%d",&dfa.states);

	fprintf(stdout,"How Many Symbols in Your Dfa\n");

	scanf("%d",&dfa.symbols);
	
	if(((dfa.states) < 0 ) || (dfa.symbols) < 0 || (dfa.symbols) > 26 || (isalpha(dfa.states)) != 0)
	{	
		fprintf(stdout,"Invalid states / symbols count\n");
		exit(0);
	}
	
	fprintf(stdout,"** Accept Transitions For Every State Over Every Alphabet **\n");
	
	for(source  = 0; source < (dfa.states); source ++)
	{	
		fprintf(stdout,"For State %d ",source);
		for(unique = 0; unique < (dfa.symbols); unique ++)
		{	
			fprintf(stdout,"Over Symbol %c \n",(asci + unique)); 
			scanf("%d",&(dfa.transitions[source][unique]));
			
/* *****		if(isalpha(dfa.transitions[source][unique]) != 0)
			{
				fprintf(stdout,"Invaliid State Transition\n");
				exit(0);
			}	
	***** */		
			if((dfa.transitions[source][unique]) > (dfa.states)-1 )
			{
				fprintf(stdout,"Invaliid State (Enter The Valid State)\n");
				source --;	
				break;
			}
		}
	}
	
	fprintf(stdout,"Define Array Of Final States\n");
	
	fprintf(stdout,"How Many Final States ");
	scanf("%d",&finals);
	
	if(finals > (dfa.states) || (finals < 0))
	{
		fprintf(stdout,"Incorrect Final states\n");	
		exit(0);
	}
	
	for(i = 0; i < finals; i++)
		scanf("%d\n",&(dfa.final[i]));  	
		if((dfa.final[i]) < 0)
		{
			fprintf(stdout,"Incorrect Final states\n");	
			exit(0);
		}
	
	dfaExecution(dfa);
	
	fprintf(stdout,"\n");
	
	displayDfaDetails(dfa);
		
}

int main(void)
{	
	acceptDfaDetails();
	
	return 0;
}	
