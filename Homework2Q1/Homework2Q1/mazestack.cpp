#include <string>
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

/*
the maze array contains nRows rows (you couldn't check for this anyway);
each string in the maze is of length nCols;
the maze contains only Xs and dots when passed in to the function;
the top and bottom rows of the maze contain only Xs, as do the left and right columns;
sr and er are between 0 and nRows-1, and sc and ec are between 0 and nCols-1;
maze[sr][sc] and maze[er][ec] are '.' (i.e., not walls)
*/

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	stack<Coord> coordStack;     // declare a stack of Coords

	Coord a(sr, sc);
	coordStack.push(a); // push the coordinate (sr,sc)
	maze[sr][sc] = '/'; //indicate encounter

	while (!coordStack.empty())
	{
		Coord b = coordStack.top(); // look at top item in the stack
		coordStack.pop(); // remove the top item from stack
		Coord c(er, ec);

		if (b.r() == c.r() && b.c() == c.c())
			return true;

		
		if (maze[b.r() + 1][b.c()] != 'X' && maze[b.r() + 1][b.c()] != '/') //moving south
		{
			coordStack.push(Coord(b.r() + 1, b.c()));
			maze[b.r() + 1][b.c()] = '/';
		} 
		
		if (maze[b.r()][b.c() - 1] != 'X' && maze[b.r()][b.c() - 1] != '/') //moving west
		{
			coordStack.push(Coord(b.r(), b.c() - 1));
			maze[b.r()][b.c() - 1] = '/';
		} 
		if (maze[b.r() - 1][b.c()] != 'X' && maze[b.r() - 1][b.c()] != '/') //moving north
		{
			coordStack.push(Coord(b.r() - 1, b.c()));
			maze[b.r() - 1][b.c()] = '/';
		}
		if (maze[b.r()][b.c() + 1] != 'X' && maze[b.r()][b.c() + 1] != '/') //moving east
		{
			coordStack.push(Coord(b.r(), b.c() + 1));
			maze[b.r()][b.c() + 1] = '/';
		}
		
	}

	return false;
}

int main()
{
	string maze[10] = {
		"XXXXXXXXXX",
		"X....X...X",
		"X.XX.XX..X",
		"XXX....X.X",
		"X.XXX.XXXX",
		"X.X...X..X",
		"X...X.X..X",
		"XXXXX.X.XX",
		"X........X",
		"XXXXXXXXXX"
	};

	if (pathExists(maze, 10, 10, 3, 5, 8, 8))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;
	if (pathExists(maze, 10, 10, 1, 8, 8, 8))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;
}