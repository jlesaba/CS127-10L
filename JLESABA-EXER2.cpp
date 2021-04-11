/*
* Programmer: LESABA, John Kenneth S.
* Date Created: 5/18/2017
* Terminal No: 15
* Program: BSIT
* Course / Section: CS127-10L/BM1
*/
#include<iostream>
#include<iomanip>
using namespace std;

//global
const int size=10;
typedef double *pointers;
int ctr;
//milespergallon - this function is for the input, process and output of miles per gallon
void MilesPerrGallon(double *ptr1,double *ptr2);//process and final output of miles per gallon
void MperG();//input of miles and gallon with validation
//sorting
void sortSelect(int *xptr,int xselSize);//process sorting values using SELECTION technique
void selectInput(int *xptr,int xselSize);//input n numbers for selection
void selectOutput(int *xptr,int xselSize);//output n numbers in ascending and descending order

int main()
{
   char ans;

   do{
   system("cls");
   cout<<"----------O P T I O N S----------\n"
	   <<"[1] Compute Miles per Gallon \n"
	   <<"[2] Sorting of Numbers\n"
	   <<"[3] EXIT\n"
	   <<"---------------------------------\n"
	   <<"Enter your choice: ";
   cin>>ans;   	
   	try{
		   //add code here
		   if(isalpha(ans))
		   	throw char(ans);
			if(ispunct(ans))
				throw char(ans);
			
   	}
   catch(char e)
   {
	//add code here
		cout << e << " is an invalid input.";
   }
   }while (ans<'1'||ans>'3');

	switch(ans)
	{
	case '1':	//add code here
		MperG();
		break;
	case '2': {
		        int *point,max;
		        system("cls");
	            //add code here
	            cout << "Input array size: ";
	            cin >> max;
	            point = new int[max];
	          //calling of functions - sortSelect, selecInput andselectOutput
	        	selectInput(point,max);
	        	sortSelect(point,max);
	        	selectOutput(point,max);
	          }
		break;
	case '3': 
		char sagot;
		do{
		      //add code here
		      cout << "Are you sure you want to exit program?<y/n>";
		      cin >> sagot;
		      if(sagot == 'y')
		      	break;
		    	else if(sagot == 'n'){
		    		main();
				}
		}while(sagot!='n'&&sagot!='y');

		//add code here
		cout << "\nGoodbye!";
	}//end switch
	
}

/////////////////////////
void MperG()
{
    double miles[size],gallons[size];
	int ctr;
	pointers milPtr,galPtr;

	//add code here
	
	
	milPtr = &miles[0];
	for(ctr=0;ctr<size;ctr++)
	{
		//add code here
		while(true){
			cout << "Mile[" << ctr << "]: ";
			cin >> *(milPtr+ctr);
			try{
				if(*(milPtr+ctr) < 100 || *(milPtr+ctr) > 250)
					throw *(milPtr+ctr);
					
					//more code
					break;
			}
			catch(double x){
				cout << x << " is an invalid input. (Please enter from numbers 100 to 250 only)\n";
				continue;
			}
		}
		
	}//loop for miles
	
/*********************************************************/
//add code here
	galPtr = &gallons[0];
	for(ctr=0;ctr<size;ctr++)
	{
		//add code here
		while(true){
			cout << "Gallon[" << ctr << "]: ";
			cin >> *(galPtr+ctr);
			try{
				if(*(galPtr+ctr) < 5 || *(galPtr+ctr) > 20)
					throw *(galPtr+ctr);
					
					//more code
					break;
			}
			catch(double y){
				cout << y << " is an invalid input. (Please enter from numbers 5 to 20 only)\n";
				continue;
			}
		}
	}//loop for gallons


//calline function MilePerrGallon
	MilesPerrGallon(milPtr,galPtr);
}
////////////////////////
void MilesPerrGallon(double *ptr1,double *ptr2)
{

	//add code here
	double quo[size];
	pointers quoPtr;
	
	quoPtr = &quo[0];
	
	//process
	for(ctr=0;ctr<size;ctr++)
		*(quoPtr+ctr) = *(ptr1+ctr) / *(ptr2+ctr);
		
	//output
	cout << endl;
	for(ctr=0;ctr<size;ctr++){
		cout << setw(7) << "MPGe[" << ctr << "]: " << setprecision(2) << fixed << *(quoPtr+ctr);
	}
	
}

////////////////////////////////////////////////////////
void sortSelect(int *xptr,int xselSize)
{
	//add code here
	int loc,min,temp;
	for(ctr=0;ctr<xselSize-1;ctr++)
    {
        min=*(xptr+ctr);
        loc=ctr;
        for(int j=ctr+1;j<xselSize;j++)
        {
            if(min>*(xptr+j))
            {
                min=*(xptr+j);
                loc=j;
            }
        }
 
        temp=*(xptr+ctr);
        *(xptr+ctr)=*(xptr+loc);
        *(xptr+loc)=temp;
    }
} 

/////////////////////////////////////////////////////
void selectInput(int *xptr,int xselSize)
{
	
	//add code here
	cout << "Input " << xselSize << " numbers." << endl;
	for(ctr=0;ctr<xselSize;ctr++){
		cout << "Number[" << ctr << "]: ";
		cin >> *(xptr+ctr);
	}
	sortSelect(xptr,xselSize);
}
/////////////////////////////////////////////////////
void selectOutput(int *xptr,int xselSize)
{
	//add code here
	cout<<"ASCENDING ORDER\n";
 	for(ctr=0;ctr<xselSize;ctr++)
    {
        cout<<setw(5)<<*(xptr+ctr);
    }
      
    cout<<"\n\nDESCENDING ORDER\n";
	for(ctr=xselSize-1;ctr>=0;ctr--)
    {
        cout<<setw(5)<<*(xptr+ctr);
       
    }
     cout<<endl;
}
/////////////////////////////////////////////////////////

