#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include "general.h"

using namespace std;

class bubblesort
{

	public :
            
            /* sarwsi olou tu pinaka eisodou apo tin arxi, kathe fora 
             pou vriskei katalilo zeugos gia enallagi, tin pragmatopoiei
             me stoxo tin prwti fora to megalitero stoixeio tou pinaka
             na exei paei stin teleutaia thesi tu neou taxinomimenou pin*/


		void bubbleSort(int array[], int N, int& sigrisi) 
		{
	
			for (int i = 0 ; i < N  ; i++)
			{

				for (int j = N ; j > i ; j--)
				{	
                                        sigrisi++;
					if (array[j - 1] > array[j])
                                        {
                                            
						swap(array[j], array[j - 1]);
					}
        			}
    			}
		}


};	// end class

#endif
