#include "TetrisSystem.h"

using namespace std;

// Pos.X = Column way
// Pos.Y = Raw way
void printOutBlockShow(int blockType, int color) {
	for (int i = 12; i < 17; i++) {
		for (int j = 1; j < 6; j++) {
			printOutBlank(i, j);
		}
	}

	for (int i = 0; i < 4; i++) {
		printOutBlock(BLOCKSHOW_X+BLOCKTYPE[blockType][0][i].posX, 
			BLOCKSHOW_Y + BLOCKTYPE[blockType][0][i].posY, color);
	}
}

void printOutBlock(int x, int y, int color) {
	changeCursorColor(color);
	gotoXY(x, y);
	printf("%c", BLOCK);
	changeCursorColor(GRAY);
}

void printOutBlank(int x, int y) {
	gotoXY(x, y);
	printf("%c", BLANK);
}

void gotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void changeCursorColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void setConsoleSystemSetting() {
	system("mode con cols=100 lines=100");
	makeCursorInvisible();
}

void makeCursorInvisible() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

COORD getXY() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO screen;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&screen);
	Cur.X = screen.dwCursorPosition.X;
	Cur.Y = screen.dwCursorPosition.Y;
	return Cur;
}

void printOutGameTitle() {
	gotoXY(0, 0);

	changeCursorColor(GRAY);

	for (int i = 0; i < GAMESCREEN_Y; i++) {
		for (int j = 0; j < GAMESCREEN_X; j++) {
			printf("%c", TITLEPAGE[i][j]);
		}
		printf("\n");
	}
}

void printOutGameTemplate() {
	gotoXY(0, 0);

	changeCursorColor(GRAY);

	for (int i = 0; i < GAMESCREEN_Y; i++) {
		for (int j = 0; j < GAMESCREEN_X+1; j++) {
			printf("%c", GAMETEMPLATE[i][j]);
		}
		printf("\n");
	}
}

void printOutGameOver() {
	gotoXY(0, 0);

	changeCursorColor(GRAY);

	for (int i = 0; i < GAMESCREEN_Y; i++) {
		for (int j = 0; j < GAMESCREEN_X+1; j++) {
			printf("%c", GAMEOVER[i][j]);
		}
		printf("\n");
	}
}

void printOutScore(int SCORE, int line) {
	gotoXY(GAMESCREEN_X + 3, GAMESCREEN_Y - 1);
	printf("TOTAL SCORE : %d", updateScore(SCORE, line));
}

int updateScore(int SCORE, int line) {
	int score = 0;
	for (int i = 1; i < line + 1; line++)
		score = 2 * i;
	score *= 10;
	return SCORE+score;
}

int dropSpeedControll(int score) {
	return (500 - score % 10) < 200 ? 200 : (500 - score % 10);
}

int whichBlockType() {
	srand((unsigned int)time(NULL));
	int blockType = rand() % 7;
	return blockType;
}



//Class : TetrisBlock : Method
void TetrisBlock::tetrisBlockRotate(std::list<dotPos>& stackedBlock) {
	dotPos buffer[4];
	bool ableToRotate = true;
	bool rotate = GetAsyncKeyState(VK_SPACE);
	if (rotate) {
		for (int i = 0; i < 4; i++) {
			buffer[i] = componentBlock[i].getBlockNowState();
			buffer[i].posX = buffer[i].posX - BLOCKTYPE[tetrisBlockType][tetrisBlockRotationNum][i].posX
				+ BLOCKTYPE[tetrisBlockType][(tetrisBlockRotationNum + 1) % 4][i].posX;
			buffer[i].posY = buffer[i].posY - BLOCKTYPE[tetrisBlockType][tetrisBlockRotationNum][i].posY
				+ BLOCKTYPE[tetrisBlockType][(tetrisBlockRotationNum + 1) % 4][i].posY;
		}

		for (list<dotPos>::iterator iter = stackedBlock.begin(); iter != stackedBlock.end(); iter++) {
			for (int i = 0; i < 4; i++) {
				if (buffer[i].posX == iter->posX) {
					if (buffer[i].posY == iter->posY) {
						ableToRotate = false;
						break;
					}
				}
				if (ableToRotate == false)
					break;
				ableToRotate = true;
			}
		}
	}
	if (rotate && ableToRotate) {
		tetrisBlockRotationNum = (tetrisBlockRotationNum + 1) % 4;
		for (int i = 0; i < 4; i++) {
			componentBlock[i].updateBlockPrevPos(componentBlock[i].getBlockNowState().posX,
				componentBlock[i].getBlockNowState().posY);
			componentBlock[i].updateBlockPos(buffer[i].posX, buffer[i].posY);
		}
	}
}

