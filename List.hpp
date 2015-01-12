#ifndef LIST_H
# define LIST_H

#include <iostream>
#include "AEntity.hpp"


class List
{
private:
	AEntity *_member;
	List *_next;
	static List *_first;
	List(List const & copy);
	List const & operator=(List const &);

public:
	List();
	~List();
	List(AEntity *member);
	static void setFirst(void);
	void add(List *elem);
	static void remove(List *elem);
	AEntity *getMember(void) const;
	List *getNext(void) const;
	static List *getFirst(void);
	void setNext(List *first);
	void setMember(AEntity *member);
	static void display(Screen &screen, int frameID);
	//static void destroy(List *elem, List *prev);
};

#endif
