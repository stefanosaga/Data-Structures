#include <iostream>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "general.h"
#include "binary.h"
#include "binIntSearch.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <fstream>

#include <sstream>
#include <string>

using namespace std;




int main() 
{

string str;

clock_t start, end;	// metavlites xronou
double diarkeia;	// metavliti diarkeias 
int epan=0;		// epanaliyi peiramatos
int menu, taxin, anaz, pinakas, arxeio;	// int epilogis menu-taxinomisis-anazitisis-xeiristis/mesis-arxeiou
int num, numFile,lines, key, numSearch ,k=0; // voithitikes metavlites gia arxeia 
int vimata =0, sigrisi;	// vimata anazitisewn,sigrisewn  
int * Darray;	// dynamic allocation gia times pros taxinomisi
int * Dtemp;	// voithitikos gia epanafora timwn 
int * Dbinary;	// pinakas binary search
int * arrayMerge;  // voithitikos gia mergesort

// eisagwgi pros epexergasia twn dosmenwn arxeiwn 
ifstream myfile1 ("/home/stefanosaga/Desktop/Link to domes/1/f1.txt");
ifstream myfile2 ("/home/stefanosaga/Desktop/Link to domes/1/f2.txt");
ifstream myfile3 ("/home/stefanosaga/Desktop/Link to domes/1/f3.txt");
ifstream myfile4 ("/home/stefanosaga/Desktop/Link to domes/1/f4.txt");
ifstream myfile5 ("/home/stefanosaga/Desktop/Link to domes/1/f5.txt");

// antikeimena klasewn algorithmwn kai genikwn pliroforiwn 
general gen;
quicksort quick;
mergesort merge;
bubblesort bubble;
binary bin;
binIntSearch bis;
	cout<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"*                    TAXINOMISI / ANAZITISI                        *"<<endl;
	cout<<"********************************************************************"<<endl<<endl;
	do{ 

	cout<<"\n\t------- MENU TAXINOMISIS / ANAZITISIS --------"<<endl;

			/* menu vasikwn epilogwn  */
	gen.printMenu();

	cin >> str; 
        istringstream buffer(str);
	buffer >> menu;
	
	//cin>>menu;	

		// switch gia vasiko menu 
		switch (menu){
			

			// epilogi 1, ilopihsh algorithmou taxinomisis 
			case 1:
				//mesi h xeiroteri periptwsi???
				gen.printMenuPeript();

					
				
				cin>>pinakas;	// epilogi pinaka

				// switch periptwsi pinakwn 
				switch (pinakas){

				// epilogi pinaka 1 gia xeiroteri periptwsi, me dosmeno sinolo stoixeiwn apo xristi
				case 1:	

				cout<<"\n\tPosa stoixeia theleis ston pinaka?"<<endl;
				cin>>num;
			
				//  dimiurgia pinakwn analoga me to dosmeno num tu xristi
				Darray= new int [num];
                                Dtemp= new int [num];
					
				// ekxwrisi stoixeiwn stus pinakes gia xeiristi periptwsi
				// XEIRISTI PERIPTWSI = PINAKAS MEGALITERO -> MIKROTERO  

				for (int j = num-1 ; j > 0; j--){
					Darray[k] = j;
					Dtemp[k] = Darray[k];
					k++;
				}
                                				
				cout<<"\nAlgorithmoi Taxinomisis se pinakes xeiroteris periptwsis! "<<endl;
			
				gen.printMenuTaxin();
				cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	

					switch (taxin){

					// QUICKSORT !
					case 1:
						while(epan!=2)
						{
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl; 
    							//gen.print(Darray, k-1 );
                                                        

							start = clock();
							quick.quickSort(Darray,0, k, sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"\n1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout <<"\nXronos ektelesis Quicksort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

					case 2:

					arrayMerge= new int [k];


					while(epan!=2)
					{

						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



					case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-1]<<"\n(N)sto stoixeio :"<<Darray[k]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;


								
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;


                                        
                                    }//end  
					

				
					cout<<"\n---------------"<<endl;
		
					break;  //break menu gia taxinomisi

				
				break; 	// break case 1 pinaka 

				
				case 2:	// ilopihsh taxinomisewn se mesis periptwsis ( dosmena arxeia f1, f2...)


				gen.printMenuArxeiou();
				cin>>arxeio;	// epilogi vasikou menou gia alg taxinom	


				switch (arxeio){
                         


				// epilogi 1, arxeio f1
				case 1: 
					

					Darray= new int [999]; // orismos megethus analoga to arxeio 
                               		Dtemp= new int [999];
                                        
                                        k=0; // metrima lines arxeiou 
                                           
					// elenxos gia swsto open arxeiou
					if (myfile1.is_open())
					{
						// diavasma int ana grammi apo to arxeio, kai ekxwrisi tu ston Darray
						while ( myfile1 >> numFile) 
						{
							//cout << numFile <<" ";
							Darray[k]=numFile;
                                                 	Dtemp[k]=numFile;
							k++;                                                       
						}
                                               	cout<<endl;
                                                
                                            cout<<endl<<"LINES :"<<k<<"\n1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;    
    

					myfile1.close();
					}

					else cout << "Unable to open f1.txt"<<endl;  
                                        

					gen.printMenuTaxin();    
					cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	
                                    	switch (taxin){
					
					// case gia quicksort
					case 1:
                                        
                                      		
						while(epan!=2)
						{   
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    							//gen.print(Darray, k-1 );

							start = clock();
							quick.quickSort(Darray,0, k-1,sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout<<"\nXronos ektelesis QuickSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k-1 ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

					case 2:

					arrayMerge= new int [k-1];


					while(epan!=2)
					{
						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout<<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k-1 ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



					case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k-1 ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;

							
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;


                                        
                                    }//end  
					

					

				break; 	// break case f1.txt

				// epilogi 2, arxeio f2
				case 2:

						k=0;
                                                                   
                                                
						Darray= new int [4999];
                               			Dtemp= new int [4999];

						if (myfile2.is_open())
						{
							while ( myfile2 >> numFile) 
							{
								Darray[k]=numFile;
                                              	          	Dtemp[k]=numFile;
								k++;                                                       
						}
                                                
                                                                                                                                              
                                            	cout<<endl<<"LINES :"<<k<<"\n1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;    
                                            		
                                       		myfile2.close();
						}

						else {
						cout << "Unable to open f2.txt"<<endl;  
						}                                        
                                        

                                 	gen.printMenuTaxin();
                                    	cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	
                                    	switch (taxin){

                                    	case 1:
                                        
                                      		
						while(epan!=2)
						{
                                                    
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    							//gen.print(Darray, k-1 );

							start = clock();
							quick.quickSort(Darray,0, k-1,sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout<<"\nXronos ektelesis QuickSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k-1 ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

				case 2:

					arrayMerge= new int [k-1];


					while(epan!=2)
					{

						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout<<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k-1 ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



				case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
                                                cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
                                                
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k-1 ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;


								
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;


                                        
                                    }//end  
					


				break; 	// break case f2.txt

				// epilogi 3, arxeio f3
				case 3:

						k=0;
                                                                   
                                                
						Darray= new int [9999];
                               			Dtemp= new int [9999];

						if (myfile3.is_open())
						{
							while ( myfile3 >> numFile) 
							{
								//cout << numFile <<" ";
								Darray[k]=numFile;
                                              	          	Dtemp[k]=numFile;
								k++;                                                       
						}
                                                	cout<<endl<<"LINES :"<<k<<endl;
                                                                                                
                                            		//for (int j = 0; j < 50; j++){
                                            		//	cout<<Darray[j]<<endl;	
                                            		//}
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;    
                                            		
                                            
                                           
                                       		myfile3.close();
						}

						else {
						cout << "Unable to open f3.txt"<<endl;  
						break;
						}                                        
                                        

                                    
                                    
					gen.printMenuTaxin();    
                                         
                                    	cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	
                                    	switch (taxin){

                                    	case 1:
                                        
                                        
                                      		
						while(epan!=2)
						{
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    							//gen.print(Darray, k-1 );

							start = clock();
							quick.quickSort(Darray,0, k-1,sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout<<"\nXronos ektelesis QuickSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k-1 ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

				case 2:

					arrayMerge= new int [k-1];


					while(epan!=2)
					{

						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout<<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k-1 ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



				case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k-1 ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;


								
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;



                                        
                                    }//end  
					


				break; 	// break case f3.txt


				// epilogi 4, arxeio f4
				case 4:

						k=0;
                                                                   
                                                
						Darray= new int [49999];
                               			Dtemp= new int [49999];

						if (myfile4.is_open())
						{
							while ( myfile4 >> numFile) 
							{
								//cout << numFile <<" ";
								Darray[k]=numFile;
                                              	          	Dtemp[k]=numFile;
								k++;                                                       
						}
                                                	cout<<endl<<"LINES :"<<k<<endl;
                                                                                                
                                            		//for (int j = 0; j < 50; j++){
                                            		//	cout<<Darray[j]<<endl;	
                                            		//}
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;    
                                            		
                                            
                                           
                                       		myfile4.close();
						}

						else {
						cout << "Unable to open f4.txt"<<endl;  
						break;
						}                                        
                                        

                                    
                                    
					gen.printMenuTaxin();    
                                         
                                    	cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	
                                    	switch (taxin){

                                    	case 1:
                                        
                                        
                                      		
						while(epan!=2)
						{
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    							//gen.print(Darray, k-1 );

							start = clock();
							quick.quickSort(Darray,0, k-1,sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout<<"\nXronos ektelesis QuickSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k-1 ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

				case 2:

					arrayMerge= new int [k-1];


					while(epan!=2)
					{

						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout<<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k-1 ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



				case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k-1 ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;


								
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;


                                        
                                    }//end  
					

			

				break; 	// break case f4.txt
	




				// epilogi 5, arxeio f5
				case 5:

						k=0;
                                                                   
                                                
						Darray= new int [99999];
                               			Dtemp= new int [99999];

						if (myfile5.is_open())
						{
							while ( myfile5 >> numFile) 
							{
								//cout << numFile <<" ";
								Darray[k]=numFile;
                                              	          	Dtemp[k]=numFile;
								k++;                                                       
						}
                                                	cout<<endl<<"LINES :"<<k<<endl;
                                                                                                
                                            		//for (int j = 0; j < 50; j++){
                                            		//	cout<<Darray[j]<<endl;	
                                            		//}
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;    
                                            		
                                            
                                           
                                       		myfile5.close();
						}

						else {
						cout << "Unable to open f5.txt"<<endl;  
						break;
						}                                        
                                        

                                    
                                    
					gen.printMenuTaxin();    
                                         
                                    	cin>>taxin;	// epilogi vasikou menou gia alg taxinom	
	
                                    	switch (taxin){

                                    	case 1:
                                        
                                        
                                      		
						while(epan!=2)
						{
                                                    sigrisi=1;

							cout<<"\n\tQUICKSORT! "<<endl;
							cout << "\nO pinakas PRIN to QuickSort: " <<endl;
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    							//gen.print(Darray, k-1 );

							start = clock();
							quick.quickSort(Darray,0, k-1,sigrisi);
							end = clock();
										
							cout << "\nO pinakas META to QuickSort: " << endl;
    							//gen.print(Darray, k-1);
							cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl;

							diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
							cout.precision(15);
							cout<<"\nXronos ektelesis QuickSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

							cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
							cin>>epan;

							for (int j = 0; j <= k-1 ; j++){
								Darray[j] = Dtemp[j];
							}
                                      
									
						}// while epanaliyis

						epan=0;	
																																									
					break; 

				case 2:

					arrayMerge= new int [k-1];


					while(epan!=2)
					{

						sigrisi=1;

						cout<<"\n\tMERGESORT! "<<endl;
						cout << "\nO pinakas PRIN to MergeSort: " <<endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						start = clock();					
						merge.mergeSort(Darray, arrayMerge,0, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to MergeSort: " << endl;
   						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 	

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout<<"\nXronos ektelesis MergeSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;
						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

						for (int j = 0; j <= k-1 ; j++){
							Darray[j] = Dtemp[j];
						}

                                        
									
					}// while epanaliyis
						
					epan=0;

								
					break;



				case 3:

					while(epan!=2)
					{
                                            sigrisi=1;

						cout<<"\n\tBUBBLESORT ! "<<endl;
						cout << "\nO pinakas PRIN to BubbleSort: " <<endl;
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 
    						//gen.print(Darray, k-1);

						start = clock();
						bubble.bubbleSort(Darray, k-1,sigrisi);
						end = clock();

						cout << "\nO pinakas META to BubbleSort: " << endl;
    						//gen.print(Darray, k-1 );
						cout<<"1o stoixeio :"<<Darray[0]<<"\n2o stoixeio :"<<Darray[1]<<"\n(N-1)sto stoixeio :"<<Darray[k-2]<<"\n(N)sto stoixeio :"<<Darray[k-1]<<endl; 

						diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
						cout.precision(15);
						cout <<"\nXronos ektelesis BubbleSort: "<<fixed<<diarkeia<<"\nSigriseis : "<<sigrisi<<endl;

						cout<<"\nEpanaliyi peiramatos ? \nPata 1 gia NAI \nPata 2 gia OXI"<<endl;
						cin>>epan;

					for (int j = 0; j <= k-1 ; j++){
						Darray[j] = Dtemp[j];
					}

                                        				
					}// while epanaliyis
						
					epan=0;


								
					break;
			
					default:
				
					cout<<"\nLathos !\n"<<endl;			
					
					break;
                                    }//end  
					

				break; 	// break case f5.txt
	


				default:// default break case .txt
				
				cout<<"\nLathos sta arxeia!\n"<<endl;
			
				break; // break case default .txt

									
				} // switch arxeio


				break; 	// break case2 pinakwn 
				
				
	
				default:// case default pinakwn 
				
						cout<<"\nLathos epilogi Pinaka periptwsewn!\n"<<endl;
			
				break; // break case default pinakwn 

									
				} 	// end switch pinakwn 
				

// ===================================================== TELOS pinakwn  ==============================================================

	

                        menu=3;
			break;	// break epilogis 1 MENU gia taxinomisi




// ===================================================== ANAZITISIS  ==============================================================



			//epilogi 2, ilopihsh algorithmu anazitisis
			case 2:
	
				gen.printMenuAnaz();

				cin>>anaz;	// epilogi vasikou menou gia alg anaz


		cout<<"\nPosa stoixeia thes na exei o pinakas gia anazitisi ? "<<endl;

		cin>>numSearch;
		Dbinary= new int [numSearch];

				for (int j = 0 ; j < numSearch; j++){
						
					Dbinary[j] = j;
				}	
						

			switch (anaz){
			

				// epilogi 1, ilopihsh algorithmou taxinomisis
				case 1:

					cout<<"\n\tBINARY SEARCH! "<<endl;
					cout << "\nO pinakas pros anazitisi : " <<endl;
    					gen.print(Dbinary, numSearch-1);

					cout<<"\nPio stoixeio thes na yaxeis ? "<<endl;
					cin>>key;
		
					start = clock();
					bin.binarySearch(Dbinary, key, 0,  numSearch, vimata) ;
  					end = clock();

					diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
					cout.precision(15);
					cout<<"\nXronos ektelesis Binary Search: "<<fixed<<diarkeia<<endl;



				break; 	// break case binary

				case 2:


					cout<<"\n\tBINARY INTERPOLATION SEARCH! "<<endl;
                                        cout << "\nO pinakas pros anazitisi : " <<endl;
    					gen.print(Dbinary, numSearch-1);

					cout<<"\nPio stoixeio thes na yaxeis ? "<<endl;
					cin>>key;
		
					start = clock();
					bis.bis(Dbinary, key, 0,  numSearch, vimata) ;
  					end = clock();

					diarkeia = ((double) (end-start)) / CLOCKS_PER_SEC ;
					cout.precision(15);
					cout<<"\nXronos ektelesis Binary Interpolation Search: "<<fixed<<diarkeia<<endl;


					

				break; 	// break case binary INTERPOLATION
	


				default:// case default anazitisi
				
					cout<<"\nLathos stin anazitisi\n"<<endl;
			
				break; // break case default anazitisi

									
			} // switch anazitisi

                        menu=3;
			cout<<"\n---------------"<<endl;
			break;	//break menu anazitisi		


			//epilogi 3, telos programmatos
			case 3:
	
				cout<<"\nTelos programmatos! "<<endl;
				
			cout<<"---------------\n"<<endl;
			break;//break menu gia 3i epilogi


			default:
				
				cout<<"\nLathos epilogi !!  Xanaprospathise !\n"<<endl;			
			break;
		}
                
           
	
	}while(menu!=3); // telos programmatos otan patisei o xristis to 3

//delete [] Dtemp;
//delete [] Darray;
return 0;


}	// end main



