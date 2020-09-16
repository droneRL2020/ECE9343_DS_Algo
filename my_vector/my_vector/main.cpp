#include <iostream>
//#include <vector>
#include "my_vector.h"	
using namespace std;

int main()
{
	Vector vec;
	vec.push_back(2);
    vec.push_back(3);
	cout << vec[0] << " " << vec[1] << endl;
	cout << vec.size() << endl;
	vec.pop_back();
	vec.pop_back();
	cout << vec.size() << endl;
	vec.pop_back();
	return 0;
}