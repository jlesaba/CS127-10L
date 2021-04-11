#include<iostream>
#include<iomanip>
using namespace std;

//global declaration
const int colSize=4;
const int rowSize=3;
int ctr;
int row,col;
int srow,scol;
char opt;
//function declaration
void choiceMenu(); //display the menu of the program
char choice(char opt);//containing the validation of choices (1-2) if valid, will return the value of 1 or 2 //otherwise, will return to the main function to process the program from start.
void sortSelect(int xSelect[],int xselSize);//process sorting values using SELECTION technique
void selectInput(int xSelect[],int xselSize);//input 10 numbers for [1]selection
void selectOutput(int xSelect[],int xselSize);//output 10 numbers in ascending and descending order
void searchAssign(int xSearch[][colSize],int xRow);//process the assignments of elements 
int binarySearch(int xSearch[ ][colSize],int target,int xRow);//process and handles the searching using //BINARYsearching method
char tryAgain();//prompt the user to try again with validation and return the answer 'n' or 'y'

int main()
{
	//add declaration here
	char choice;
	const int rowsize=10;
	int Row;
	int selSize;
	int Select[rowsize];		
	int arr[rowSize][colSize]={2,4,6,8,
							   10,20,30,40,
							   55,65,75,85};
	int xtarget;
	
	choiceMenu();
	cout<<"Enter your choice here: ";
	cin>>choice;
	system("cls");
	switch(choice)//add code here)
	{
		case'1'://selection sorting 1D
				{	
					selectInput(Select,rowsize);
					sortSelect(Select,rowsize);
					selectOutput(Select,rowsize);	
				}//end case1
		break;
		
		case '2'://binary searching 2D
				{
					searchAssign(arr,Row);
					binarySearch(arr,xtarget,Row);
				}//end case2
	}//end switchcase
	   system("pause");
	  
	tryAgain();
	
	 
	  cout<<endl;
}//end main
//////////////////////////////////////////////////////
void choiceMenu()
{	

	cout<<"CHOICES" << endl;
	cout << "[1]Selection Sort" << endl;
	cout << "[2]Binary Searching" << endl;
		
		   	
}
///////////////////////////////////////////////////////
char choice(char opt)
{
	do
	{
	choiceMenu();
	}while( opt!='1' && opt!='2');
		
	return opt;
}
////////////////////////////////////////////////////////
void sortSelect(int xSelect[],int xselSize)
{
	int i;
	int min;
	int temp;
	int loc;
	int j;
 	for(i=0;i<xselSize-1;i++)
    {
        min=xSelect[i];
        loc=i;
        for(j=i+1;j<xselSize;j++)
        {
            if(min>xSelect[j])
            {
                min=xSelect[j];
                loc=j;
            }
        }
 
        temp=xSelect[i];
        xSelect[i]=xSelect[loc];
        xSelect[loc]=temp;
    }
 

}
/////////////////////////////////////////////////////
void selectInput(int xSelect[],int xselSize)
{
	int i;
	cout<<"your choice is 1 - SELECTION SORTING\n";
	cout<<"Please enter 10 numbers to be sorted\n";
	
	for(i=0;i<xselSize;i++)
	{
		cout<<"number["<<i<<"]: ";
		cin>>xSelect[i];
	}	
}
/////////////////////////////////////////////////////
void selectOutput(int xSelect[],int xselSize)
{
	int i;
	cout<<"ASCENDING ORDER\n";
 	for(i=0;i<xselSize;i++)
    {
        cout<<setw(5)<<xSelect[i];
    }
      
    cout<<"\n\nDESCENDING ORDER\n";
	for(i=9;i>=0;i--)
    {
        cout<<setw(5)<<xSelect[i];
       
    }
     cout<<endl;
}
/////////////////////////////////////////////////////////
void searchAssign(int xSearch[ ][colSize],int xRow)
{
	int arr[rowSize][colSize]={2,4,6,8,
							   10,20,30,40,
							   55,65,75,85};
	cout<<"your choice is 2 - BINARY SEARCH\n";
	for(row=0;row<rowSize;row++)
	{
		for(col=0;col<colSize;col++)
		{
			cout<<setw(5)<<arr[row][col];
		}
		cout<<endl;
	}

}
///////////////////////////////////////////////////////////////
int binarySearch(int xSearch[ ][colSize],int target,int xRow)
{
	int tar;
	int arr[rowSize][colSize]={2,4,6,8,
							   10,20,30,40,
							   55,65,75,85};
	cout<<"Input your target key from the table above: ";
	cin>>tar;
	
	if(tar==2,4,6,8,10,20,30,40,55,65,75,85)
	{
		
		cout<<"Target value found" << endl << endl;
		
	}
	else{
		cout<<"Target value is not found" << endl << endl;
	}
}
//////////////////////////////////////////////////////////
char tryAgain()
{
	char answer;
system("cls");
cout<<"Do you want to try again? ";
cin>>answer;

do{
	if(answer=='y')
	{
		system("cls");
		main();
	}
	else if(answer== 'n')
	{
		cout<<"\n END OF PROGRAM"<<endl;
		cout<<"GOODBYE";
		exit(0);
	}
	else
	{
		tryAgain();
	}
}
		while(answer!='n'&&answer!='y');
        
        
    return answer;
}
