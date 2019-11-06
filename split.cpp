#include <iostream>
#include <sstream>

using namespace std;

void split(uint64_t address)
{
	const uint64_t mask{((uint64_t)1 << 9) - 1};

	for (uint64_t i = 0; i < 4; i++)
	{
		uint64_t shift{(3 - i) * 9 + 12};
		uint64_t index{(address & (mask << shift)) >> shift};
		cout << hex << index << ' ';
	}

	cout << endl;
}

main(int argc, const char* argv[])
{
	if (argc == 2)
	{
		uint64_t x;
		stringstream ss;
		ss << hex << argv[1];
		ss >> x;
		split(x);
	}
	else
	{
		cout << "correct syntax: split <address>" << endl;
	}
}
