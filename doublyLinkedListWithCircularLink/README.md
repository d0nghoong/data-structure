# doublyLinkedListWithCircularLink
자료구조 과제 문제로 이중 순환 연결 리스트에 관한 코드이다
## problem
함수에서 오류가 발생했을 시 고려 못한 상황이 있는지 체크하자<br>
처음에 insert 함수에서 첫 노드로 insert가 될시 h->head 값에 다가 삽입한 노드를 넣어야 하는 것을 놓침<br>
ㄴ과정 마다 printf 함수를 사용함으로써 문제가 생기는 부분을 파악하고 해당 부분에 집중하여 찾음

linked list insert 함수에서 순서 진짜 중요하다, insert에 오류 있을 시 순서에 문제가 있을 수 있다고 항상 명심하자<br>
insert 함수에서 	newNode->next = temp->next; temp->next = newNode; 순서를 바꾸어 적어 오류 생김<br>
ㄴ 과정 마다 printf 함수를 사용함으로써 문제가 생기는 부분을 파악하고 해당 부분에 집중하여 찾음
구조체는 bool 형식으로 판단 불가능하다.

## 소스.cpp
43행: newNode가 리스트의 첫번째 노드로 매치되는 경우 - h->head 할당을 위해 구분 <br>
81행: temp와 리스트의 첫 노드 값이 같은 경우 리스트에 항이 1개 있는 경우와 그렇지 않은 경우를 구분하여 h->head에 값을 넣어준다

