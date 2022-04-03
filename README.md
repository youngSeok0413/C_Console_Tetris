# C_Console_Tetris

## C/C++를 이용하여 만든 콘솔 테트리스 게임입니다.
3개의 클래스와 화면을 그리고, 설정하는 함수들로 구성되어 있습니다.

## 알고리즘

1. 게임이 시작되면 게임 상황을 저장하는 인스턴스를 생성합니다.
2. 4개의 Block type의 인스턴스를 생성하는 TetrisBlock type의 인스턴스를 생성하고 충돌상태를 갱신합니다.
3. Tetris Block의 위치가 확정되기 전까지(낙하가 불가능하기 전까지)는 상황을 저장하지 않고 게임 화면상에 출력합니다.
4. 블록의 위치가 확정되면 확정된 위치를 게임 상황을 업데이트 합니다.
5. 라인이 지워진지 여부, 게임 오버의 여부를 판단한 뒤 생성한 블록 인스턴스를 지웁니다.
6. 게임이 오버되지 않았다면 다시 2번 단계로 돌아갑니다.
7. 만약 게임이 오버 되었다면 게임 상황을 저장하고 있던 인스턴스를 지우고, 게임 오버 화면을 출력합니다.  

## 클래스에 대한 설명:

Block : 클래스 블록은 테트리스 구성 블록의 위치를 저장하고 각종 상호작용에 대해서 정의하고 있습니다. 블록의 낙하, 사용자의 조작에 따른 위치변화, 상하좌우 충돌에 # 대한 판단, 블록의 위치가 완전히 정해졌는 지의 여부 확인을 담당하고 있습니다. 메서드는 다음과 같습니다.

1. void blockDefaultFall(void) : 블록의 기본적인 낙하
2. void blockPlayerControllLeft(bool left) : 사용자의 키조작에 따라서 왼쪽으로 움직임
3. void blockPlayerControllRight(bool right) : 사용자의 키조작에 따라서 오른쪽으로 움직임
4. void blockPlayerControllDown(bool down) : 사용자의 키조작에 따라서 아래쪽으로 움직임
5. void blockCollisionCheck(std::list<dotPos>& stackedBlock) : 블록의 좌, 우, 아래방향으로의 충돌 확인(받는 것은 차후 StackedBlock State에서 반환된 경계 블록이다)
6. bool blockRightCollisionCheck(std::list<dotPos>& stackedBlock) : 블록의 오른쪽 충돌 확인(받는 것은 차후 StackedBlock State에서 반환된 경계 블록이다)
7. bool blockLeftCollisionCheck(std::list<dotPos>& stackedBlock) : 블록의 왼쪽 충돌 확인(받는 것은 차후 StackedBlock State에서 반환된 경계 블록이다)
8. bool blockDownCollisionCheck(std::list<dotPos>& stackedBlock) : 블록의 아랫쪽 충돌 확인 및 현재 블록 상태의 확정(추락하지 못하는 블록은 더이상 위치가 변하지 않음)
9. dotPos getBlockNowState() : 위치가 변한 블록의 위치 반환
10. dotPos getBlockPrevState() : 변화 전 블록의 위치 반환
11. ableToMove getNowMovableState() : 블록의 이동 가능한 상태 반환
12. void updateNowMovableStateLeft(bool) : 블록의 이동가능 상태 임의조작(왼쪽 방향)
13. void updateNowMovableStateRight(bool) : 블록의 이동가능 상태 임의조작(오른쪽 방향)
14. void updateNowMovableStateDown(bool) : 블록의 이동가능 상태 임의조작(아래 방향)
15. void updateWhetherStacked(bool) : 블록의 위치 확정 여부 확인
16. void updateBlockPos(int x, int y) : 블록의 위치 조정
17. void updateBlockPrevPos(int x, int y) : 블록의 전 위치 조정

TetrisBlock : Block 타입의 인스턴스 4개를 생성함으로써 7개 종류의 테트리스 블록의 생성, 사용자 조작,낙하 및 회전, 상하좌우 충돌에 대한 판단, 블록의 위치 저장, 게임 화면 상으로의 블록 출력에 관여합니다.
메서드는 다음과 같습니다.

