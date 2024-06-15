#include <iostream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;


// Twister

bool can_win(string s, int &move_index) {
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'O' && s[i + 1] == 'O') {
      s[i] = s[i + 1] = 'X';
      if (!can_win(s, move_index)) {
        move_index = i;
        return true;
      }
      s[i] = s[i + 1] = 'O';
    }
  }
  return false;
}

int arbitrary(string &s) {
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'O' && s[i + 1] == 'O') {
      s[i] = s[i + 1] = 'X';
      return i;
    }
  }
  return 0;
}

string generate(int ch) {
  char op[2] = {'X', 'O'};
  string result = "";
  for (int i = 0; i < ch; i++) {
    result = result + op[rand() % 2];
  }
  return result;
}

bool move(int index, string &str) {
  if (str[index] == 'O' && str[index + 1] == 'O') {
    str[index] = str[index + 1] = 'X';
    return true;
  } else {
    cout << "Invalid move" << endl;
    return false;
  }
}

void display(string str, int n) {
  for (int i = 0; i < 10; i++) {
    cout << "\033[;31m" <<  "0" << i << "\033[0m";
    i++;
    cout << "\033[;32m" <<  "0" << i << "\033[0m";
  }
  for (int i = 10; i < n; i++) {
    cout << "\033[;31m" << i << "\033[0m";
    i++;
    cout << "\033[;32m" << i << "\033[0m";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << "\033[;36m" <<  " " << str[i] << "\033[0m";
  }
  cout << endl;
}

int total_moves(string str, int size) {
  int n = 0;
  for (int i = 0; i < size - 1; i++) {
    if (str[i] == 'O' && str[i + 1] == 'O') {
      n++;
    }
  }
  return n;
}

void twister() {
  string str = generate(32);
  int m;
  int totalMoves = total_moves(str, 32);
  int counter = -1;
  while (totalMoves >= 1) {
    counter = 0;
    display(str, 32);
    cout << "Make Your Move:";
    cin >> m;
    if (move(m, str) == true) {
      totalMoves = total_moves(str, 32);
      m = -1;
      if (can_win(str, m) == true && totalMoves > 0) {
        move(m, str);
        counter = 1;
        cout << "AI played:" << m << endl;
      } else if(can_win(str, m) == false && totalMoves > 0) {
        counter = 1;
        m = arbitrary(str);
        cout << "AI played:" << m << endl;
      }else{
        continue;  
      }
      totalMoves = total_moves(str, 32);
    }
  }
  cout << "Game Over:" << endl;
  display(str, 32);
  if (counter == 0) {
    cout << "You won";
  } else {
    cout << "You lost";
  }
}

//snake and ladder

void draw_line(int n,char ch)
{
for(int i=0;i<n;i++)
   cout<<ch;
}

void boardSnL()
{
  cout<<"\n\n";
  draw_line(50,'-');
  cout<<"\n\t\tSNAKE AT POSITION\n";
  draw_line(50,'-');
  cout<<"\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to  1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to  7\n\tFrom 52 to 11\n\tFrom 48 to  9\n\tFrom 46 to  5\n\tFrom 44 to 22\n\n";
draw_line(50,'-');
  cout<<"\n\t\t LADDER AT POSITION\n";
  draw_line(50,'-');
  cout<<"\n\tFrom  8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
  draw_line(50,'-');
  cout<<endl;
}

void gamescore(char name1[],char name2[],int p1, int p2)
{
  cout<<"\n";
  draw_line(50,'~');
  cout<<"\n\t\tGAME STATUS\n";
  draw_line(50,'~');
  cout<<"\n\t--->"<<name1<<" is at position "<<p1<<endl;
  cout<<"\t--->"<<name2<<" is at position "<<p2<<endl;
  draw_line(50,'_');
  cout<<endl;
}

