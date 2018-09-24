#ifndef BININTSEARCH_H
#define BININTSEARCH_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdio.h>


using namespace std;

class binIntSearch 
{

	public :
	
		/* binary interpolation search, ginetai ektimisi 
		tis thesis tu stoixeiu, analoga me to poso megalitero 
		einai to zitumeno stoixeio apo to left kai poso megalitero
		einai to rigth apo to left. ipologizume diastima
		kai sti sinexia kanume vimata rizas size gia na
		ipologisume to epomeno diastima pros anazitisi
		tou stoixeiou. 
		Otan exume ftasei se ena mikro diastima anazitisis
		tote ektelume gramiki anazitisi 
		
		*/
			

void bis(int a[], int x, int left, int num, int steps)
{
	 
	int next, size, i,right;

	float tnext=0;

  
    right = num-1;

	size = right - left + 1;

// ipologismos ektimiss thesis 
    
	tnext = ceil(size*(float)(x-a[left]) / (a[right] - a[left]));
	next = (int)tnext; //gia to roundup
    
	if (next >= size)
		next = size -1;
    
	while (x != a[next])
	{
		steps++;
		// grammiki anazitisi stoixeiou
		if ((right-left+1) <=3)
		{

			for (int i=left; i<=right; i++)
			{
				
				steps++;
				if (a[i] == x)
				{
					
					cout<<"\nTo stoixeio "<< x<<"  vrethike!"<<endl;
					cout<<"Vimata Binary Interpolation Search: "<<steps<<endl;
					
					return;
                		}
            		}
			cout<<"\nTo stoixeio "<< x<<" DEN vrethike!"<<endl;
			
			return;
		}

		i = 0;
		size = right - left + 1;
		
		// ipologismos neou diastimatos anazitisis

		if (x>=a[next])
		{
			//steps++;
			while (x>a[next+i*int(sqrt(size))-1]) i++;

			right = next + i*int(sqrt(size));
			left = next + (i-1)*int(sqrt(size));
            
			if (right >= num)
			{

				right = num-1;
				left = right - int(sqrt(size));
			}
 		}
		else if (x<a[next] && next !=0)
		{
			//steps++;

			while (x<a[next - i*int(sqrt(size))+1]) i++;

			right = next - (i - 1)*int(sqrt(size));
			left = next - i*int(sqrt(size));
		}

		if (a[right] - a[left] !=0)
		{
			//steps++;
			tnext = ceil((float)((right-left+1)*(x-a[left]) / (a[right] - a[left])));
			next = left + (int)tnext -1;
		}
	}

	if (x==a[next])
	{
		steps++;
		cout<<"\nTo stoixeio "<< x<<"  vrethike!"<<endl;
		cout<<"Vimata Binary Interpolation Search: "<<steps<<endl;
							
        	
	}	

}// end void 



};	// end class

#endif