void TetrisBlock::tetrisBlockPrintOut(int blockColor) {
	for (int i = 0; i < 4; i++) {
		printOutBlank(getTetrisBlockPrevState(i).posX, getTetrisBlockPrevState(i).posY);
	}
	for (int i = 0; i < 4; i++) {
		printOutBlock(getTetrisBlockNowState(i).posX, getTetrisBlockNowState(i).posY, blockColor);
	}
}

void TetrisBlock::tetrisBlockDefaultFall(std::list<dotPos>& stackedBlock) {
	tetrisBlockCollisionDownCheck(stackedBlock);
	for (int i = 0; i < 4; i++) {
		componentBlock[i].blockDefaultFall();
	}
}

void TetrisBlock::tetrisBlockPlayerControllLeft(std::list<dotPos>& stackedBlock) {
	tetrisBlockCollisionDownCheck(stackedBlock);
	if (tetrisBlockNowMovableState.ableToFall == true)
		tetrisBlockCollisionLeftCheck(stackedBlock);
	bool whetherLeft = GetAsyncKeyState(VK_LEFT);
	for (int i = 0; i < 4; i++)
		componentBlock[i].blockPlayerControllLeft(whetherLeft);
}

void TetrisBlock::tetrisBlockPlayerControllRight(std::list<dotPos>& stackedBlock) {
	tetrisBlockCollisionDownCheck(stackedBlock);
	if (tetrisBlockNowMovableState.ableToFall == true)
		tetrisBlockCollisionRightCheck(stackedBlock);
	bool whetherRight = GetAsyncKeyState(VK_RIGHT);
	for (int i = 0; i < 4; i++)
		componentBlock[i].blockPlayerControllRight(whetherRight);
}

void TetrisBlock::tetrisBlockPlayerControllDown(std::list<dotPos>& stackedBlock) {
	tetrisBlockCollisionDownCheck(stackedBlock);
	bool whetherDown = GetAsyncKeyState(VK_DOWN);
	for (int i = 0; i < 4; i++)
		componentBlock[i].blockPlayerControllDown(whetherDown);
}

void TetrisBlock::tetrisBlockCollisionLeftCheck(std::list<dotPos>& stackedBlock) {
	for (int i = 0; i < 4; i++) {
		bool buffer = componentBlock[i].blockLeftCollisionCheck(stackedBlock);
		componentBlock[i].updateNowMovableStateLeft(buffer);
	}

	for (int i = 0; i < 4; i++) {
		if (componentBlock[i].getNowMovableState().ableToMoveLeft == false) {
			tetrisBlockNowMovableState.ableToMoveLeft = false;
			break;
		}
		tetrisBlockNowMovableState.ableToMoveLeft = true;
	}

	for (int i = 0; i < 4; i++) {
		componentBlock[i].updateNowMovableStateLeft(tetrisBlockNowMovableState.ableToMoveLeft);
	}
}

void TetrisBlock::tetrisBlockCollisionRightCheck(std::list<dotPos>& stackedBlock) {
	for (int i = 0; i < 4; i++) {
		bool buffer = componentBlock[i].blockRightCollisionCheck(stackedBlock);
		componentBlock[i].updateNowMovableStateRight(buffer);
	}

	for (int i = 0; i < 4; i++) {
		if (componentBlock[i].getNowMovableState().ableToMoveRight == false) {
			tetrisBlockNowMovableState.ableToMoveRight = false;
			break;
		}
		tetrisBlockNowMovableState.ableToMoveRight = true;
	}

	for (int i = 0; i < 4; i++) {
		componentBlock[i].updateNowMovableStateRight(tetrisBlockNowMovableState.ableToMoveRight);
	}
}

void TetrisBlock::tetrisBlockCollisionDownCheck(std::list<dotPos>& stackedBlock) {
	for (int i = 0; i < 4; i++) {
		bool buffer = componentBlock[i].blockDownCollisionCheck(stackedBlock);
		componentBlock[i].updateNowMovableStateDown(buffer);
	}

	for (int i = 0; i < 4; i++) {
		if (componentBlock[i].getNowMovableState().ableToFall == false) {
			tetrisBlockNowMovableState.ableToFall = false;
			tetrisBlockNowMovableState.ableToMoveLeft = false;
			tetrisBlockNowMovableState.ableToMoveRight = false;
			break;
		}
		tetrisBlockNowMovableState.ableToFall = true;
	}

	if (tetrisBlockNowMovableState.ableToFall == false) {
		for (int i = 0; i < 4; i++) {
			componentBlock[i].updateNowMovableStateDown(tetrisBlockNowMovableState.ableToFall);
			componentBlock[i].updateNowMovableStateLeft(tetrisBlockNowMovableState.ableToMoveLeft);
			componentBlock[i].updateNowMovableStateRight(tetrisBlockNowMovableState.ableToMoveRight);
			componentBlock[i].updateWhetherStacked(true);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			componentBlock[i].updateNowMovableStateRight(tetrisBlockNowMovableState.ableToMoveRight);
		}
	}
}

