#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {
	// list�� �տ� ���� �߰�
	// list�� �� �ڿ� ���� �߰�
	// K��°�� ���� �߰�
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	printList(); // 1 2 8 9 ���


	// list�� node�� ����
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	accessNode(8); // 3 ���. 8�� 3��°�� �ֱ� �����̴�.


	// K��° ���� ����
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	addKth(7, 3); // 1 2 7 8 9
	deleteKth(2); // 1 7 8 9
	deleteKth(3); // 1 7 9
	deleteKth(2); // 1 9
	printList(); // 1 9 ���
	
}