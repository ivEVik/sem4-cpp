#include "sort.h"


template<class T> void Sort(T* array, const size_t length)
{
	bool cycle = true;
	while(cycle)
	{
		cycle = false;
		
		for(size_t t = 0; t < length; ++t)
			if(array[t] < array[t - 1])
			{
				T a = array[t];
				array[t] = array[t - 1];
				array[t - 1] = a;
				
				cycle = true;
			}
	}
}

template void Sort<int>(int* array, const size_t length);
