#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

using namespace std;

class mergesort
{

	public :
	
	
	/*
	diaxwrisi arxikou pinaka se 2 tmimata isou megethus,
	anadromiki klisi tu mergesort me skopo tin epimerous diaxwrismo
	twn 2 ipopinakwn mexri na ftasume se simeio o kathe pinakas na exei
	1 stoixeio mono. tote kaleitai i merge giasigxwneusi twn stoixeiwn 
	wste na paraxthei i teliki taxinomimeni exodos	
	*/


	void mergeSort(int *a, int*b, int low, int high,int& sigrisi)
	{
	
		int mid;	// dilwsi mesaiou stoixeiou pinaka gia diaxwrisi tou sta 2 

	/* anadromiki klisi mergesort gia diamerisi tou arxikou pinaka se 2 ipopinakes 
         /* stoxos o kathe pinakas na katalixei na exei ena stoixeio. */

                //an ta akra einai isa, tote telos diamerisis
                
                sigrisi++;
                
		if(low<high)
		{

                    // evresi mesaias thesis pinaka 

			mid=(low+high)/2;	

                        // anadromikes kliseis mergesort gia tous pinakes

			mergeSort(a,b,low,mid,sigrisi);

 
			mergeSort(a,b,mid+1,high,sigrisi);

                       /* paragwgi tou telikoy taxinomimenu pinaka me sinxwneusi twn ipopinakwn anadromika */

			merge(a,b,low,mid,high,sigrisi);

		}	// end if

	}	// end mergesort







// sinartisi merge gia tin sigxwneusi taxinominenwn pinakwn me eidoso tus 2 pinakes
// kai ta akriana stoixeia tus

	void merge(int *a, int *b, int low, int mid, int high,int& sigrisi)
	{
		int h,i,j,k;
		h=low;
		i=low;
		j=mid+1;
 

		// Merge in sorted form the 2 arrays
		while((h<=mid)&&(j<=high)){

			
		sigrisi++;
			if(a[h]<=a[j])
        		{
				
				//sigrisi++;
				b[i]=a[h];
				h++;
			}

			else
			{
				//sigrisi++;
				b[i]=a[j];
				j++;
			}

			i++;

		}	// end while 

		// Merge the remaining elements in right array
		if(h>mid)
		{
			

			for(k=j; k<=high; k++)
			{

			sigrisi++;

				b[i]=a[k];
				i++;
			} // end for

		} // end if 
	

		// Merge the remaining elements in left array
		else
		{
			
			
			for(k=h; k<=mid; k++)
			{

			sigrisi++;

				b[i]=a[k];
				i++;
			}

		}


		// apothikeusi ston arxiko pinaka ton temp b pinaka me tis taxinomimenes times 


		for(k=low; k<=high; k++) 
			a[k]=b[k];

	}// end merge






};	// end class

#endif
