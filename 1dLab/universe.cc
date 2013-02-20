

/*  File: universe.cc
 *  Date: 27 Sep 05
 *  Rev:  v1
 *
 *  definition of universe class
 *  a simplest case with updates as a copy of the current universe
 */

#include "universe.h"
#include "entry.h"
#include "container.h"

// maximum number of generations to process
static const int MAXGEN = 3;

// symbols for cell state
const int DEAD = 0;
const int ALIVE = 1;

// Constructor and Destructors
Universe :: Universe()
{	init_to_empty();	}

Universe :: ~Universe()
{	init_to_empty();	}

// Accessors
void Universe :: display() const
{
	// show header
    printf("             begin: %3d",begin - 2);
    for(int i = begin; i <= end+2; i++) printf("  ");
    printf("%3d end\n", end +2);
    
	// show universe
	printf("Generation %03d: ", generation);
	printf(". . . 0 0 ");
	for(int i = begin; i <= end; i++)
		printf("%d ", cells.get(i));
	printf("0 0 . . .\n");
}

// Mutators

void Universe :: clear()
{	init_to_empty();	}

void Universe :: populate()
{
	// a simple initial universe for testing
	cells.insert(ALIVE);
	cells.insert(DEAD);
	cells.insert(ALIVE);
	end = 2;
}

int Universe :: update(Universe *other)
{
	// a trivial update operation which copies to the next generation.
	update_from_copy(*other);
	other->generation++;
	return other->generation - MAXGEN;
}

// Private helper functions

void Universe :: init_to_empty()
{	begin = end = generation = 0;
	cells.clear();
}

void Universe :: update_from_copy(Universe &other)
{
	for(int i = begin; i <= end; i++)
	{
		other.cells.insert(cells.get(i - begin));
	}
    
	other.generation = generation;
	other.begin = begin;
	other.end = end;
}

