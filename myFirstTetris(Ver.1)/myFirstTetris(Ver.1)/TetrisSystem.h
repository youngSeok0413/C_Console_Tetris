#ifndef TetrisSystem
#define TetrisSystem

#include <Windows.h>
#include <stdio.h>
#include <Time.h>
#include <list> // list vs vector : Is the data changed frequently?
#include "Tetris_ConstNum.h"

using namespace std;

COORD getXY();
void gotoXY(int x, int y);
void changeCursorColor(int color);

void setConsoleSystemSetting();
void makeCursorInvisible();

void printOutBlockShow(int blockType, int color);
void printOutBlock(int x, int y, int color);
void printOutBlank(int x, int y);
void printOutGameTitle();
void printOutGameTemplate();
void printOutGameOver();
void printOutScore(int SCORE, int line);

int updateScore(int SCORE, int line);
int dropSpeedControll(int score);

int whichBlockType();

class Block {
private:
	dotPos nowState;
	dotPos prevState;
	ableToMove nowMovableState;
public:
	Block(int X=0, int Y=0) {
		this->nowState = {X, Y, FALSE};
		this->prevState = {X, Y, FALSE};
		this->nowMovableState = {TRUE, TRUE, TRUE};
	}
	void blockDefaultFall(void);
	void blockPlayerControllLeft(bool left);
	void blockPlayerControllRight(bool right);
	void blockPlayerControllDown(bool down);
	void blockCollisionCheck(std::list<dotPos>& stackedBlock);
	bool blockRightCollisionCheck(std::list<dotPos>& stackedBlock);
	bool blockLeftCollisionCheck(std::list<dotPos>& stackedBlock);
	bool blockDownCollisionCheck(std::list<dotPos>& stackedBlock);
	dotPos getBlockNowState();
	dotPos getBlockPrevState();
	ableToMove getNowMovableState();
	void updateNowMovableStateLeft(bool);
	void updateNowMovableStateRight(bool);
	void updateNowMovableStateDown(bool);
	void updateWhetherStacked(bool);
	void updateBlockPos(int x, int y);
	void updateBlockPrevPos(int x, int y);
};

class TetrisBlock {
private:
	Block componentBlock[4];
	int tetrisBlockType;
	int tetrisBlockRotationNum;
	ableToMove tetrisBlockNowMovableState;
	dotPos bringBackNowPos[4];
	dotPos bringBackPrevPos[4];
public:
	TetrisBlock(int posX = TETRISBLOCKGENERATEPOINT_X,
		int posY = TETRISBLOCKGENERATEPOINT_Y, int blockType = 0) {
		for (int i = 0; i < 4; i++) {
			componentBlock[i] = Block(posX + BLOCKTYPE[blockType][0][i].posX,
				posY + BLOCKTYPE[blockType][0][i].posY);
		}
		tetrisBlockType = blockType;
		tetrisBlockRotationNum = 0;
		tetrisBlockNowMovableState = { TRUE, TRUE, TRUE };
	}
	void tetrisBlockRotate(std::list<dotPos>& stackedBlock);
	void tetrisBlockPrintOut(int blockColor);
	void tetrisBlockDefaultFall(std::list<dotPos>& stackedBlock);
	void tetrisBlockPlayerControllLeft(std::list<dotPos>& stackedBlock);
	void tetrisBlockPlayerControllRight(std::list<dotPos>& stackedBlock);
	void tetrisBlockPlayerControllDown(std::list<dotPos>& stackedBlock);
	void tetrisBlockCollisionLeftCheck(std::list<dotPos>& stackedBlock);
	void tetrisBlockCollisionRightCheck(std::list<dotPos>& stackedBlock);
	void tetrisBlockCollisionDownCheck(std::list<dotPos>& stackedBlock);
	int getTetrisBlockType();
	dotPos getTetrisBlockNowState(int);
	dotPos getTetrisBlockPrevState(int);
};


class StackedBlockState {
public:
	blockMemory stackedBlockState[GAMETEMPLATE_Y + GAMETEMPLATE_MARGIN_TYPE_1]
		[GAMETEMPLATE_X + 2 * GAMETEMPLATE_MARGIN_TYPE_1];
	list<dotPos> collisionBoundary;
	StackedBlockState() {
		collisionBoundary = list<dotPos>();

		for (int i = 0; i < GAMETEMPLATE_Y + GAMETEMPLATE_MARGIN_TYPE_1; i++) {
			for (int j = 0; j < GAMETEMPLATE_X + 2 * GAMETEMPLATE_MARGIN_TYPE_1; j++) {
				stackedBlockState[i][j] = {FIRSTBLOCKSTATE[i][j], GREEN};
			}
		}
	}
	int updateStackedBlockLine();
	void updateStackedBlock(dotPos* updatedData);
	void updateStackedTetrisBlock(TetrisBlock* tetrisBlock);
	void updateCollisionBoundary();
	void printOutFinalChangedState();
	bool checkWhetherGameOver();
};

#endif TetrisSystem
