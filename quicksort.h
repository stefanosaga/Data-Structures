#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include "general.h"

using namespace std;

class quicksort 
{

	public :
            
            /* eisodos enas pinakas, emeis epilegoume ena stoixeio pivot-diaxwristi
              me vasi ton opio diaxwrizume ton pinaka se 2 ipopinakes , opou
             o prwtos exei ola ta stoixeia x<pivot kai o allos x>pivot 
             akolou8eitai anadromiko kalesma sinartisewn quicksort, me skopo
             tin epipleon diaxwrisi twn ipopinakwn me neo pivot kathe fora.
			 
             */

		void quickSort( int a[], int first, int last, int& sigrisi ) 
		{
                    
			int pivotElement;
 
                        // an o pinakas exei ftasei se simio ppou periexei monades
                        // tote telos anadromikwn klisewn 
    			if(first < last)
    			{
                            /* orise pivot*/
       				pivotElement = pivot(a, first, last, sigrisi);
                                
                                // anadromiki klisi quicksort gia na ftiaxume ton pinaka
                                
				quickSort(a, first, pivotElement-1,sigrisi);
				quickSort(a, pivotElement+1, last,sigrisi);
    			}
                     
		}


		
		int pivot(int a[], int first, int last, int& sigrisi ) 
		{
            /*
			orizw thesi gia tis enalages stoixeiwn <pivot kai >pivot. 
			diatrexw pinaka kai kanw tis kataliles enalages me ti voitheia tis thesis
			wste na o pinakas na exei apo ti mia pleura ta megalitera
			kai apo tin alli ta mikrotera stoixeia			
			*/
			int  thesi = first;
			
            // orise san pivot diaxwristi to prwto stixio tu pinaka 
			int pivotElement = a[first];
			
 
			for(int i = first+1 ; i <= last ; i++)
			{
                            
				sigrisi++;
				
                                
				if(a[i] <= pivotElement)
				{
					
					thesi++;
					swap(a[i], a[thesi]);
					
				}
			}
 			
			swap(a[thesi], a[first]);
			//sigrisi++;
 
			return thesi;

		}


};	// end class

#endif
