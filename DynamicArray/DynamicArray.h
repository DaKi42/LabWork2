#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr;
	int size;
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	void Input();
	void Output()const;
	int* GetPointer()const;
	int GetSize()const;

	void resize(int newSize);
	void sort();
	int search(int a) const;
	void reverse();

	DynamicArray operator+(int sum);
	DynamicArray operator-(int diff);
	DynamicArray operator*(int multi);
	DynamicArray operator-(DynamicArray& diff);
	DynamicArray operator+(DynamicArray& sum);
	DynamicArray operator++();
	DynamicArray operator--();

};