void play_dice(int &score)
{
  int dice;
  srand(time(0));
  dice=rand()%6+1;
  cout<<"\nYou got "<<dice<<" Point !! ";
  score=score+dice;
  cout<<"Now you are at position "<<score;
  switch(score)
  {
   case 98 :score=28;break;
   case 95 :score=24;break;
   case 92 :score=51;break;
   case 83 :score=19;break;
   case 73 :score=1;break;
   case 69 :score=33;break;
   case 64 :score=36;break;
   case 59 :score=17;break;
   case 55 :score=7;break;
   case 52 :score=11;break;
   case 48 :score=9;break;
   case 46 :score=5;break;
   case 44 :score=22;break;
   case 8  :score=26;break;
   case 21 :score=82;break;
   case 43 :score=77;break;
   case 50 :score=91;break;
   case 54 :score=93;break;
   case 62 :score=96;break;
   case 66 :score=87;break;
   case 80 :score=100;
 }
}

void snakeAndLadder() {
    int player1=0,player2=0,lastposition;
  char player1name[80],player2name[80];
  cout<<"\nEnter Name of player 1 :";
  cin>>player1name;
  cout<<"\nEnter Name of player 2 :";
  cin >> player2name;
  while(player1<=100 && player2<=100)
  {
    boardSnL();
    gamescore(player1name,player2name,player1,player2);
    cout<<"\n\n--->" <<player1name<<" Now your Turn >> Press any key to play ";
    getch();
    lastposition=player1;
    play_dice(player1);
    if(player1<lastposition)
       cout<<"\n\n\aOops!! Snake found !! You are at postion "<<player1<<"\n";
    else if(player1>lastposition+6)
       cout<<"\n\nGreat!! you got a ladder !! You are at position "<<player1;
    cout<<"\n\n\n--->"<<player2name<<" Now your Turn >> Press any key to play ";
    getch();
    lastposition=player2;
    play_dice(player2);
    if(player2<lastposition)
       cout<<"\n\n\n\aOops!! Snake found !! You are at position "<<player2<<"\n";
    else if(player2>lastposition+6)
       cout<<"\n\n\nGreat!! you got a ladder !! You are at position "<<player2<<"\n";
    getch();
  }
  cout<<"\n\n\n";
  draw_line(50,'+');
  cout<<"\n\n\t\tRESULT\n\n";
  draw_line(50,'+');
  cout<<endl;
  gamescore(player1name,player2name,player1,player2);
  cout<<"\n";
  if(player1>player2)
    cout<<player1name<<" !! You are the winner of the game\n\n";
  else if (player2>player1)
    cout<<player2name<<" !! You are the winner of the game\n\n";
  draw_line(50,'+');
  getch();
}


// 2048

int board[4][4];
int dirLine[]={1,0,-1,0};
int dirColumn[]={0,1,0,-1};

pair<int,int> generateUnocupiedPosition()
{
    int occupied = 1,line,column;
    while(occupied)
    {
        line = rand() % 4;
        column = rand() % 4;
        if(board[line][column]==0)
            occupied=0;
    }
    return make_pair(line,column);
}
void addPiece()
{
    pair<int,int> pos = generateUnocupiedPosition();
    board[pos.first][pos.second]=2;
}
void newGame()
{
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        board[i][j]=0;
    }
    addPiece();
    
}

void printUI()
{
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        if(board[i][j]==0)
            cout << "\033[;33m" << setw(4) << "." << "\033[0m";
        else
            cout << "\033[1;31m" << setw(4) << board[i][j] << "\033[0m";
        cout<<endl;

    }
    cout<<"n: new game, w:up, s:down, d:right, a:left, q:quit"<<endl;
}

bool canDoMOve(int line,int column,int nextLine,int nextColumn)
{
    if(nextLine<0 || nextColumn<0 || nextLine >= 4 || 
    nextColumn >= 4 || (board[line][column]!= board[nextLine][nextColumn] 
    && board[nextLine][nextColumn]!=0))
        return false;
    return true;
}

