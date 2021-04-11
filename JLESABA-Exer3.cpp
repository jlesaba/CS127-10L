/*
* Programmer: LESABA, John Kenneth S.
* Date Created: 6/1/2017
* Terminal No: 15
* Program: BSIT
* Course / Section: CS127-10L/BM1
*/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#include<conio.h>
#include<windows.h>
string sort(string str);//reaaranging the orders of string to test if its anagram
bool areAnagrams(string str1,string str2);//process the strgin if anagram anf returns the value 1 or 0
string RemSpacePunct(string str);//function that removes space and punctation in aa string
////////////////////////////////
void palindrome(char sal[120]);//testing whether the c-string value is palindrome or not
//void password();//asking the user to enter the password
char menu();//displaying choices a,b, and c then returns the answer
void quit();//asking the user if he/she wants to quit
//string EnterPassword();//processing if the password is correct and diplaying it with "*" sign

int main()
{
	char let,ans;
    
   //add code here
	ans = menu();
   switch(ans)
   {

//add code here
		case 'a':
			char word[120];
			cout << "[a] Check Palindrome" << endl
				<< "Input the word: ";
				cin.ignore();
			cin.getline(word,120);
			palindrome(word);
			break;
		case 'b':
			string str1,str2;
			int test;
			cout << "[b] Testing if strings are Anagrams" << endl
				<< "Test whether the following strings are anagrams:" << endl
				<< "Enter string1: ";
				cin.ignore();
				getline(cin,str1);
				cout << "\nEnter string2:";
				getline(cin,str2);
				
				cout<<"\nString1: "<<str1;
				cout<<"\nString2: "<<str2;
	
				
				str1=RemSpacePunct(str1);
				str2=RemSpacePunct(str2);
			
				test=areAnagrams(str1,str2);
			
				if(test==1)
					cout<<"\nThey are anagrams!\n\n";
				else
					cout<<"\nThey are not anagrams!\n\n";
			break;
		//case 'c':
			
		//	break;



   }

   do{
		cout<<"Do you want to try again [y/n]"<<endl
			<<"Choice: ";
		cin>>let;
		let=tolower(let);
		}while(let!='n'&&let!='y');

		//add code here

		system("pause");
        return 0;	
}//end main
//////////////////////////////////////////////////////
void quit()
{
	//add code here


}

///////////////////////
/*string EnterPassword()
{
   //add code here
   

   return password;

}*/

////////////////////////////////////////////////////
char menu()
{

	//add code here
	char choice;
	cout << "[a] Check Palindrome" << endl
		<< "[b] Testing if strings are Anagrams" << endl
		<< "[c] Quit" << endl
		<< "Your choice: ";
	cin >> choice;
	choice = tolower(choice);
	    //return choice;
		return choice;

}


//////////////////////////////////
/*void password()
{
//add code here
}*/

////////////////////////////////////////////////////////////////
string sort(string str)
{
	//add code here
    
}
//////////////////////////////
bool areAnagrams(string str1,string str2)
{
	//add code here
	str1=sort(str1);
    str2=sort(str2);
    
    if(str1.length()==str2.length())
    {
	
    for(int i=0;i<str1.length();i++)
    {
    	if(str1[i]==str2[i])
    	 continue;
    	else if(str1[i]!=str2[i])
    	 {
    	 	return 0;
    	 	break;
		 }
	}
	  return 1;
   }
   return -1;
}
//////////////////////////////
string RemSpacePunct(string str)
{
	//add code here
	for(int i=0;i<str.length();i++)
	{
		if(!isalpha(str[i]))
		  {
		  	str.erase(i,1);
		  }
	}
   return str;
}
///////////////////////////////
void palindrome(char sal[120])
{
	//add code here
	char test[120];
	strcpy(test,sal);
	cout << "in reverse order: " << strrev(sal) << endl;
	if(strcmpi(test,sal)==0)
		cout << "The word is palindrome!\n";
	else
		cout << "The word is not palindrome\n";
}

