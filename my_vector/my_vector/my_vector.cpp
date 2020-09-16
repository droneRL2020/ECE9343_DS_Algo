#include "my_vector.h"
#include "assert.h"
using namespace std;
Vector::Vector()
{
	m_arr = new int[capacity];
}

Vector::~Vector()
{
	delete[] m_arr;
}

void Vector::push_back(int value)
{
	if(m_size <= capacity || capacity==NULL)
		capacity += 1;
	m_size += 1;
	m_arr[capacity-1] = value;
}

void Vector::pop_back()
{
	m_size -= 1;
	assert (m_size >= 0);
	m_arr[m_size] = NULL;
}

int Vector::size()
{
	return m_size;
}

int& Vector::operator[](int i)
{
	return m_arr[i];
}