void applyMove(int direction)
{
    int startLine =0, startColumn=0,lineStep=1, columnStep=1;
    if(direction == 0)
    {
        startLine = 3;
        lineStep = -1;
    }
    if(direction == 1)
    {
        startColumn = 3;
        columnStep = -1;
    }
    int movePossible,canAddPiece=0;
    do{
        movePossible = 0;
    
        for(int i=startLine; i>=0 && i<4; i+= lineStep)
            for(int j=startColumn; j>=0 && j<4; j+= columnStep)
            {
                int nextI=i+dirLine[direction],nextJ=j+dirColumn[direction];
                // cout<<i<<" "<<j<<" "<<nextI<<" "<<nextJ<<endl;
                if(board[i][j] && canDoMOve(i,j,nextI,nextJ))
                {
                    board[nextI][nextJ]+=board[i][j];
                    board[i][j]=0;
                    movePossible = canAddPiece = 1;
                }
            }
    }while(movePossible);
        if(canAddPiece)
            addPiece();
    

}

void tiles()
{
    char commandToDir[128];
    commandToDir['s']=0;
    commandToDir['d']=1;
    commandToDir['w']=2;
    commandToDir['a']=3;
    newGame();
    while(true)
    {
        printUI();
        char command;
        cin>>command;
        if(command == 'n')
            newGame();
        else if(command == 'q')
            break;
        else
        {
            int currentDirection = commandToDir[command];
            applyMove(currentDirection);
        }
    }

}

// Maze

int score = 0;
vector<vector<char>> maze;

char u[15], ps[11], r1 = 201, r2 = 200, r3 = 188, r4 = 187, r5 = 205, r6 = 186, r7 = 220,
                    r8 = 202, r9 = 204, r10 = 203, r11 = 206, r12 = 185;
void printHeader()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "  WELCOME TO MazeQuest: A Graph-Based Adventure  " << r6 << endl
         << endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}

class Graph
{
public:
    int nodes;
    vector<vector<int>> adj;
    int sp;
    int lp;

    Graph(int n)
    {
        sp = 0;
        this->nodes = n;
        adj = vector<vector<int>>(n * n);
    }

    void checkEdge()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                edge(i, j);
            }
        }
    }

    void add_edge(int org, int dest)
    {
        adj[org].push_back(dest);
    }

    void edge(int i, int j)
    {
        if (maze[i][j] != 'X')
        {
            if (i > 0 && maze[i - 1][j] != 'X')
            {
                add_edge((i * nodes) + j, (i - 1) * nodes + j);
            }
            if (i < nodes - 1 && maze[i + 1][j] != 'X')
            {
                add_edge((i * nodes) + j, (i + 1) * nodes + j);
            }
            if (j > 0 && maze[i][j - 1] != 'X')
            {
                add_edge((i * nodes) + j, (i * nodes) + (j - 1));
            }
            if (j < nodes - 1 && maze[i][j + 1] != 'X')
            {
                add_edge((i * nodes) + j, (i * nodes) + (j + 1));
            }
        }
    }

    int minEdgeBFS(int u, int v)
    {
        vector<bool> visited(nodes * nodes, false);
        vector<int> distance(nodes * nodes, 0);
        queue<int> Q;
        distance[u] = 0;
        Q.push(u);
        visited[u] = true;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < adj[x].size(); i++)
            {
                if (visited[adj[x][i]])
                    continue;
                distance[adj[x][i]] = distance[x] + 1;
                Q.push(adj[x][i]);
                visited[adj[x][i]] = true;
            }
        }
        return distance[v];
    }
};

class MazeGame
{
public:
    string player;
    int n, steps;

    MazeGame(int n, string name)
    {
        this->n = n;
        player = name;
        steps = 0;
        maze = vector<vector<char>>(n, vector<char>(n, ' '));
        maze[0][0] = '@';
        maze[n - 1][n - 1] = '#';
    }

