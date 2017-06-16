#include "LevenshteinDistance.h"

/*
* Responsible for calculating the similarity between two strings using the Levenshtein distance metric
* 
* // info: https://en.wikipedia.org/wiki/Levenshtein_distance
* // credit to: http://rosettacode.org/wiki/Levenshtein_distance
* @param s1: first candidate string for similarity test
* @param s2: second candidate string for similarity test
* @param return: numeric measure of distance
*/
size_t uiLevenshteinDistance(const string &s1, const string &s2)
{
	const size_t m(s1.size());
	const size_t n(s2.size());
 
	if( m==0 ) 
	{
		return n;
	}

	if( n==0 ) 
	{
		return m;
	}
 
	size_t *costs = new size_t[n + 1];
 
	for( size_t k=0; k<=n; k++ ) 
	{
		costs[k] = k;
	}	
 
	size_t i = 0;
	for ( std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i )
	{
		costs[0] = i+1;
		size_t corner = i;
 
		size_t j = 0;
		for ( std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j )
		{
			size_t upper = costs[j+1];
			if( *it1 == *it2 )
			{
				costs[j+1] = corner;
			}
			else
			{
				size_t t(upper<corner?upper:corner);
				costs[j+1] = (costs[j]<t?costs[j]:t)+1;
			}
			corner = upper;
		}
	}
 
	size_t result = costs[n];
	delete [] costs;
 
	return result;
}