dotPos TetrisBlock::getTetrisBlockNowState(int blockNum) {
	for (int i = 0; i < 4; i++) 
		bringBackNowPos[i] = componentBlock[i].getBlockNowState();
	return bringBackNowPos[blockNum];
}

dotPos TetrisBlock::getTetrisBlockPrevState(int blockNum) {
	for (int i = 0; i < 4; i++)
		bringBackPrevPos[i] = componentBlock[i].getBlockPrevState();
	return bringBackPrevPos[blockNum];
}

int TetrisBlock::getTetrisBlockType() {
	return tetrisBlockType;
}

//Class : Block : Method
void Block::blockDefaultFall() {
	if (nowMovableState.ableToFall) {
		this->prevState = this->nowState;
		this->nowState.posY += 1;
	}
}

void Block::blockPlayerControllLeft(bool left) {
	if (left) {
		if (nowMovableState.ableToMoveLeft) {
			this->prevState = this->nowState;
			this->nowState.posX -= 1;
		}
	}
}

void Block::blockPlayerControllRight(bool right) {
	if (right) {
		if (nowMovableState.ableToMoveRight) {
			this->prevState = this->nowState;
			this->nowState.posX += 1;
		}
	}
}

void Block::blockPlayerControllDown(bool down) {
	if (down) {
		if (nowMovableState.ableToFall) {
			this->prevState = this->nowState;
			this->nowState.posY += 1;
		}
	}
}

void Block::blockCollisionCheck(std::list<dotPos>& stackedBlock) {
	this->nowMovableState.ableToFall = blockDownCollisionCheck(stackedBlock);
	this->nowMovableState.ableToMoveLeft = blockLeftCollisionCheck(stackedBlock);
	this->nowMovableState.ableToMoveRight = blockRightCollisionCheck(stackedBlock);
	if (nowMovableState.ableToFall == false) { 
		nowMovableState = { false, false, false };
		nowState.whetherStacked = true;
	}
}
bool Block::blockRightCollisionCheck(std::list<dotPos>& stackedBlock) {
	list<dotPos>::iterator iter = stackedBlock.begin();
	for (;iter != stackedBlock.end(); iter++) 
	{
		if (iter->posY == nowState.posY) {
			if (iter->posX - nowState.posX == 1)
				return FALSE;
		}
	}
	return TRUE;
}
bool Block::blockLeftCollisionCheck(std::list<dotPos>& stackedBlock) {
	list<dotPos>::iterator iter = stackedBlock.begin();
	for (;iter != stackedBlock.end(); iter++)
	{
		if (iter->posY == nowState.posY) {
			if (nowState.posX - iter->posX == 1)
				return FALSE;
		}
	}
	return TRUE;
}
bool Block::blockDownCollisionCheck(std::list<dotPos>& stackedBlock) {
	list<dotPos>::iterator iter = stackedBlock.begin();
	for (; iter != stackedBlock.end(); iter++)
	{
		if (iter->posX == nowState.posX) {
			if (iter->posY - nowState.posY < 2)
				return FALSE;
		}
	}
	return TRUE;
}

dotPos Block::getBlockPrevState() {
	return prevState;
}

dotPos Block::getBlockNowState() {
	return nowState;
}

ableToMove Block::getNowMovableState() {
	return nowMovableState;
}

void Block::updateNowMovableStateLeft(bool left) {
	nowMovableState.ableToMoveLeft = left;
}

void Block::updateNowMovableStateRight(bool right) {
	nowMovableState.ableToMoveRight = right;
}

void Block::updateNowMovableStateDown(bool down) {
	nowMovableState.ableToFall = down;
}

void Block::updateWhetherStacked(bool decision) {
	nowState.whetherStacked = decision;
}

void Block::updateBlockPos(int x, int y) {
	nowState.posX = x;
	nowState.posY = y;
}

void Block::updateBlockPrevPos(int x, int y) {
	prevState.posX = x;
	prevState.posY = y;
}

//Class : StackedBlockState : Method
void StackedBlockState::printOutFinalChangedState() {
	for (int j = 0; j < GAMETEMPLATE_Y; j++) {
		for (int i = 1; i < GAMETEMPLATE_X + GAMETEMPLATE_MARGIN_TYPE_1; i++) {
			if (stackedBlockState[j][i].blockORBlank == BLOCK) {
				printOutBlock(i + TEMPLATESTARTPOINT_X, j + TEMPLATESTARTPOINT_Y, stackedBlockState[j][i].color);
			}
			else{
				printOutBlank(i + TEMPLATESTARTPOINT_X, j + TEMPLATESTARTPOINT_Y);
			}
		}
	}
}