    void randomObstruction(double percent)
    {
        int c = (percent * n * n);
        while (c > 0)
        {
            int i = rand() % n;
            int j = rand() % n;
            if (maze[i][j] != 'X' && maze[i][j] != '#' && (i != 0 || j != 0))
            {
                maze[i][j] = 'X';
                c--;
            }
        }
    }

    void drawMaze()
    {
        int i, j = 0;
        cout << "\n\n\n";
        for (i = 0; i < n; i++)
        {
            cout << "\t   " << (i + 1) << "  ";
        }
        cout << "\n";
        for (i = 0; i < n; i++)
        {
            cout << "\t  _  ";
        }
        cout << "\n";
        while (j < n)
        {
            for (i = 0; i < n; i++)
            {
                if (maze[i][j] != ' ')
                    printf("\t| %c |", maze[i][j]);
                else
                    cout << "\t| _ |";
            }
            cout << "\n";
            j++;
        }
        cout << "\n\n\n\n\n";
    }

    void move(int x, int y)
    {
        char ch;
        do
        {
            cout << "\nUP....'W'";
            cout << "\nLEFT....'A'";
            cout << "\nDOWN....'S'";
            cout << "\nRIGHT....'D'";
            cout << "\nQUIT....'Q'";
            cout << "\nEnter Your Move:- ";
            cin >> ch;
            ch = toupper(ch);
            switch (ch)
            {
            case 'W':
                if (y > 0 && maze[x][y - 1] != 'X' && maze[x][y - 1] != '#')
                {
                    maze[x][y] = '_';
                    y -= 1;
                    maze[x][y] = '@';
                    steps++;
                }
                else if (maze[x][y - 1] == '#')
                {
                    cout << "\n\t\t\tHURRAY!! Level Cleared !!";
                    y -= 1;
                    break;
                }
                else
                    cout << "\nCan't Move up";

                break;
            case 'A':
                if (x > 0 && maze[x - 1][y] != 'X' && maze[x - 1][y] != '#')
                {
                    maze[x][y] = '_';
                    x -= 1;
                    maze[x][y] = '@';
                    steps++;
                }
                else if (maze[x - 1][y] == '#')
                {
                    cout << "\n\t\t\tHURRAY!! Level Cleared !!";
                    x -= 1;
                    break;
                }
                else
                    cout << "\nCan't Move left";

                break;
            case 'S':
                if (y >= 0 && y + 1 < n && maze[x][y + 1] != 'X' && maze[x][y + 1] != '#')
                {
                    maze[x][y] = '_';
                    y += 1;
                    maze[x][y] = '@';
                    steps++;
                }
                else if (maze[x][y + 1] == '#')
                {
                    cout << "\n\t\t\tHURRAY!! Level Cleared !!";
                    y += 1;
                    break;
                }
                else
                    cout << "\nCan't Move Down";

                break;
            case 'D':
                if (x >= 0 && x + 1 < n && maze[x + 1][y] != 'X' && maze[x + 1][y] != '#')
                {
                    maze[x][y] = '_';
                    x += 1;
                    maze[x][y] = '@';
                    steps++;
                }
                else if (maze[x + 1][y] == '#')
                {
                    cout << "\n\t\t\tHURRAY!! Level Cleared !!";
                    x += 1;
                    break;
                }
                else
                    cout << "\nCan't Move Right";

                break;
            case 'Q':
                cout << "\n"
                     << player << " Your steps are:- " << steps + 1;
                cout << "\n"
                     << player << " Your score is:- " << score;
                exit(0);
            default:
                cout << "\nInvalid Move. Please enter a valid move.\n";
                break;
            }
            drawMaze();

        } while (maze[x][y] != '#');
    }

