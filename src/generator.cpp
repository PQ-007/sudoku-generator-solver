#include <iostream>
using namespace std;
class Generator
{
public:
    int board[9][9] = {0};
    void print_board()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    int find_empty()
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == 0)
                {
                    return r, c;
                }
            }
        }
        return 0;
    }
    bool valid_cell(int num, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num || board[i][col] == num)
            {
                return false;
            }
        }
        int box_row_start = row - row % 3;
        int box_col_start = col - col % 3;
        for (int r = box_row_start; r < box_row_start + 3; r++)
        {
            for (int c = box_col_start; c < box_col_start + 3; c++)
            {
                if (board[r][c] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void generate()
    {
        while (find_empty() != 0)
        {
            int row, col;
            row, col = find_empty();

            return;
        }
    }
};

int main() {
    Generator gen;
    gen.generate();
    gen.print_board();

    return 0;
}
