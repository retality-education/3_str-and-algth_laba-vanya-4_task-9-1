#pragma once
#include"Student.h"

using TInfo = Student;

class NODE
{
public:
	TInfo info;
	NODE* next;
	NODE() {};
	NODE(TInfo info, NODE* ptr_next = nullptr) :info(info), next(ptr_next) {};
	~NODE()
	{
		next = nullptr;
	}
};