1. void tetrisBlockPrintOut(int blockColor) : 게임 화면상 테트리스 블록 출력
2. void tetrisBlockDefaultFall(std::list<dotPos>& stackedBlock) : 테트리스 블록의 낙하
3. void tetrisBlockRotate(std::list<dotPos>& stackedBlock) : 조작에 따른 테트리스 블록의 회전
4. void tetrisBlockPlayerControllLeft(std::list<dotPos>& stackedBlock) : 사용자의 조작에 따른 테트리스 블록 이동가능 여부 판단 및 이동(왼쪽)
5. void tetrisBlockPlayerControllRight(std::list<dotPos>& stackedBlock) : 사용자의 조작에 따른 테트리스 블록 이동가능 여부 판단 및  이동(오른쪽)
6. void tetrisBlockPlayerControllDown(std::list<dotPos>& stackedBlock) : 사용자의 조작에 따른 테트리스 블록 이동가능 여부 판단 및  이동(아래쪽)
7. void tetrisBlockCollisionLeftCheck(std::list<dotPos>& stackedBlock) : 테트리스 블록의 충돌(왼쪽)의 감지
8. void tetrisBlockCollisionRightCheck(std::list<dotPos>& stackedBlock) : 테트리스 블록의 충돌(오른쪽)의 감지
9. void tetrisBlockCollisionDownCheck(std::list<dotPos>& stackedBlock) : 테트리스 블록의 충돌(낙하)의 감지
10. int getTetrisBlockType() : 테트리스 블록의 종류 결정
11. dotPos getTetrisBlockNowState(int) : 이동 후 테트리스 블록의 위치 반환
12. dotPos getTetrisBlockPrevState(int) : 이동 전 테트리스 블록의 위치 반환
    
StackedBlockState : 게임의 상황을 저장과 업데이트를 담당하고, Block 클래스와 TetrisBlock 클래스에 충돌경계에 대한 list를 반환하는 역할을 합니다. 메서드는 다음과 같습니다.
    
1. void updateStackedBlock(dotPos* updatedData) : 구성 블록의 위치가 확정된 후, 현재 게임 상황에 반영
2. void updateStackedTetrisBlock(TetrisBlock* tetrisBlock) : 테트리스 블록의 위치가 설정된 후, 현재 게임 상황에 반영
3. void updateCollisionBoundary() : 충돌 경계 업데이트
4. void printOutFinalChangedState() : 게임 현재 상황을 화면상 출력
5. int updateStackedBlockLine() : 지워진 줄의 개수 반환 및 변화된 현재 상황 반영
6. bool checkWhetherGameOver() : 게임 오버 여부 판단
    
## 그 외의 함수들 : 

1. COORD getXY() : 커서의 현재 위치 반환
2. void gotoXY(int x, int y) : 커서의 위치 변경
3. void changeCursorColor(int color) : 커서의 색 변경
4. void setConsoleSystemSetting() : 콘솔 시스템의 설정
5. void makeCursorInvisible() : 커서를 보이지 않게 함
6. void printOutBlockShow(int blockType, int color) : 다음에 떨어질 블록을 미리보기에 
7. void printOutBlock(int x, int y, int color) : 기본 블록 하나를 화면상 출력
8. void printOutBlank(int x, int y) : 공란을 화면상 출력
9. void printOutGameTitle() : 게임의 첫 메인 화면 출력
10. void printOutGameTemplate() : 게임 기본 화면 출력
11. void printOutGameOver() : 게임 오버 화면 출력
12. void printOutScore(int SCORE, int line) : 게임 점수 화면 출력
13. int updateScore(int SCORE, int line) : 게임 점수의 업데이트 및 반환
14. int dropSpeedControll(int score) : 블록의 낙하 속도 조절
15. int whichBlockType() : 나올 블록의 종류를 랜덤하게 결정
    
PS . 콘솔에 대한 기본적인 정보를 제외하고, 아무 자료도 참고하지 않고 처음으로 짜본 프로그램이네요...그만큼 코드가 많이 스파게티입니다.ㅠㅠ 프로그램 자체도 많이 무겁다고 
느껴지네요. 궁금하신 점이 있으면 댓글로 남겨주세요. 피드백 또한 당연히 환영합니다 !!


