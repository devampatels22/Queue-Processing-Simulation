//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds items for a queue 
//-----------------------------------------
class ListItem;

class Node {
private:
	ListItem *item;
	Node *next;
public:
	Node();
	Node(ListItem *i, Node *n);
	Node *getNext();
	void setNext(Node *next);
	ListItem *getItem();
	//void setItem(ListItem *i);
}; // class Node
