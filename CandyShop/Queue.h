#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

//Isn't implementing List.h because some methods of List do not apply to queues (only adds to one end)

class Queue {
private:
	Node* start;
	Node* end;
	int len;

public:
	Queue();
	~Queue();

	//O(1)
	int length();

	//O(1)
	const Data getStart();

	//O(c)
	Data removeStart();

	//O(1)
	const Data getEnd();

	//O(c)
	void addToEnd(Data toAdd);

};

#endif