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
    
  ans=menu();

   switch(ans)
   {
    case 'a':
    	{
    		system("cls");
    		char test[120];
    		cout<<"Input the word: ";
    		cin.ignore();
    		 cin.getline(test,120);
    		palindrome(test);
			break;
		}
	case 'b':
		{
			system("cls");
			string str1,str2;
			int check;
			cout<<"Enter String1: ";
			 cin.ignore();
			 getline(cin,str1);
			cout<<"Enter String2: ";
			  getline(cin,str2);
		
			
			 
		
		
			
		   	cout<<"\nString1: "<<str1;
			cout<<"\nString2: "<<str2;
	
				
			str1=RemSpacePunct(str1);
			str2=RemSpacePunct(str2);
			
			check=areAnagrams(str1,str2);
			
			if(check==1)
			{
				cout<<"\nThey are anagrams!\n\n";
			}
			else
			{
				cout<<"\nThey are not anagrams!\n\n";
			}
			
			break;
		}
	case 'c':
		{
			quit();
			break;
		}
		
	default:
		{
			cout<<"Invalid Input!\n\n";
			break;
		}
   
   }

   do{
		cout<<"Do you want to try again [y/n]"<<endl
			<<"Choice: ";
		cin>>let;
		let=tolower(let);
		}while(let!='n'&&let!='y');

		if(let=='y')
		{
			system("cls");
		    main();
		}
		else
		{
			exit(0);
		}

		system("pause");
        return 0;	
}//end main
//////////////////////////////////////////////////////
void quit()
{
	char choice;
	
    cout<<"\n\nDo you want to quit now? [y/n]";
    cout<<"\nChoice: ";
     cin>>choice;
     if(choice=='y'||choice=='Y')
      exit(0);
     else if(choice=='n'||choice=='N')
      {
      	system("cls");
      	main();
	  }
	 else
	  {
	  	cout<<"\nInvalid Input!";
	  	Sleep(1000);
	  	system("cls");
		quit();
	  }
   

}

///////////////////////
/*string EnterPassword()
{
   string password;
   char temp[15];
   
   int i=0;
   cout<<"Enter Password: ";
    while(1)
    {
	temp[i]=getch();
     if(temp[i]==13)
      {
      	temp[i]='\0';
      	break;
	  }
	  if(temp[i]==8 && i>0)
	  {
	  	cout<<"\b \b";
	  	i--;
	  }
	  else
	  {
	  	cout<<"*";
	  	i++;
	  }
    }
    
    ostringstream convert;
    convert<<temp;
    password=convert.str();
   
   return password;

}*/

////////////////////////////////////////////////////
char menu()
{

	char choice;
	
	cout<<"[a] Check the Palindrome"<<endl;
	cout<<"[b] Testing if strings are Anagrams"<<endl;
	cout<<"[c] Quit";
	cout<<"\n\nYour Choice: ";
     cin>>choice;
     
	choice=tolower(choice);
	
	    return choice;


}


//////////////////////////////////
/*void password()
{
   string pass=EnterPassword();
   if(pass=="123456")
   {
   	 system("cls");
   }
   else
   {
   	 Try.count++;
   	 cout<<"\n\nIncorrect Password! Please try again!";
   	  if(Try.count==3)
   	   {
   	   	 cout<<"\n\nYou have reached the maximum attempt for password!";
   	   	  exit(0);
		  }
   	 Sleep(1500);
   	  system("cls");
   	 password();
   }
}*/

////////////////////////////////////////////////////////////////
string sort(string str)
{
	
	string temp;
	
	for(int i=0;i<str.length();i++)
	{
		str[i]=tolower(str[i]);
	}
	
	for(int i=1;i<str.length();i++)
	{
		for(int j=1;j<str.length();j++)
		{
			if(str[j]<str[j-1])
			{
			  temp[0]=str[j];
			  str[j]=str[j-1];
			  str[j-1]=temp[0];
			}
		}
	}
	

    return str;
}
//////////////////////////////
bool areAnagrams(string str1,string str2)
{
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
	char temp[120];
	strcpy(temp,sal);
	strrev(temp);
	cout<<"In reverse order: "<<temp;
    if(!strcmpi(temp,sal))
    {
    	cout<<"\nThe word is palindrome!"<<endl<<endl;
	}
	else
	{
		cout<<"\nTHe word is not palindrome!"<<endl<<endl;
	}
	
	
	
	
}
