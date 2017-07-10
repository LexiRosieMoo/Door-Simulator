/*
DoorParse.h
A file to attempt to parse input for door simulator
May God have mercy
*/

/*
THEORY
The input can be checked for words and then
corrosponding numbers can be added
to a list in the order that they appear
and maybe something good will happen
*/

/*
	0: Nothing useful
	1: Door
	2: Hand
	3: Open
	4: Turn
*/

std::string uInput; // A string that is global to be accessed by the function easily.

class WordList
{
	struct Node
	{
		Word word;
		//int ID;
		Node *next;
	};
	
	public:
	
	WordList()
	{
		head = NULL;
	}
	
	void insert(string val)
	{
		Node *n = new Node();
		n->word = new Word(val);
		//n->ID = IDFind(val)
		n->next = head;
	}
	
	string pop()
	{
		Node *n = head;
		string ret = n->x;
		
		head = head->next;
		delete n;
		return ret;
	}
	
	private:
	
	Node *head;

}
