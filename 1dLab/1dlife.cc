
/*  File: 1dlife.c
 *  Date: 27 Sep 05
 *  Rev:
 *
 *  execute the 1D Life simulation
 */

#include "universe.h"


int main()
{
    Universe U1, U2;
    Universe *currgen = &U1;
    Universe *nextgen = &U2;
    
	// populate the initial universe and display it
	currgen->populate();
	currgen->display();
    
   	int changes = true;
	// while there are changes in the universe
	while(changes)
	{
		// compute the next generation and display it
		changes = currgen->update(nextgen);
		nextgen->display();
        
		// swap universes
		Universe *temp = currgen;
		currgen = nextgen;
		nextgen = temp;
		// and destroy the old universe
		nextgen->clear();
	}
    
}