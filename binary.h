#ifndef BINARY_H
#define BINARY_H

#include <iostream>


using namespace std;

class binary 
{

	public :

		/* eisodos enas taxinomimenos pinakas, stoxos na vrume to stoixeio pu
		ziteitai.
		Se kathe vima tu algorithmu, ipodiplasiazetai to megethos tu pinaka 
		kai exetazetai to kedriko stoixeio. Sinexizontai oi anadromikes kliseis
		tu algorithmu mexri na vrethei i oxi to stoixeio, otan o pinakas 
		tha ftasei na exei 1 stoixeio mono
		*/	

		void binarySearch(int a[], int key, int start, int end, int steps)
{
	
	if(end < start)    {
    
	// an 0 pinakas kai den exei vrethei to stoixeio tote telos
	cout<<"\nTo stoixeio DEN vrethike!"<<endl;
	
	}

	else
	{
	 // ipologizw to meso tu pinaka, gia spasimo tu arxikou se 2 ipopinakes
        	int mid = (start + end)/2;
         

		if (a[mid] < key){
		steps++;
		// an to kleidi einai megalitero tu meseou stoixeiou,
		// tote anadromiki klisi binary gia elenxo tu ipopinaka
		binarySearch(a, key, mid+1, end, steps);
		
		}

        	else if (a[mid] > key){
		// an to kleidi einai megalitero tu meseou stoixeiou,
		// tote anadromiki klisi binary gia elenxo tu ipopinaka
		steps++;
		binarySearch(a, key, start, mid-1,steps);
		
		}

		
		else{
		steps++;
		// an to key den einai oute megalitero oute mikrotero, 
		// tote vrethike sto kedriko simeio !
		cout<<"\nTo stoixeio "<< key<<"  vrethike!"<<endl;
		cout<<"Vimata Binary Search: "<<steps<<endl;
							
		
		}

	}
}








};	// end class

#endif
