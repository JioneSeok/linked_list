#include <iostream>
#include "linked_list.h"
using namespace std;

// struct�� �̿��Ͽ� node�� �����Ѵ�.
struct node {
	int data; // ����� ��
	node* link; // ����� node�� �ּ� ���̴�. ��, ���� node�� �ּڰ�.
};
struct node* header; // header�� ù��° node�̴�.

// K��°�� ���ο� node�� �߰����ִ� �Լ��̴�.
void addKth(int value, int k) { // value�� �߰��Ϸ��� node�� ���̴�. k�� ���ο� node�� �߰��Ϸ��� ��ġ�̴�.
	// ���ο� node�� �����ϰ� ����ڰ� �Է��� value�� �߰��Ϸ��� node�� data�� �޾� �����Ѵ�.
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = value;
	newNode->link = NULL;
	
	int number = 0;
	node* current = header;

	// ����ִ� list���ٸ� ���ο� node�� header �ǵ��� �Ѵ�. ��, ù��° node.
	if (header == NULL) {
		header = newNode;
	}
	else {
		// k=1, �� ù��°�� ���ο� node�� �߰��Ϸ��� �Ѵٸ� ���ο� node�� header node�� �ǵ��� �Ѵ�.
		if (k == 1) {
			newNode->link = header;
			header = newNode;
		}
		else {
			//k-1���� ����ؼ� ����� ���� node�� �̵��Ѵ�.
			while (current != NULL) {
				number = number + 1;
				if (number == k - 1) {
					break;
				}
				current = current->link;
			}
			
			newNode->link = current->link; // ���ο� node�� k��° node�� �ּҸ� �������ش�.
			current->link = newNode; // k-1��° node�� ���� ���� node�� �ּҸ� �������ش�.
		}
	}

}

// ����ڰ� �Է��� value ���� list�� �� �տ� �����ϴ� �Լ��̴�.
void addBegin(int value) {
	// ���ο� node�� �����ϰ� ����ڰ� �Է��� value�� �߰��Ϸ��� node�� data�� �޾� �����Ѵ�.
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->link = NULL;

	// ����ִ� list���ٸ� ���ο� node�� header �ǵ��� �Ѵ�.
	if (header == NULL) {
		header = newNode;
	}

	else {
		newNode->link = header; // ���ο� node�� header�� �ּҸ� �����Ѵ�.
		header = newNode; // ���ο� node�� header�� �ǰ��Ѵ�.
	}

}

// ����ڰ� �Է��� value ���� list�� �� �ڿ� �����ϴ� �Լ��̴�.
void addEnd(int value) {
	// ���ο� node�� �����ϰ� ����ڰ� �Է��� value�� �߰��Ϸ��� node�� data�� �޾� �����Ѵ�.
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->link = NULL;

	// ����ִ� list���ٸ� ���ο� node�� header �ǵ��� �Ѵ�. ��, ù��° node.
	if (header == NULL) {
		header = newNode;
	}
	else {
		node* current = header;

		// current node�� �� ĭ�� �����̸� current node�� null�� �Ǹ� current node�� ���� node�� ���ο� node�� �ǰ��Ѵ�.
		while (current->link != NULL) {
			current = current->link;
		}
		current->link = newNode;

	}
}

// ����ڰ� ���ϴ� value ���� ������ �� �ְ� ���ִ� �Լ��̴�.
void accessNode(int value) {
	int number = 0;
	node* current = header;

	// header node���� �� ĭ�� �����̸鼭 ������� ���ϴ� value�� node�� ����Ǿ� �ִ� data ���� ��ġ�� ���� ã�´�.
	while (current != NULL) {

		// ���ϴ� value�� node�� data�� ��ġ�ϸ� �׶��� ������ ����Ѵ�.
		if (current->data == value) {
			cout << number + 1 << endl;
			number++;
		}
		current = current->link;
		number++;
	}

}

// ����ڰ� ����ڰ� ������� �ϴ� list�� k��° ���� �����Ѵ�.
void deleteKth(int k) {

	// ������� �ϴ� ���Ҹ� ã�� ���� nextNode�� current node�� �������ش�.
	int number = 0;
	node* nextNode = header->link;
	node* current = header;

	// ����ڰ� ù��° node�� ���ְ� �ʹٸ� header node�� �����Ѵ�.
	if (k == 1) {
		current->link = header;
		free(current);
	}
	else {

		// current node�� k - 1��°, newNode�� k��° node�� �ɶ����� ã�´�.
		while (current != NULL) {
			number++;
			if (number == k - 1) {
				break;
			}
			current = current->link;
			nextNode = nextNode->link;
		}
		current->link = nextNode->link; // nextNode�� ����Ǿ� �ִ� nextNode ���� node�� �ּ� ���� current node�� ���� �ּ� ������ �����Ѵ�.
		free(nextNode); // k��°�� �ִ� nextNode�� �����Ѵ�.

	}
}

// linked list�� reset�ϴ� �Լ��̴�.
void reset() {
	if (header == NULL) {
		return;
	}
	else {
		node* current;
		current = header; // header node�� current node�� �����Ѵ�.

		// current node�� ���� node�� �ּҸ� header�� �������ָ� current node�� null�� �� ������ �����Ѵ�.
		while (current != NULL) {
			header = current->link;
			free(current);
			current = header;
		}
	}
}

// linked list�� ����Ǿ� �ִ� data�� print�ϴ� �Լ��̴�.
void printList() {
	node* current = header;

	// header node���� �� ĭ�� �����̸� data�� print�Ѵ�.
	while (current != NULL) {
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}
