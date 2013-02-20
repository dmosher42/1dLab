
/*  File: universe.h
 *  Date: 27 Sep 05
 *  Rev:
 *
 *  declaration of universe class
 */

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <iostream>
#include "entry.h"
#include "container.h"

typedef int Coordinate;
typedef int State;

class Universe {
    
public:
	// constructors and destructors
	Universe();
	~Universe();
    
	// accessors
	void display() const;
    
	// mutators
	void clear();
	void populate();
	int update(Universe *other); // compute the next generation into other
    
private:
	int generation;		// generation number
	Coordinate begin;	// beginning of the known universe
	Coordinate end;		// end of the known universe
	Container cells;	// cells of the universe
    
	// private helper functions
	void init_to_empty();
	void update_from_copy(Universe &o);
    
	Entry update_live(Coordinate p) const;
    // compute the next state of the live cell at coordinate p
	Entry update_dead(Coordinate p) const;
    // compute the next state of the dead cell at coordinate p
	int count_cells(Coordinate start, Coordinate stop) const;
    // count the number of current live cells from start to stop
	int eval_cell(Coordinate p) const;
    // determine the current state of cell at coordinate p
};


#endif