#pragma once
#include "GroupList.h"

// ����������� �����: ���������������� ������
class AbstractList : public GroupList
{
public:
	// �����������
	AbstractList(MemoryManager &mem) : GroupList(mem) {}

	// ����������
	virtual ~AbstractList() {}

	// ���������� �������� � ������ ����������.
	// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
	virtual int push_front(void *elem, size_t elemSize) = 0;

	// �������� �������� �� ������ ����������.
	virtual void pop_front() = 0;

	// ������� ���� ���������� ��������� �� �������, ����������� � ������ ����������.
	// � �� ���� ���������� ������ ������
	virtual void* front(size_t &size) = 0;

	// ���������� �������� � �������, �� ������� ��������� �������� iter.
	// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
	virtual int insert(Iterator *iter, void *elem, size_t elemSize) = 0;
};
