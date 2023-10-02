#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {
	// list의 앞에 원소 추가
	// list의 맨 뒤에 원소 추가
	// K번째에 원소 추가
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	printList(); // 1 2 8 9 출력


	// list의 node에 접근
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	accessNode(8); // 3 출력. 8이 3번째에 있기 때문이다.


	// K번째 원소 제거
	reset();
	addBegin(2); // 2
	addBegin(1); // 1 2
	addEnd(9); // 1 2 9
	addKth(8, 3); // 1 2 8 9
	addKth(7, 3); // 1 2 7 8 9
	deleteKth(2); // 1 7 8 9
	deleteKth(3); // 1 7 9
	deleteKth(2); // 1 9
	printList(); // 1 9 출력
	
}