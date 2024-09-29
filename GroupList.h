#pragma once
#include "Container.h"

// Базовый класс для однонаправленного и двунаправленного списков
class GroupList : public Container
{

protected:
	struct Node {
		void* val;
		size_t valSize = 0;
		Node* next;
		
	};

	Node* newNode(void * elem, size_t elemSize);
	void deleteNode(Node* tmp);


public:
	GroupList(MemoryManager &mem) : Container(mem) {}

};