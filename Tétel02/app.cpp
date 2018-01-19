#include <iostream>

using namespace std;

class intwrap
{
public:
	int wrapped;
	intwrap(int i = 0) : wrapped(i) {}
	~intwrap() {}
	intwrap(const intwrap& from)
	{
		wrapped = from.wrapped;
		cout << "Másolás történt!\n";
	}
	intwrap(intwrap&& from)
	{
		wrapped = from.wrapped;
		from.wrapped = 0;
		cout << "Mozgatás történt!\n";
	}
	intwrap operator+(intwrap& i)
	{
		intwrap k;
		k.wrapped = i.wrapped + this->wrapped;
		return k;
	}
};

void main()
{
	intwrap i(2), j(3);
	intwrap k(i);		//másol
	intwrap h(i + j);	//mozgat
	cin.get();
}
