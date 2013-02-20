
/*  File: listnode_inl.h
 *  Date: 12 Feb 13
 *  Rev:
 *
 *   Listnode inline functions
 */

#ifndef LISTNODE_INL_H
#define LISTNODE_INL_H

#include <stdlib.h>
#include "entry.h"

inline ListNode::ListNode(Entry x)
{
	entry = x;
    
	next = NULL;
}

inline Entry ListNode::getdata() const
{
	return entry;
}

inline ListNode* ListNode::getnext() const
{
	return next;
}

inline void ListNode::setdata(Entry x)
{
	entry = x;
}

inline void ListNode::setnext(ListNode *n)
{
	next = n;
}

#endif
