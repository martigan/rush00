#include "List.hpp"
#include "define.hpp"
List* List::_first (NULL);

List::~List(){
	if (this == this->_first)
		this->_first = this->getNext();
}
List::List(AEntity *member) : _member(member){
	if (!_first)
		List::_first = this;
	else
		List::add(List::_first);
	this->_next = NULL;
}
void List::add(List *list) {
	while (list->getNext())
		list = list->getNext();
	list->setNext(this);
}

// void List::remove(AEntity *member) {
// 	List * elem = List::getFirst();
// 	List *prev = NULL;
// 	while (elem && elem->getMember() != member)
// 	{
// 		prev = elem;
// 		elem = elem->getNext();
// 	}
// 	if (elem)
// 		List::destroy(elem, prev);
// }

void List::remove(List *elem) {
	if (elem)
	{
		List * tmp = elem->getNext()->getNext();
		delete elem->getNext();
		elem->setNext(tmp);
	}
	else
	{
		List * tmp = List::getFirst();
		List::_first = tmp->getNext();
		delete tmp;
	}
}
// void List::destroy(List *elem, List *prev) {
// 	if (prev)
// 		List::_first = elem->getNext();
// 	else if (elem->getNext())
// 		prev->setNext(elem->getNext());
// 	delete elem;
// }
AEntity *List::getMember(void) const {
	return this->_member;
}
List *List::getNext(void) const {
	return this->_next;
}
List *List::getFirst(void) {
	return List::_first;
}
void List::setNext(List *next) {
	this->_next = next;
}
void List::setMember(AEntity *member) {
	this->_member = member;
}

void List::display(Screen &screen, int frameID) {
	List * elem = List::getFirst();

	while (elem->getNext())
	{
		elem->getNext()->getMember()->move(frameID);
		elem->getNext()->getMember()->display(screen);
		int tmp = elem->getNext()->getMember()->getY();
		if ( tmp > WIDTH - 2 || tmp < 0)
			remove(elem);
		else
			elem = elem->getNext();
	}
}
