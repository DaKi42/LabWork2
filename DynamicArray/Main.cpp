#pragma once
#include "DynamicArray.h"

DynamicArray GetObj()
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
void main()
{
	DynamicArray a(2);
	DynamicArray b(6);
	a.Input();
	a.Output();

	DynamicArray res = a + 22;
	res.Output();
	res = a - 2;

	res.Output();
	res = a * 2;
	res.Output();

	res = a - b;
	res.Output();

	res = a + b;
	res.Output();

	++res;
	res.Output();
	--res;

	res.Output();

	system("pause");
}