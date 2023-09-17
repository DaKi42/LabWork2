#include "DynamicArray.h"
#include <Windows.h>
#include <iostream>
using namespace std;

DynamicArray::DynamicArray() :ptr(nullptr), size(0) {}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S] {0};
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	delete[] ptr;
	//Sleep(1000);
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output()const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n*****************\n";
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize()const
{
	return size;
}

void DynamicArray::resize(int newSize)
{
	if (size == newSize) {
		return;
	}

	int* newPtr = new int[newSize];

	for (int i = 0; i < newSize; i++) {
		if (i < size) {
			newPtr[i] = ptr[i];
		}
		else {
			newPtr[i] = 0;
		}
	}

	delete[] ptr;
	ptr = newPtr;
	size = newSize;
}

void DynamicArray::sort()
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ptr[j] > ptr[j + 1]) {
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}

int DynamicArray::search(int a) const
{
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == a) {
			return i;
		}
	}

	return -1;

}

void DynamicArray::reverse()
{
	int left = 0;
	int right = size - 1;
	int temp;

	while (left < right) {
		temp = ptr[left];
		ptr[left] = ptr[right];
		ptr[right] = temp;

		left++;
		right--;
	}
}

DynamicArray DynamicArray::operator+(int sum)
{
	int newSize = size + sum;
	DynamicArray newArray(newSize);

	for (int i = 0; i < size; i++) {
		newArray.ptr[i] = this->ptr[i];
	}

	for (int i = size; i < size; i++) {
		newArray.ptr[i] = 0;
	}

	size = newSize;
	return newArray;
}

DynamicArray DynamicArray::operator-(int diff)
{
	int newSize = size - diff;
	DynamicArray newArray(newSize);

	if (size < diff) {

		for (int i = 0; i < newSize; i++) {
			newArray.ptr[i] = ptr[i];
		}

		return newArray;
	}
	else {
		return *this;
	}
}

DynamicArray DynamicArray::operator*(int multi)
{
	DynamicArray newArray;
	newArray.size = size;
	newArray.ptr = new int[newArray.size];

	for (int i = 0; i < size; i++) {
		newArray.ptr[i] = ptr[i];
	}

	for (int i = 0; i < newArray.size; i++) {
		newArray.ptr[i] *= multi;
	}
	return newArray;
}

DynamicArray DynamicArray::operator-(DynamicArray& diff)
{
	if (size != diff.size) {
		return *this;
	}
	else {
		DynamicArray newArray(size);

		for (int i = 0; i < size; i++) {
			newArray.ptr[i] = ptr[i] - diff.ptr[i];
		}

		return newArray;
	}

}

DynamicArray DynamicArray::operator+(DynamicArray& sum)
{
	DynamicArray newArray(size + sum.size);

	for (int i = 0; i < size; i++) {
		newArray.ptr[i] = ptr[i];
	}

	for (int i = size; i < sum.size; i++) {
		newArray.ptr[i] = sum.ptr[i - size];
	}

	return newArray;
}

DynamicArray DynamicArray::operator++()
{
	if (size > 0) {
		int newSize = size + 1;
		int* newPtr = new int[newSize];

		for (int i = 0; i < size; i++) {
			newPtr[i] = ptr[i];
		}
		newPtr[size] = 0;

		delete[] ptr;
		ptr = newPtr;
		size = newSize;
	}

	return *this;
}

DynamicArray DynamicArray::operator--()
{
	if (size > 0)
	{
		size--;
		int* temp = new int[size];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
	}
	return *this;
}