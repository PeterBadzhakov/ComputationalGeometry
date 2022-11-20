#include <iostream>
#include <vector>

#include "../include/vecta.h"

using namespace std;
using namespace vecta;

Number dist(vec2d<Number>& lhs, vec2d<Number>& rhs);
vec2d<Number>& find_closest(vec2d<Number>& what, vector<vec2d<Number>>& where);

/*

	Имплементирайте алгоритъм за рязане на уши
	(Ван Гог) за редица точки, образуващи многоъгълник.

*/

int main()
{
	vector<vec2d<Number>> v;
	
	for (auto i = 0; i < 5; ++i)
	{
		cin >> v[i].x >> v[i].y;
	}

	return 0;
}

Number dist(vec2d<Number>& lhs, vec2d<Number>& rhs)
{
	return len(rhs - lhs);
}

vec2d<Number>& find_closest(vec2d<Number>& what, vector<vec2d<Number>>& where)
{
	size_t min_dist = size_t(-1);
	vec2d<Number>* closest_vec = nullptr;

	for (auto& curr_vec : where)
	{
		size_t curr_dist = dist(what, curr_vec);
		
		if (curr_dist > 0 && curr_dist < min_dist)
		{
			closest_vec = &curr_vec;
			min_dist = curr_dist;
		}
	}

	return *closest_vec;
}
