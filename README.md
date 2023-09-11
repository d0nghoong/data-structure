# doubleLinkedList
이중 연결 리스트에 대한 알고리즘

## DoubleLinkedList.h
2행: 여타 연결 리스트와 달리 llink, rlink 링크 2개를 만들어준다

## DoubleLinkedList.cpp
30행/34행: DL이 비어 있을 경우 newNode의 llink,rlink는 NULL로 설정 DL->head는 newNode로 둔다<br>
35/42행: newNode를 DL의 가장 앞에 삽입하는 경우 llink는 NULL로 rlink는 DL->head로 둔다<br>
45/50행: newNode의 llink는 pre로, rlink는 pre가 rlink로 가지던것을 갖는다<br>
48행: newNode가 DL의 끝이 아닌지 체크해주자<br>

54행,55행: DL이 존재하지 않거나 삭제 노드가 존재하지 않는 경우 체크<br>
57행~60행: old->llink와 old->rlink를 연결하고 old는 삭제<br>

## Problem
-연결리스트에서 오류 발생시 순서 확인 한번 해주자( 순서 하나 바뀜으로써 오류 가능)<br>
-문자열은 배열과 같은 것이라고 생각하자 -> 대입 혹은 비교를 위해서 = 을 사용 불가능하며 strcpy,strcmp 이용하자
