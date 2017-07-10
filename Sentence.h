//Sentence.h
//A header file to separate the contents of a string into words using a linked list

std::string uInput; // A string that is global to be accessed by the functions easily.

class WordList
{
	struct Node
	{
		string word;
		int ID;
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
		n->word = val;
		n->ID = IDFind(val)
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