int StackedBlockState::updateStackedBlockLine() {
	int line = 0;
	bool whetherStacked[20] = { false, };

	for (int j = 0; j < GAMETEMPLATE_Y; j++) {
		for (int i = 1; i < GAMETEMPLATE_X+GAMETEMPLATE_MARGIN_TYPE_1; i++) {
			if (stackedBlockState[j][i].blockORBlank == BLANK) {
				whetherStacked[j] = false;
				break;
			}
			whetherStacked[j] = true;
			line++;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (whetherStacked[i] == true) {
			for (int j = 1; j < 11; j++) {
				stackedBlockState[i][j] = {BLANK, GREEN};
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		if (whetherStacked[i] == true) {
			for (int j = i - 1; j >= 0; j--) {
				for (int k = 1; k < GAMETEMPLATE_X + GAMETEMPLATE_MARGIN_TYPE_1; k++) {
					stackedBlockState[j + 1][k] = stackedBlockState[j][k];
				}
			}
			for (int k = 1; k < GAMETEMPLATE_X + GAMETEMPLATE_MARGIN_TYPE_1; k++)
				stackedBlockState[0][k] = {BLANK, GREEN};
		}
	}
	return line;
}

void StackedBlockState::updateStackedTetrisBlock(TetrisBlock* tetrisBlock) {
	for (int i = 0; i < 4; i++) {
		dotPos buffer = tetrisBlock->getTetrisBlockNowState(i);
		if (buffer.whetherStacked == true) 
			stackedBlockState[buffer.posY - TEMPLATESTARTPOINT_Y][buffer.posX - TEMPLATESTARTPOINT_X] 
			= {BLOCK, tetrisBlockTypeNColor[tetrisBlock->getTetrisBlockType()].color};
	}
}

void StackedBlockState::updateCollisionBoundary() {
	while (collisionBoundary.size() != 0)
		collisionBoundary.pop_back();

	for (int j = 0; j < GAMETEMPLATE_Y + GAMETEMPLATE_MARGIN_TYPE_1; j++) {
		for (int i = 0; i < GAMETEMPLATE_X + 2*GAMETEMPLATE_MARGIN_TYPE_1; i++) {
			dotPos buffer = {i+TEMPLATESTARTPOINT_X, j + TEMPLATESTARTPOINT_Y, true};
			collisionBoundary.push_back(buffer);
			if (stackedBlockState[j][i].blockORBlank != BLOCK) {
				collisionBoundary.pop_back();
			}
			else {
				bool whetherXLowerThan0 = (i-1)<0 ? true : false;
				bool whetherYLowerThan0 = (j-1)<0 ? true : false;
				bool whetherXHigherThanMax = (i+1)>11 ? true : false;
				bool whetherYHigherThanMax = (j+1)>20 ? true : false;

				if (whetherXLowerThan0) {
					if (whetherYLowerThan0) {
						if (stackedBlockState[j+1][i].blockORBlank==BLOCK) {
							if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
								collisionBoundary.pop_back();
							}
						}
					}
					else if (whetherYHigherThanMax) {
						if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
								collisionBoundary.pop_back();
							}
						}
					}
					else {
						if (stackedBlockState[j+1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
								if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
									collisionBoundary.pop_back();
								}
							}
						}
					}
				}

				else if(whetherXHigherThanMax) {
					if (whetherYLowerThan0) {
						if (stackedBlockState[j+1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
								collisionBoundary.pop_back();
							}
						}
					}
					else if (whetherYHigherThanMax) {
						if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
								collisionBoundary.pop_back();
							}
						}
					}
					else {
						if (stackedBlockState[j+1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
								if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
									collisionBoundary.pop_back();
								}
							}
						}
					}
				}

				else {
					if (whetherYLowerThan0) {
						if (stackedBlockState[j+1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
								if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
									collisionBoundary.pop_back();
								}
							}
						}
					}
					else if (whetherYHigherThanMax) {
						if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
								if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
									collisionBoundary.pop_back();
								}
							}
						}
					}
					else {
						if (stackedBlockState[j+1][i].blockORBlank == BLOCK) {
							if (stackedBlockState[j-1][i].blockORBlank == BLOCK) {
								if (stackedBlockState[j][i+1].blockORBlank == BLOCK) {
									if (stackedBlockState[j][i-1].blockORBlank == BLOCK) {
										collisionBoundary.pop_back();
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool StackedBlockState::checkWhetherGameOver() {
	for (int i = 1; i < GAMETEMPLATE_X + GAMETEMPLATE_MARGIN_TYPE_1; i++) {
		if (stackedBlockState[0][i].blockORBlank == BLOCK)
			return true;
	}

	return false;
}



