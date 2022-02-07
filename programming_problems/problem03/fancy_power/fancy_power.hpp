#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancy_power(int n, int m) //returns n^m
{
	int ans;
	
	if (m == 0) {ans = 1;}
	if (m == 1) {ans = n;}
	else if (m % 2) {ans = (n * fancy_power(n*n, (m-1)/2));}
	else {ans = fancy_power(n*n, m/2);}

	return ans;
}

#endif
