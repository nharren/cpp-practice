#include <iostream>

using namespace std;

char GetChar(int generator, char base, int range)
{
    return base + generator % range;
}

void OutputRandomCharacters(char row[80], int j)
{
    int i = 0;

    while (i < 80)
    {
        if (row[i] != ' ')
        {
            row[i] = GetChar(j + i * i, '!', 30);
        }

        cout << row[i];

        ++i;
    }
}

void Delay()
{
    int i = 0;

    while (i < 600000)
    {
        GetChar(1, 1, 1);

        ++i;
    }
}

void main()
{
    char row[80];

    int j = 7;
    int k = 2;
    int l = 5;
    int m = 1;

    while (true)
    {
        OutputRandomCharacters(row, j);

        j += 31;
        k += 17;
        l += 7;
        m += 67;

        row[j % 80] = '-';
        row[k % 80] = ' ';
        row[l % 80] = '-';
        row[m % 80] = ' ';

        Delay();
    }
}