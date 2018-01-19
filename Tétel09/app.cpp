#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

template<class Key, class T> map<Key, T> MapSort(const map<Key, T>& m)
{
	vector<pair<Key, T>> v;
	auto i = m.begin();
	while (i != m.end())
	{
		v.push_back(*i);
		++i;
	}
	sort(v.begin(), v.end(), [](auto x, auto y) {return x.second < y.second; });
	map<Key, T> k(v.begin(), v.end());
	return k;
}
template <class Key, class T> vector<pair<Key, T>> MapSortIntoVector(const map<Key, T>& m)
{
	vector<pair<Key, T>> v;
	auto i = m.begin();
	while (i != m.end())
	{
		v.push_back(*i);
		++i;
	}
	sort(v.begin(), v.end(), [](auto x, auto y) {return x.second < y.second; });
	return v;
}

void main()
{
	const int size = 10;
	map<int, int> m1, m2;
	for (int i = 0; i < size; i++)
	{
		m1[i] = size - i;
		m2[i] = size - i;
	}
	//m1 alapból rendezett reprezentációja folytán, azt nem kell sort-olni (és nem is lehet)
	m2 = MapSort(m2);		//m2-nek rendezve kéne lennie value alapján!
	auto mv = MapSortIntoVector(m1);
	auto m1i = m1.begin();			//ciklusból ki kellett helyezni, az auto m1i = m1.begin(), auto m2i = m2.begin()-re hibát adott ki
	auto m2i = m2.begin();
	auto mvi = mv.begin();
	cout << "\tDefault map order!\t\tValue sorted map order!\t\tValue sorted vector from map!" << endl << endl;
	for (; m1i != m1.end() && m2i != m2.end() && mvi != mv.end(); ++m1i, ++m2i, ++mvi)
	{
		cout << "\t" << m1i->first << "\t:\t" << m1i->second << "\t|\t" << m2i->first << "\t:\t" << m2i->second << "\t|\t" << mvi->first << "\t:\t" << mvi->second << endl;
	}
	//kiírásnál látszik, m1 és m2 ugyanúgy rendezett, KULCS alapján
}
