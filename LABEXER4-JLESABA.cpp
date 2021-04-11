/*
* Programmer: Lesaba, John Kenneth S.
* Date Created: 6/20/2017
* Terminal No: 15
* Program: BSIT
* Course / Section: CS127-10L/BM1
Password: easy123
*/
#include<iostream>
#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
#include <iomanip>
#include <windows.h>
#include<conio.h>
#include<cstring>
using namespace std;
int i, j;
const string PASSKEY="easy123";
string EnterPassword();
void password();

void cursor( HANDLE StdOut, SHORT x, SHORT y ){
	// Set the cursor position.
	COORD Cord;
	Cord.X = x;
	Cord.Y = y;
	SetConsoleCursorPosition( StdOut, Cord );
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Products{
	string product;
	int asize;
	string brand;
	double price;
	int stock;
	int sold;
	int left;
	Products *branch;
};
int enterProduct();
void inputProduct(int val);
void productDisplay(Products *temp, int sval);

main()
{	
	int count;
	char user[10];
	cout<<"PRODUCT INVENTORY SYSTEM CS127L"<<endl<<endl;
		password();
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout<<"PRODUCT INVENTORY SYSTEM CS127L"<<endl<<endl;

	count=enterProduct();

	cout<<endl<<"ENTER "<<count<<" PRODUCTS"<<endl;

	inputProduct(count);

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void password()
{
    system("cls");
    cout<<"\nEnter Password: ";
    string pass;
    int attempts = 0;
    while (true) {
        pass = EnterPassword();
       cout<<"\nProcessing password"; 

        for (int i = 0; i < 5; i++) {
            Sleep(100); 
           cout<<"."; 
        }
       cout<<"\n";

        if (pass == PASSKEY) {
            system("cls");
            cout << "Accepted.\n";
            Sleep(100);
            system("cls");
            
            break;
        }
        else {
            system("cls"); 
            cout<<"Incorrect , please try again\n";
			cout<<"Enter Password: "; 
            attempts += 1;
        }

        if (attempts >= 3) {
            cout << "Too many failed attempts. Exiting program...\n\n";
            Sleep(1000);;
            
            exit(0);

            break; 
        }


    }

  
}
string EnterPassword(){
    const char BACKSPACE = 8; 
    const char RETURN = 13;

    string entry; 
    char key = 0;

   
    while ((key = getch()) != RETURN) {
        
        if (key == BACKSPACE) {
            if(entry.length() > 0) {
               cout<<"\b \b";
                entry.resize(entry.size()-1);
            }   
        }
        else {
            entry += key;
          cout<<"*";
        }
    }
	return entry;
}
int enterProduct(){

	int numProd;
	do{
	
	cout << "ENTER NUMBER OF PRODUCTS FOR INVENTORY: ";
	cin >> numProd;
	if(numProd>10||numProd<=0){
		cout<<"Invalid input try again\n";
		Sleep(100);
		cin.clear();
		cin.ignore(10000,'\n');
	}
	}while(numProd>10||numProd<=0);	

	return numProd;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void inputProduct(int val){
	Products *newProd;
	newProd = new Products[val];

	for (i = 0; i < val; ++i){
		cout << "Product[" << i+1 <<"]: ";
		cin >> newProd[i].product;
		do{
			cout << "How many " << newProd[i].product << "? ";
		cin >> newProd[i].asize;
		cout << endl;
			if(newProd[i].asize>10||newProd[i].asize<=0){
		cout<<"Invalid input try again\n";
		Sleep(100);
		cin.clear();
		cin.ignore(10000,'\n');
		}
		}while(newProd[i].asize<1||newProd[i].asize>5);
		

		newProd[i].branch = new Products[newProd[i].asize];
		for(j = 0; j < newProd[i].asize; ++j){
			cout << newProd[i].product << "[" << j+1 << "]: ";
			cin >> newProd[i].branch[j].brand;
			cout << "Price: ";
			cin >> newProd[i].branch[j].price;
			cout << "Stock: ";
			cin >> newProd[i].branch[j].stock;
			cout << "Sold: ";
			cin >> newProd[i].branch[j].sold;
			cout << endl;
			newProd[i].branch[j].left = newProd[i].branch[j].stock - newProd[i].branch[j].sold;
		}
	}

	cout << endl;

	productDisplay(newProd, val);
}

//////////////////////////////////
void productDisplay(Products *temp, int sval)
{
	HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
	system("cls");
	cout << "		***** INVENTORY SYSTEM CS127 4TH QTR*****\n"<<endl;
	cout << "PROD NO.   PRODUCT       NAME       PRICE    STOCK    SOLD   LEFT\n\n\n\n\n\n";
		i = 3; // initialize to 3rd row
		for(int yy = 0; yy < sval; yy++)
		{
			//PRODUCT NUMBER LOOP
			cursor(hStdout, 3, i); // product number
			cout << "[" << yy+1 << "]";
		
			cursor(hStdout, 11, i); // product
			cout << temp[yy].product;	
		
			for(int xx = 0; xx < temp[yy].asize; xx++)
			{
				//NAME TO LEFT LOOP
				cursor(hStdout, 25, i); // product name
				cout << temp[yy].branch[xx].brand;
		
				cursor(hStdout, 36, i); // product price
				cout << temp[yy].branch[xx].price;		
		
				cursor(hStdout, 46, i); // product stock
				cout << temp[yy].branch[xx].stock;	
		
				cursor(hStdout, 55, i); // product sold
				cout << temp[yy].branch[xx].sold;	
		
				cursor(hStdout, 62, i); // product left
				cout << temp[yy].branch[xx].left;
			
				i++;
			}
			i++;
		}
}

