//Minor functions for Door Simulator+ Project

string userinput;

//Prompts the user for a keypress
void keyp()
{
	cout<<">>";
	getch();
	cout<<endl;
}

//Prints out a string, character by character
void stringout(string text)
{ 
	for(int d = 0; d < text.length(); d++)
	{
		if (text[d] != '1')
		{
				cout<<text[d];
				delay(50);
		}
		else
		{
			delay(100);
		}    
	}
}

//Prompts the users for an input
string prompt()
{
	string uinput = "";
	string finalinput = "";
	cout<<">";
	getline(cin, uinput);

	for (int x = 0; x<uinput.length(); x++)
	{
		if (x == 4)
		{
			if (uinput.substr(0, 4) == "load")
			{
				finalinput += uinput[x];
			}
			else
			{
				finalinput += tolower(uinput[x]);
			}
		}
		else
		{
			finalinput += tolower(uinput[x]);
		}
	}
	uinput = finalinput;
	cout<<endl;
	return uinput;
			


}

//Returns if a word is found in the input
bool wordcheckb(string check)
{
	if ((userinput.find(check) <1000) || (userinput.find(check) <1000))
	{
		return true;
	}
}



//Returns the position of a word in the input
int wordcheckp(string check)
{
	if (wordcheckb(check))
	{
		return userinput.find(check);
	}
	else
	{
		cout<<"this should not happen"<<endl;
		return 0;
	}
}

//Returns true if word a is before word b
bool wordorder(string a, string b)
{
	if (wordcheckb(a) && wordcheckb(b))
	{
		if (wordcheckp(a) < wordcheckp(b))
		{
			return true;
		}
		else 
		return false;
	}
	else
	return false;
}



