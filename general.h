#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>

using namespace std;

class general 
{

	public :


		void printMenu()
		{
			cout<<"\nPliktrologise 1 gia ylopoihsh algorithmou Taxinomisis"<<endl;	
			cout<<"Pliktrologise 2 gia ylopoihsh algorithmou Anazitisis"<<endl;
			cout<<"Pliktrologise 3 gia exodo apo programma !"<<endl;
			cout<<"Epilogi : ";	
		}


		void printMenuPeript()
		{
			cout<<"\nEktelesi algorithmwn se :"<<endl;
			cout<<"Pliktrologise   1   gia pinakes XEIROTERIS periptwsis "<<endl;	
			cout<<"\nPliktrologise   2   gia pinakes MESIS periptwsis "<<endl;
			cout<<"Epilogi : ";	
		
		}		


		void printMenuTaxin()
		{
	    
			cout<<"\nPliktrologise   1   gia ylopoihsh algorithmou Quicksort"<<endl;	
			cout<<"Pliktrologise   2   gia ylopoihsh algorithmou Mergesort"<<endl;
			cout<<"Pliktrologise   3   gia ylopoihsh algorithmou Bubblesort "<<endl;
			cout<<"Epilogi : ";
		}



		void printMenuArxeiou()
		{
	    
		cout<<"\nSe poio arxeio thes na ginei taxinomisi ?"<<endl;

		cout<<"\nPliktrologise   1   gia arxeio F1 ( 1000 arithmoi )"<<endl;	
		cout<<"Pliktrologise   2   gia arxeio F2 ( 5000 arithmoi )"<<endl;
		cout<<"Pliktrologise   3   gia arxeio F3 ( 10000 arithmoi )"<<endl;
		cout<<"Pliktrologise   4   gia arxeio F4 ( 50000 arithmoi )"<<endl;
		cout<<"Pliktrologise   5   gia arxeio F5 ( 100000 arithmoi )"<<endl;	
		cout<<"Epilogi : ";
		}


		void printMenuAnaz()
		{
	    
		cout<<"\nAlgorithmoi Anazitisis! "<<endl;
		cout<<"\nPliktrologise 1 gia ylopoihsh algorithmou Binary Search"<<endl;	
		cout<<"Pliktrologise 2 gia ylopoihsh algorithmou Binary Interpolation Search"<<endl;
		cout<<"Epilogi : ";
		}


		void print(int array[], int N)
		{
    			for(int i = 0 ; i <= N ; i++)
			{
				cout << " " << array[i] ;
			}

			cout<< endl;

		}


		void swap(int& a, int& b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		




};	// end class

#endif
