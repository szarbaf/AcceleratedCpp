#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;		using std::sort;

template <class T>
T template_median (vector<T> input){
	
	typedef typename vector<T>::size_type cont_size;
	cont_size mid = input.size() / 2;
	//Sorting the input.
	sort(input.begin(), input.end());
	//Finding the center element.
	return input.size() % 2 == 0 ? (input[mid-1]+input[mid])/2 : input[mid];
}

template <class It, class X>
It template_find(It beg, It end, const X &sample)
{
	while(beg != end && *beg != sample)
		beg++;
	return beg;
}

template <class It, class X>
It equal(It b, It e, const X &obj)
{
	while(b != e && *b != obj)
		b++;

	return b;
}

template <class Iti, class Ito>
void copy (Iti b, Iti e, Ito out)
{
	while(b != e)
		*out++ = *b++;
}

template <class Iti, class Ito, class X>
Ito remove_copy(Iti b, Iti e, Ito d, const X &obj)
{
	while(b != e)
	{
		if(!(*b == obj)
			*d++ = *b;
		b++;
	}
}

template <class Iti, class Ito, class X>
Ito remove_copy_if(Iti b, Iti e, Ito d, X UnPred)
{
	while(b != e)
	{
		if  ( !UnPred(b) )
		
	}
}

