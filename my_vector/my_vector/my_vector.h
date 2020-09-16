#pragma once
#include <iostream>
class Vector
{
public:
	Vector();
	virtual ~Vector();
	void push_back(int value);
	void pop_back();
	int size();
	int& operator [](int i);
	
private:
	int capacity;
	int* m_arr;
	int m_size;
};