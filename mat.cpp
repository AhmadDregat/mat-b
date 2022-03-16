/**
 *
 * AUTHORS: <Aldrarga ahmad>
 *
 * Date: 2021-03
 */

#include "mat.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

using namespace ariel;

void CreatingMat(vector<vector<char>> &mat, int startR, int endR, int startC, int endC, char s)
{

    for (int i = 0; i <= mat.size() / 2 && i <= mat[0].size() / 2; i++)
    {
        // Fill the mat col with the symbol in place
        for (int j = startC; j < endR; j++)
        {
            mat[j][endC - 1] = s;
            mat[j][startC] = s;
        }

        // Fill the mat row with the symbol in place
        for (int j = startR; j < endC; j++)
        {
            mat[endR][j] = s;
            mat[startR][j] = s;
        }

        startC += 2;
        endC -= 2;
        startR += 2;
        endR -= 2;
    }
}

string ariel::mat(int col, int row, char s1, char s2)
{
    vector<vector<char>> matR;
    const int minAsci = 33;
    const int maxAsci = 126;
    // cheack input
    if (row % 2 == 0 || col % 2 == 0)
    {
        throw invalid_argument("Mat size is not allowed even");
    }

    if (row <= 0 || col <= 0)
    {
        throw invalid_argument(" your input should be greater than 0 ");
    }

    if ((s1 < minAsci) || (s2 < minAsci) || (s1 > maxAsci) || (s2 > maxAsci))
    {
        throw invalid_argument("Invalid Character");
    }

    for (int i = 0; i < row; i++)
    {
        vector<char> vector_row;
        // Request a change in capacity
        vector_row.reserve(col);

        for (int j = 0; j < col; j++)
        {
            vector_row.push_back(s2);
        }

        matR.push_back(vector_row);
    }

    CreatingMat(matR, 0, row - 1, 0, col, s1);

    // convert to string
    string result;

    for (vector<char> temp : matR)
    {
        string s(temp.begin(), temp.end());
        s += '\n';
        result += s;
    }

    return result;
}
