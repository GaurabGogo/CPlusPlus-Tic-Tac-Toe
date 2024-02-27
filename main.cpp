#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Grid
{
private:
  char arr[3][3];

  void InitializeArray()
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        arr[i][j] = '-';
      }
    }
  }

  void Welcome()
  {
    printf("This is a tic-tac toe game with the boxes initialized as\n [1] | [2] | [3] \n-----|-----|-----\n [4] | [5] | [6] \n-----|-----|-----\n [7] | [8] | [9] \n");
  }

public:
  Grid()
  {
    Welcome();
    InitializeArray();
  }

  void DrawGrid()
  {
    for (int i = 0; i < 3; i++)
    {
      printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
      if (i != 2)
        printf("---|---|---\n");
    }
  }

  bool GridEmpty()
  {
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (arr[i][j] != '-')
        {
          if (arr[i][j] == 'X' || arr[i][j] == 'O')
          {
            count++;
          }
        }
      }
    }
    if (count == 9)
    {
      return false;
    }
    return true;
  }

  int UpdateGrid(int choice, int turn)
  {
    char place;
    if (turn == 0)
    {
      place = 'X';
    }
    else
    {
      place = 'O';
    }

    switch (choice)
    {
    case 1:
      if (arr[0][0] == 'X' || arr[0][0] == 'O')
        return 0;
      else
        arr[0][0] = place;
      break;
    case 2:
      if (arr[0][1] == 'X' || arr[0][1] == 'O')
        return 0;
      else
        arr[0][1] = place;
      break;
    case 3:
      if (arr[0][2] == 'X' || arr[0][2] == 'O')
        return 0;
      else
        arr[0][2] = place;
      break;
    case 4:
      if (arr[1][0] == 'X' || arr[1][0] == 'O')
        return 0;
      else
        arr[1][0] = place;
      break;
    case 5:
      if (arr[1][1] == 'X' || arr[1][1] == 'O')
        return 0;
      else
        arr[1][1] = place;
      break;
    case 6:
      if (arr[1][2] == 'X' || arr[1][2] == 'O')
        return 0;
      else
        arr[1][2] = place;
      break;
    case 7:
      if (arr[2][0] == 'X' || arr[2][0] == 'O')
        return 0;
      else
        arr[2][0] = place;
      break;
    case 8:
      if (arr[2][1] == 'X' || arr[2][1] == 'O')
        return 0;
      else
        arr[2][1] = place;
      break;
    case 9:
      if (arr[2][2] == 'X' || arr[2][2] == 'O')
        return 0;
      else
        arr[2][2] = place;
      break;

    default:
      break;
    }
    return 1;
  }

  int CheckWin(int turn)
  {
    char player;
    if (turn == 0)
    {
      player = 'X';
    }
    else
    {
      player = 'O';
    }
    if (arr[0][0] == player && arr[0][1] == player && arr[0][2] == player)
      return 1;
    if (arr[1][0] == player && arr[1][1] == player && arr[1][2] == player)
      return 1;
    if (arr[2][0] == player && arr[2][1] == player && arr[2][2] == player)
      return 1;
    if (arr[0][0] == player && arr[1][0] == player && arr[2][0] == player)
      return 1;
    if (arr[0][1] == player && arr[1][1] == player && arr[2][1] == player)
      return 1;
    if (arr[0][2] == player && arr[1][2] == player && arr[2][2] == player)
      return 1;
    if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
      return 1;
    if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
      return 1;
    return 0;
  }
};

class Players
{
private:
  string playerOne, playerTwo;
  int choice;
  int turn = 0;

  void InitializePlayers()
  {
    cout << "Enter player one name: ";
    cin >> playerOne;
    cout << "Enter player two name: ";
    cin >> playerTwo;
    fflush(stdin);
  }

public:
  Players()
  {
    InitializePlayers();
  }

  int GetPlayerChoice()
  {
    printf("Enter the choice between 1-9: ");
    cin >> choice;
    return choice;
  }

  void PlayerTurn()
  {
    if (turn == 0)
    {
      cout << "Its player " << playerOne << " turn" << endl;
    }
    else
    {
      cout << "Its player " << playerTwo << " turn" << endl;
    }
  }

  string GetPlayerName(int turn)
  {
    if (turn == 0)
    {
      return playerOne;
    }
    else
    {
      return playerTwo;
    }
  }

  int GetPlayerTurn()
  {
    return turn;
  }

  void UpdatePlayerTurn()
  {
    if (turn == 0)
    {
      turn = 1;
    }
    else
    {
      turn = 0;
    }
  }
};

class Game
{
private:
  Grid grid = Grid();
  Players players = Players();
  bool gameStatus = false;
  int choice;
  int param = 0;
  int turn;

public:
  Game()
  {
    gameStatus = true;
  }

  void Draw()
  {
    grid.DrawGrid();
  }

  void UpdateChoice()
  {
    if (grid.GridEmpty())
    {
      players.PlayerTurn();
      choice = players.GetPlayerChoice();
      turn = players.GetPlayerTurn();
      if (grid.UpdateGrid(choice, turn) == 1)
      {
        if (grid.CheckWin(turn))
        {
          param = 1;
        }
        players.UpdatePlayerTurn();
      }
      else
      {
        printf("Invalid Choice!\n");
        UpdateChoice();
      }
    }
    else
    {
      param = 2;
    }
  }

  void DisplayWin(int turn)
  {
    cout << players.GetPlayerName(turn) << " won the game!" << endl;
    gameStatus = false;
  }

  void DisplayTie()
  {
    cout << "Its a tie!" << endl;
    gameStatus = false;
  }

  bool CheckGame()
  {
    if (!gameStatus)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void Result()
  {
    if (param == 1)
      DisplayWin(turn);
    if (param == 2)
      DisplayTie();
  }
};

int main()
{
  system("clear");
  cout << "Welcome to the Game!" << endl;

  // Initialize Game
  Game game = Game();

  while (1)
  {
    if (!game.CheckGame())
    {
      break;
    }
    game.UpdateChoice();
    system("clear");
    game.Draw();
    game.Result();
  }

  // Wait for user input
  getchar();
  return 0;
}
