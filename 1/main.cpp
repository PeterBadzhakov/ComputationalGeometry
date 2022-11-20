#include <iostream>

#include "../include/vecta.h"

using namespace vecta;
using namespace std;

bool eq(double lhs, double rhs)
{
	return abs(lhs - rhs) < 0.0001;
}
template<typename T>
int sign(const T& var)
{
	if (var > 0)
	{
		return 1;
	}
	else if (var == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	x y -> A
	x y -> B
	x y -> C
	x y -> P
	
	Where is P w.r.t ABC triangle?
	1) inside
	2) outside
	3) edge or vertex (which?)

	[ABP] [BCP] [CAP] cycling order of ABC and putting P in the end.
		compare with
	[ABC]=[BCA]=[CAB] (all 3 are equal because letters are cyclic)
	=> point is inside <=> sign(1) = sign(2) = sign(3) = sign([ABC])

	If only 2 are = 0 => P is the meeting point
	If only one is = 0 and 2 others have = signs => P is on the first line
*/

int main()
{
	vec2d<Number> a, b, c, p;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> p.x >> p.y;

	if (eq(a.x, p.x) && eq(a.y, p.y))
	{
		cout << "P == A";
		return 0;
	}
	if (eq(b.x, p.x) && eq(b.y, p.y))
	{
		cout << "P == B";
		return 0;
	}
	if (eq(c.x, p.x) && eq(c.y, p.y))
	{
		cout << "P == C";
		return 0;
	}

	auto abp = (b - a) ^ (p - a),
		bcp = (c - b) ^ (p - b),
		cap = (a - c) ^ (p - c),
		abc = (b - a) ^ (c - a);
	

	return 0;
}
