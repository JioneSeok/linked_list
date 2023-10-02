#include <iostream>
#include "linked_list.h"
using namespace std;

// struct를 이용하여 node를 생성한다.
struct node {
	int data; // 노드의 값
	node* link; // 연결된 node의 주소 값이다. 즉, 다음 node의 주솟값.
};
struct node* header; // header는 첫번째 node이다.

// K번째에 새로운 node를 추가해주는 함수이다.
void addKth(int value, int k) { // value는 추가하려는 node의 값이다. k는 새로운 node를 추가하려는 위치이다.
	// 새로운 node를 생성하고 사용자가 입력한 value를 추가하려는 node의 data로 받아 저장한다.
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = value;
	newNode->link = NULL;
	
	int number = 0;
	node* current = header;

	// 비어있는 list였다면 새로운 node가 header 되도록 한다. 즉, 첫번째 node.
	if (header == NULL) {
		header = newNode;
	}
	else {
		// k=1, 즉 첫번째에 새로운 node를 추가하려고 한다면 새로운 node를 header node가 되도록 한다.
		if (k == 1) {
			newNode->link = header;
			header = newNode;
		}
		else {
			//k-1까지 계속해서 연결된 다음 node로 이동한다.
			while (current != NULL) {
				number = number + 1;
				if (number == k - 1) {
					break;
				}
				current = current->link;
			}
			
			newNode->link = current->link; // 새로운 node에 k번째 node의 주소를 저장해준다.
			current->link = newNode; // k-1번째 node에 새로 만든 node의 주소를 저장해준다.
		}
	}

}

// 사용자가 입력한 value 값을 list의 맨 앞에 저장하는 함수이다.
void addBegin(int value) {
	// 새로운 node를 생성하고 사용자가 입력한 value를 추가하려는 node의 data로 받아 저장한다.
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->link = NULL;

	// 비어있는 list였다면 새로운 node가 header 되도록 한다.
	if (header == NULL) {
		header = newNode;
	}

	else {
		newNode->link = header; // 새로운 node에 header의 주소를 저장한다.
		header = newNode; // 새로운 node가 header가 되게한다.
	}

}

// 사용자가 입력한 value 값을 list의 맨 뒤에 저장하는 함수이다.
void addEnd(int value) {
	// 새로운 node를 생성하고 사용자가 입력한 value를 추가하려는 node의 data로 받아 저장한다.
	node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->link = NULL;

	// 비어있는 list였다면 새로운 node가 header 되도록 한다. 즉, 첫번째 node.
	if (header == NULL) {
		header = newNode;
	}
	else {
		node* current = header;

		// current node를 한 칸씩 움직이며 current node가 null이 되면 current node의 다음 node가 새로운 node가 되게한다.
		while (current->link != NULL) {
			current = current->link;
		}
		current->link = newNode;

	}
}

// 사용자가 원하는 value 값에 접근할 수 있게 해주는 함수이다.
void accessNode(int value) {
	int number = 0;
	node* current = header;

	// header node부터 한 칸씩 움직이면서 사용하자 원하는 value와 node에 저장되어 있는 data 값이 일치할 때를 찾는다.
	while (current != NULL) {

		// 원하는 value와 node의 data가 일치하면 그때의 순서를 출력한다.
		if (current->data == value) {
			cout << number + 1 << endl;
			number++;
		}
		current = current->link;
		number++;
	}

}

// 사용자가 사용자가 지우고자 하는 list의 k번째 값을 제거한다.
void deleteKth(int k) {

	// 지우고자 하는 원소를 찾기 위해 nextNode와 current node를 정의해준다.
	int number = 0;
	node* nextNode = header->link;
	node* current = header;

	// 사용자가 첫번째 node를 없애고 싶다면 header node를 삭제한다.
	if (k == 1) {
		current->link = header;
		free(current);
	}
	else {

		// current node가 k - 1번째, newNode가 k번째 node가 될때까지 찾는다.
		while (current != NULL) {
			number++;
			if (number == k - 1) {
				break;
			}
			current = current->link;
			nextNode = nextNode->link;
		}
		current->link = nextNode->link; // nextNode에 저장되어 있는 nextNode 다음 node의 주소 값을 current node의 다음 주소 값으로 저장한다.
		free(nextNode); // k번째에 있는 nextNode를 삭제한다.

	}
}

// linked list를 reset하는 함수이다.
void reset() {
	if (header == NULL) {
		return;
	}
	else {
		node* current;
		current = header; // header node를 current node로 정의한다.

		// current node의 다음 node의 주소를 header로 지정해주면 current node가 null이 될 때까지 제거한다.
		while (current != NULL) {
			header = current->link;
			free(current);
			current = header;
		}
	}
}

// linked list에 저장되어 있는 data를 print하는 함수이다.
void printList() {
	node* current = header;

	// header node부터 한 칸씩 움직이며 data를 print한다.
	while (current != NULL) {
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}
