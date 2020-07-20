#include <queue>
#include <iostream>
using namespace std;

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
Coord a(5,6);
coordQueue.push(a);            // enqueue item at back of queue
coordQueue.push(Coord(3,4));   // enqueue item at back of queue
...
Coord b = coordQueue.front();  // look at front item
coordQueue.pop();              // remove the front item from queue
if (coordQueue.empty())        // Is the queue empty?
cout << "empty!" << endl;
cout << coordQueue.size() << endl;  // num of elements
*/

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	queue<Coord> coordQueue;    // declare a queue of Coords

	Coord a(sr, sc);
	coordQueue.push(a);
	maze[sr][sc] = '/';

	while (!coordQueue.empty())
	{
		Coord b = coordQueue.front();
		coordQueue.pop();
		Coord c(er, ec);

		if (b.r() == c.r() && b.c() == c.c())
			return true;

		if (maze[b.r() + 1][b.c()] != 'X' && maze[b.r() + 1][b.c()] != '/') //moving south
		{
			coordQueue.push(Coord(b.r() + 1, b.c()));
			maze[b.r() + 1][b.c()] = '/';
		}

		if (maze[b.r()][b.c() - 1] != 'X' && maze[b.r()][b.c() - 1] != '/') //moving west
		{
			coordQueue.push(Coord(b.r(), b.c() - 1));
			maze[b.r()][b.c() - 1] = '/';
		}
		if (maze[b.r() - 1][b.c()] != 'X' && maze[b.r() - 1][b.c()] != '/') //moving north
		{
			coordQueue.push(Coord(b.r() - 1, b.c()));
			maze[b.r() - 1][b.c()] = '/';
		}
		if (maze[b.r()][b.c() + 1] != 'X' && maze[b.r()][b.c() + 1] != '/') //moving east
		{
			coordQueue.push(Coord(b.r(), b.c() + 1));
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