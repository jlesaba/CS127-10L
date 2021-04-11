#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
//global
int i;//index
const int size = 10;

//struct definition
struct dateUse{
	int month;
	int day;
	int year;
};
struct PCRec{
	string ModelNumber;
	string PCType;
	string PCBrand;
	dateUse DateRequest;
	int PCQty;
	int PCSold;
	double PCCost;
	double PCCValueLeft;
};
//function
void  PCEnter(PCRec xpc[]);
void PCLeft(PCRec leftVal[]);
int main(){
	PCRec pc[size];
	cout << "Input " << size << " PC Records" << endl;
	//input
	PCEnter(pc);
	//process
	PCLeft(pc);
	//output
	cout << "ModelNumber" << setw(5) << "PCType" << setw(5) << "DateRequest" << setw(5) << "PCQty" << setw(5) << "PCSold" << setw(5) << "PCCost" << setw(5) << "PCCValueLeft" << endl;
	for(i=0;i<size;i++){
		cout << fixed << setprecision(2);
		cout << pc[i].ModelNumber << setw(5) << pc[i].PCType << setw(5) << pc[i].DateRequest.month << "-" << pc[i].DateRequest.day << "-" << pc[i].DateRequest.year << setw(5) << pc[i].PCQty << setw(5) << pc[i].PCSold << setw(5) << pc[i].PCCost
			<< setw(5) << pc[i].PCCValueLeft;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void  PCEnter(PCRec xPc[]){
	for(i=0;i<size;i++){
		cout << "PC " << i+1 << endl;
		cout << "Model Number: ";
		getline(cin,xPc[i].ModelNumber);
		cout << "\nPC Type: ";
		getline(cin,xPc[i].PCType);
		cout << "\nPC Brand: ";
		getline(cin,xPc[i].PCBrand);
		cout << "\nDate Request" << endl;
		cout << setw(5) << "Month: ";
		cin >> xPc[i].DateRequest.month;
		cout << endl << setw(5) << "Day: ";
		cin >> xPc[i].DateRequest.day;
		cout << endl << setw(5) << "Year: ";
		cin >> xPc[i].DateRequest.year;
		cout << "\nPC Quantity: ";
		cin >> xPc[i].PCQty;
		cout << "\nPC Sold: ";
		cin >> xPc[i].PCSold;
		cout << "\nPC Cost (in Php): ";
		cin >> xPc[i].PCCost;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void PCLeft(PCRec leftVal[]){
	for(i=0;i<size;i++){
		leftVal[i].PCCValueLeft = leftVal[i].PCCost * (leftVal[i].PCQty - leftVal[i].PCSold);
	}
}
