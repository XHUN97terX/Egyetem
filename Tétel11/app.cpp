#include <iostream>
using namespace std;
//valgrind --leak-check=yes ./app.o
#define leak true

void f()
{
	int* k = new int[1000];
	int* j = new int(10);
	if (leak)
	{
	}
	else
	{
		delete j;
		//delete[] j;	hibás
		//delete k;		hibás
		delete[] k;
	}
}
int main()
{
	for (int i = 0; i<1000; i++)
		f();
	cin.get();
}