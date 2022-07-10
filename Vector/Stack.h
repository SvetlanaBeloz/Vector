#include "Vector.h"


class Stack
{
	Vector vector;
	static const int SIZE = 10;
	int top = 0;

public:

	bool IsFull()
	{
		return top == SIZE;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	void Push(int number)
	{
		if (!IsFull()) {
			vector.PushBack(number);
			top++;
		}
		else throw "Stack overflow!";
	}

	void Pop()
	{
		if (top >= 0) {
		    vector.PopBack();
			top;
		}
		else throw "Stack is empty!";
	}

	int Peek()
	{
		if (!IsEmpty()) {
			return vector[--top];
		}
		else throw "Stack is empty!";
	}

	int GetCount()
	{
		return top;
	}

	void Clear()
	{
		top = 0;
	}
};

