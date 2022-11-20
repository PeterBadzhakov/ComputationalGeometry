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

bool parallel(const vec2d<Number>& lhs, const vec2d<Number>& rhs)
{
	return ((lhs + rhs) == vec2d<Number>(0, 0));
}

/*
	x y -> A
	x y -> B
	x y -> C
	x y -> D

	ABCD е:
	прост (няма самопресичане)
	изпъкнал
	успредник
	правоъгълник
	квадрат
	ромб
	делтоид (2х2 равни дължини като издължен ромб
	трапец
	вписан
	описан
*/

int main()
{
	vec2d<Number> a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	 
	// диагоналите BD и AC са вътрешни
	// BD - вътрешен <=> B и D са в различни полуравнини спрямо AC
	// тоест sign([ACD]) != sign([ACB]) и sign([BDA]) != sign([BDC]
	bool prost = sign((a^c) + (c^d) + (d^a)) != sign((a ^ c) + (c ^ b) + (b ^ a)) && true;

	// изпъкнал: прост
	bool izpuknal = prost && true;

	// успоредник: AB || DC
	bool usporednik = prost && izpuknal && parallel(b-a, c-d);
	
	// правоъгълник: успоредник с прави ъгли, AD.AB = 0
	bool pravougulnik = prost && izpuknal && usporednik && ( eq((d-a)*(b-a), 0) );

	// квадрат: правоъгълник с равни страни, d(AB) == d(AD)
	bool kvadrat = prost && izpuknal && pravougulnik && ( eq((b-a)*(b-a), (d-a)*(d-a)) );

	// трапец: две двойки успоредни страни AB || DC или AD || CB
	bool trapec = prost && izpuknal && (parallel(b - a, c - d) || parallel(d - a, b - c));

	// делтоид: например AD == DC и AB == BC
	bool deltoid = prost && izpuknal && (eq(len(d - a), len(c - d))) && (eq(len(b - a), len(c - b)));

	// romb: делтоид с равни страни, AD == AB
	bool romb = deltoid && eq(len(d-a), len(b-a));

	// вписан: сбор от срещуположни ъгли е 180*
	// <(DAB) + <(BCD) == 180* <=> <(AB, AD) + <(CD, CB) == 180*
	bool vpisan = prost && izpuknal && (eq(angle(b-a, d-a) + angle(d-c, b-c), PI));

	// описан: AB + DC = AD + BC
	bool opisan = prost && izpuknal && eq(len(b-a) + len(c-d), len(d-a) + len(c-b));

	return 0;
}
