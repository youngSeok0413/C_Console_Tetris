#ifndef Tetris_ConstNum
#define Tetris_ConstNum

//game template
#define GAMETEMPLATE_Y 20
#define GAMETEMPLATE_X 10
#define GAMETEMPLATE_MARGIN_TYPE_1 1
#define GAMETEMPLATE_MARGIN_TYPE_2 4
#define GAMESCREEN_X 17
#define GAMESCREEN_Y 25

#define TEMPLATESTARTPOINT_X 0
#define TEMPLATESTARTPOINT_Y 4

#define TETRISBLOCKGENERATEPOINT_X 5
#define TETRISBLOCKGENERATEPOINT_Y 5

#define BLOCKSHOW_X 14
#define BLOCKSHOW_Y 3

//Block Type
const char BLOCK = '@';
const char BLANK = ' ';

//Block Color
enum Color {
    ORANGE = 6, //L
    BLUE = 9, //reverse L
    RED = 12, // z
    YELLOW = 14, //square
    GREEN = 10, // reverse z
    PURPLE = 13, // house
    CYAN = 11, // stick
    GRAY = 7 // default color
};

struct blockTypeNColor {
    int blockType;
    int color;
};

struct blockMemory {
    char blockORBlank;
    int color;
};

//TITLE PAGE
const char TITLEPAGE[GAMESCREEN_Y][GAMESCREEN_X] = 
{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
//GAMETEMPLATE
const char GAMETEMPLATE[GAMESCREEN_Y][GAMESCREEN_X+1] =
{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','!','T','E','T','R','I','S','!',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ','!','T','E','T','R','I','S','!',' ','#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
//GAMESCREEN
const char FIRSTBLOCKSTATE[21][12] = 
{ 
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLOCK},
    {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK}
};
//GAMEOVER PAGE
const char GAMEOVER[GAMESCREEN_Y][GAMESCREEN_X+1] =
{
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ',' '},
    {' ','#',' ',' ',' ','#',' ','#',' ','#','#','#',' ','#',' ',' ',' ',' '},
    {' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ',' '},
    {' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' '},
    {' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ',' '},
    {' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' '},
    {' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ',' '},
    {' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#','#',' ',' ',' '},
    {' ','#','#','#',' ',' ','#',' ',' ','#','#','#',' ','#',' ','#',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','\?',' ','R','E','T','R','Y',' ','\?',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '}
};

struct dotPos
{
    int posX; // column way
    int posY; // raw way
    bool whetherStacked; // BlockType : 'T' (stacked) : 'F' : (Not yet)
};

struct ableToMove
{
    bool ableToFall;
    bool ableToMoveLeft;
    bool ableToMoveRight;
};

//relative position
const dotPos BLOCKTYPE[7][4][4] = {
    //type1(square)
        {
            {{-1,-1,false}, {-1,0,false}, {0,-1,false}, {0,0,false}},
            {{-1,-1,false}, {-1,0,false}, {0,-1,false}, {0,0,false}},
            {{-1,-1,false}, {-1,0,false}, {0,-1,false}, {0,0,false}},
            {{-1,-1,false}, {-1,0,false}, {0,-1,false}, {0,0,false}}
        },
    //type2(loof Shape)
        {
            {{-1,0,false}, {0,-1,false}, {0,0,false}, {1,0,false}},
            {{0,0,false}, {0,-1,false}, {0,-2,false}, {-1,-1,false}},
            {{0,0,false}, {0,-1,false}, {-1,-1,false}, {1,-1,false}},
            {{0,0,false}, {0,-1,false}, {0,-2,false}, {1,-1,false}}
        },
    //type3(stick)
        {
            {{-2,0,false}, {-1,0,false}, {0,0,false}, {1,0,false}},
            {{0,-3,false}, {0,-2,false}, {0,-1,false}, {0,0,false}},
            {{-2,0,false}, {-1,0,false}, {0,0,false}, {1,0,false}},
            {{0,-3,false}, {0,-2,false}, {0,-1,false}, {0,0,false}}
        },
    //type4(reverse z)
        {
            {{-1,0,false}, {0,0,false}, {0,-1,false}, {1,-1,false}},
            {{0,0,false}, {0,-1,false}, {-1,-1,false}, {-1,-2,false}},
            {{-1,0,false}, {0,0,false}, {0,-1,false}, {1,-1,false}},
            {{0,0,false}, {0,-1,false}, {-1,-1,false}, {-1,-2,false}}
        },
    //type5(z)
        {
            {{0,0,false}, {0,-1,false}, {-1,-1,false}, {1,0,false}},
            {{0,0,false}, {0,-1,false}, {1,-1,false}, {1,-2,false}},
            {{0,0,false}, {0,-1,false}, {-1,-1,false}, {1,0,false}},
            {{0,0,false}, {0,-1,false}, {1,-1,false}, {1,-2,false}}
        },
    //type6(L)
        {
            {{0,0,false}, {-1,0,false}, {1,0,false}, {-1,-1,false}},
            {{0,0,false}, {-1,0,false}, {0,-1,false}, {0,-2,false}},
            {{-1,-1,false}, {0,-1,false}, {1,-1,false}, {1,0,false}},
            {{-1,0,false}, {-1,-1,false}, {-1,-2,false}, {0,-2,false}}
        },
    //type7(reverse L)
        {
            {{0,0,false}, {-1,0,false}, {1,0,false}, {1,-1,false}},
            {{0,0,false}, {0,-1,false}, {0,-2,false}, {-1,-2,false}},
            {{-1,0,false}, {-1,-1,false}, {0,-1,false}, {1,-1,false}},
            {{0,0,false}, {-1,0,false}, {-1,-1,false}, {-1,-2,false}}
        }
};

const blockTypeNColor tetrisBlockTypeNColor[7] = {
    {0, YELLOW},
    {1, PURPLE},
    {2, CYAN},
    {3, GREEN},
    {4, RED},
    {5, ORANGE},
    {6, BLUE}
};
#endif


