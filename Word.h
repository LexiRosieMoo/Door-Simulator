/*
Contains the Word class

*/

class Word
{
	public:
	string content;
	meaning = 0;
	
	Word(string text)
	{
		content = text;
		meaning = check();
	}
	
	int check()
	{
		return 0;
	}

};