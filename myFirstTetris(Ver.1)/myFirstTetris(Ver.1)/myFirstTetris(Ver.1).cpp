// myFirstTetris(Ver.1).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "TetrisSystem.h"

using namespace std;
// Pos.X = Column way
// Pos.Y = Raw way
//Cursor location = actual output comes


blockTypeNColor chosenBlock;

int main() {
	setConsoleSystemSetting();

	printOutGameTitle();

REPEAT : 

	StackedBlockState* STATE = new StackedBlockState();
	int SCORE = 0;
	int LINE = 0;
	int nowBlock = 0;
	int nextBlock = 0;
	STATE->updateCollisionBoundary();
	while (!GetAsyncKeyState(VK_SPACE));
	printOutGameTemplate();

	while (1) {
		nowBlock = nextBlock;
		nextBlock = whichBlockType();
		chosenBlock = tetrisBlockTypeNColor[nowBlock];
		printOutBlockShow(tetrisBlockTypeNColor[nextBlock].blockType, 
			tetrisBlockTypeNColor[nextBlock].color);
		TetrisBlock* tetrisBlock = new TetrisBlock(TETRISBLOCKGENERATEPOINT_X, 
			TETRISBLOCKGENERATEPOINT_Y, chosenBlock.blockType);
		tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

		while (!(tetrisBlock->getTetrisBlockNowState(0).whetherStacked)) {

			tetrisBlock->tetrisBlockDefaultFall(STATE->collisionBoundary);
			tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

			tetrisBlock->tetrisBlockRotate(STATE->collisionBoundary);
			tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

			tetrisBlock->tetrisBlockPlayerControllLeft(STATE->collisionBoundary);
			tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

			tetrisBlock->tetrisBlockPlayerControllRight(STATE->collisionBoundary);
			tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

			tetrisBlock->tetrisBlockPlayerControllDown(STATE->collisionBoundary);
			tetrisBlock->tetrisBlockPrintOut(chosenBlock.color);

			if (tetrisBlock->getTetrisBlockNowState(0).whetherStacked == true) {
				Sleep(100);
			}
			else {
				Sleep(500);
			}
		}
		STATE->updateStackedTetrisBlock(tetrisBlock);
		LINE += STATE->updateStackedBlockLine();
		STATE->updateCollisionBoundary();
		delete tetrisBlock;
		STATE->printOutFinalChangedState();
		if (STATE->checkWhetherGameOver()) {
			delete STATE;
			break;
		}
	}

	printOutGameOver();

	while (1) {
		if (GetAsyncKeyState(VK_SPACE)) {
			goto REPEAT;
		}
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
	}

	gotoXY(0, 30);
	return 0;
	
	
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
