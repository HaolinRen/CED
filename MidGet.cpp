#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXLEN 5
typedef int typeElem;

typedef struct Node {
	typeElem data;
	struct Node* next;
};

typedef struct Node* LinkedList;

void Yose(int num) {
	Node list[MAXLEN];
	for (int i = 1; i < MAXLEN; i++) {
		list[i].data = i + 1;
		list[i-1].next = &list[i];
	}
	list[0].data = 1;
	list[MAXLEN -1].next = list;
	LinkedList p = list[MAXLEN-3].next;
	LinkedList tempNode = list[MAXLEN-2].next;
	int turn = 0;
	while (1) {
		++turn;
		p = tempNode;
		tempNode = tempNode->next;
		if (turn % num == 0) {
			p->next = tempNode->next;
		}
		if (tempNode == p)
		{
			cout << "ok: " << p->data << endl;
			break;
		}
	}
}

int main() {
	
	Yose(3);
	return 0;
}
