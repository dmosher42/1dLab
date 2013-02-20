

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
	other->init_to_empty();
	other->begin = begin;
	other->end = end;
    
	// a trivial update operation which copies to the next generation.
	for(int i = begin; i <= end; i++)
	{
		if(cells.get(i) == ALIVE)
		{
			other->cells.insert(update_live(i));
		}
		else
		{
			other->cells.insert(update_dead(i));
		}
	}
	
	other->generation = generation + 1;
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

Entry Universe :: update_live(Coordinate p) const
{
	int sum = 0;
	
	if((p - begin) < 2)
	{
		if((p - begin) == 1)
		{
			sum+= cells.get(p - 1);
		}
	}
	else
	{
		sum += cells.get(p - 2);
		sum += cells.get(p - 1);
	}
	
	if((end - p) < 2)
	{
		if((end - p) == 1)
		{
			sum += cells.get(p + 1);
		}
	}
	else
	{
		sum += cells.get(p + 1);
		sum += cells.get(p + 2);
	}
	
	if(sum == 0 || sum == 1 || sum == 3)
	{
		return DEAD;
	}
	else
	{
		return ALIVE;
	}
    
}

Entry Universe :: update_dead(Coordinate p) const
{
	int sum = 0;
    
	if((p - begin) < 2)
	{
		if((p - begin) == 1)
		{
			sum+= cells.get(p - 1);
		}
	}
	else
	{
		sum += cells.get(p - 2);
		sum += cells.get(p - 1);
	}
	
	if((end - p) < 2)
	{
		if((end - p) == 1)
		{
			sum += cells.get(p + 1);
		}
	}
	else
	{
		sum += cells.get(p + 1);
		sum += cells.get(p + 2);
	}
    
	if(sum == 2 || sum == 3)
	{
		return ALIVE;
	}
	else
	{
		return DEAD;
	}
}

int Universe :: count_cells(Coordinate start, Coordinate stop) const
{
	int sum = 0;
	
	for(int i = start; (i <= stop) && (i <= end); i++)
	{
		sum += cells.get(i);
	}
	
	return sum;
}

int Universe :: eval_cell(Coordinate p) const
{
	return cells.get(p);
}