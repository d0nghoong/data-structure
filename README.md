# myPlaylist
선택한 곡을 반복 재생 가능하도록 하는 플레이리스트 작성

## problem
scanf에서 변수가 값을 받지 못함 -> 문자를 받는 scanf가 반복 될때 getchar 함수를 scanf 앞에 써주어야한다

## mtPlaylist.cpp
<65~68행> 입력한 문자를 플레이리스트에서 찾는다<br>
<70행> 입력한 문자를 반복 재생 리스트에 넣는다 

## main.cpp
<20행> 노래 추가하기를 선택한 경우 플레이리스트에 넣을 노래 제목을 받는다<br>
<23행> 노래 제목을 플레이리스트에 저장한다<br>
<27행> 반복 재생을 시킬 노래 제목을 받는다 <br>
<30행> 노래 제목을 반복 재생 리스트에 저장한다<br>
<33행> 3을 누르면 무한 반복문을 종료한다<br>
<35행> 1,2,3 말고 다른 것을 입력한 경우