    void scoreBoard(int shortest, double percent)
    {
        int longest = (n * n) - (percent * n * n);
        int avg = (longest + shortest) / 2;
        int count = 0;
        if ((steps + 1) > avg)
        {
            score += 40;
        }
        else if ((steps + 1) == avg)
        {
            score += 50;
        }
        else if ((steps + 1) < avg)
        {
            if ((steps + 1) == shortest)
                score += 100;
            else
            {
                count = (steps + 1) - shortest;
                if (count == 1)
                    score += 95;
                else if (count == 2)
                    score += 90;
                else if (count == 3)
                    score += 85;
                else if (count == 4)
                    score += 80;
                else if (count == 5)
                    score += 75;
                else if (count == 6)
                    score += 70;
                else if (count == 7)
                    score += 65;
                else if (count == 8)
                    score += 60;
                else if (count == 9)
                    score += 55;
                else
                    score += 50;
            }
        }
    }
};


void mazeQuest() {
    string name;
    int n = 8;
    double c;
    cout << endl
         << "\n\t Enter your Name:- ";
    cin >> name;

    MazeGame a(8, name);
    Graph g(8);
    system("cls");
    int sp = 0;
    char ch;
    cout << "\n\n\t\t\t\t " << r1;
    for (int i = 1; i < 15; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t\t\t " << r6 << "   Play    " << r6 << endl;
    cout << "\t\t\t\t " << r2;
    for (int i = 1; i < 15; i++)
        cout << r5;
    cout << r3 << endl;

    while (sp == 0)
    {
        a.randomObstruction(0.15);
        g.checkEdge();
        sp = g.minEdgeBFS(0, (8 * 8) - 1);
        if (sp != 0)
        {
            a.drawMaze();
        }
    }
    a.move(0, 0);
    a.scoreBoard(sp, c);
    cout << "\nYour Total Steps:-" << (a.steps + 1);
    cout << "\nYour Score:- " << score << endl
         << endl;

    cout << "\n\n";
    cout << "\t\t THANK YOU FOR USING MazeQuest \a";
    getch();
}


void welcome()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "          WELCOME TO OMNIVERSE ARCADE            " << r6 <<endl<< endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}

void welcomeTwister()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "               WELCOME TO TWISTER                " << r6 <<endl<< endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}

void welcomeTiles()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "               WELCOME TO 2048                   " << r6 <<endl<< endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}

void welcomeSnakess()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "          WELCOME TO SNAKE & LADDER              " << r6 <<endl<< endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}

void welcomeMaze()
{
    char u[15] = {r5, r9, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5, r5}; // 'U' in ASCII art
    char ps[11] = {r1, r6, r6, r6, r10, r5, r5, r5, r5, r5, r5};               // 'PS' in ASCII art
    for (int i = 0; i < 89; i++)
        cout << r7;

    cout << "\n\n\t\t " << r1;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r4 << endl;
    cout << "\t\t " << r6 << "             WELCOME TO MAZE QUEST               " << r6 <<endl<< endl;
    cout << "\t\t " << r2;
    for (int i = 1; i < 50; i++)
        cout << r5;
    cout << r3 << endl;

    for (int i = 0; i < 89; i++)
        cout << r7;
}




int main() { 
  int menu = 0;
  welcome();
  while(true){
  cout <<endl<<endl<<"Select the game you wanna paly below:" << endl;
  cout << "1. Twister" << endl;
  cout << "2. 2048" << endl;
  cout << "3. Snakes and Ladders" << endl;
  cout << "4. Maze" << endl;
  cout<<"Enter your choice: ";
  cin >> menu;
  if(menu == 1){
      welcomeTwister();
      cout<<endl;
      twister();  
      cout<<endl;
  }else if (menu == 2){
      welcomeTiles();
      cout<<endl;
      tiles();
      cout<<endl;
  }else if(menu == 3){
      welcomeSnakess();
      cout<<endl;
      snakeAndLadder();
      cout<<endl;
  }else if(menu == 4){
      welcomeMaze();
      cout<<endl;
      mazeQuest();
      cout<<endl;
  }else{
    cout << "Invalid Option Pls Select a Game";
  }
  char choice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout<<"THANK YOU FOR PLAYING";
            break;
        }
    }
}
