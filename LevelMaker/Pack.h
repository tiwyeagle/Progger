#include <vector>
#include <ctype.h>
#include "Level.h"

using namespace std;

const int PACK_NAME_LEN = 32;

class Pack {
	bool mainMenu;
	int levelId;

	int xPos,yPos;

	int cs;

	bool qui;

	bool keyboardLock;

	char name[PACK_NAME_LEN];
	int ncu;

	void modString(char *src, int inp, int *cursor, int max);

public:
	Pack();

	unsigned char calcCrc(FILE* file);

	void fromFile(char *path);
	void toFile(char *path);

	vector<Level*> levels;

	void gotoLevel(int i);
	void gotoMain();

	void quit();
	void moveCursor(int i);

	void newLevel();
	// i : level idex, d : direction
	bool movLevel(int i, bool d);
	void popLevel();
	void delLevel(int i);

	bool input(int inp);
	void inputMain(int inp);
	bool inputMaster(int inp);
	void inputState(int inp);

	void redraw(int x, int y);

	void redrawMain(int x, int y);

	void getCursorPos(int *x, int *y);
};