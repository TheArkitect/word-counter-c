#include <stdio.h>


/*symbolic contants*/
#define IN 1
#define OUT 0

/*since my VM is UNIX based ctrl + d was used to simulate EOF*/
/*the variable state will determine if the current subject is a word or a blank. nl, nw, nc are counters.*/

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;

	/*this is a valid statement, it read from right to left so 		it is possible to have a multi-lined initialization*/
	nl = nw = nc = 0;

	/*will iter through the characters till EOF
	since unix based enter then ctrl + d must be used*/
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("number of words: %d\n", nw);
}


