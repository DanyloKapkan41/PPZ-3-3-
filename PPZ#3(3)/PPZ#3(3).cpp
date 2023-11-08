
#include <iostream>

using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

void add(Node*& head, int N, int j)
{
	if (N > j)
	{
		int n;
		n = rand() % 200001 - 100000;
		Node* cur = new Node(n);
		head->next = cur;
		j++;
		add(cur, N, j);	
	}

}
void show(Node* head)
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
}
void deleteList(Node* head)
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
bool checking(Node* head, int pos)
{
	bool b = 0;
	if ( head->next != NULL)
	{
		b = true;
		pos++; checking(head->next, pos);
	}else
	cout << "\npos:" << pos;
	return b;
}
int main()
{
	int N=-1;
	Node* head = new Node(1);
	srand(time(NULL));
	do {
		cout << "Count of elements (N<10001): ";
		cin >> N;
	} while (N > 10000 || N < 0);
	add(head, N, 0);
	show(head);
	if (checking(head, -1))
	{	
		cout << "\ntrue";
	}
	else cout << "\nfalse";
	deleteList(head);
	return 0;
}
