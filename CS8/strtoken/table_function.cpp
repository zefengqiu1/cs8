#include "table_function.h"

void init_table(int _table[][MAX_COLUMNS])
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<MAX_COLUMNS;j++)
        {
            _table[i][j]=-1;
        }
    }
}

void mark_success(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0]=1;
}

void mark_fail(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0]=0;
}

bool is_success(int _table[][MAX_COLUMNS], int state)
{
    if(_table[state][0]==1)
    {
        return true;
    }else
    {
        return false;
    }
}

void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state)
{
    for(int i=from;i<to;i++)
    {
        _table[row][i]=state;
    }
}

void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    for(int i=0;i<strlen(columns);i++)
    {
        _table[row][columns[i]]=state;
    }
}

void mark_cell(int row, int table[][MAX_COLUMNS], int column, int state)
{
        table[row][column]=state;
}


void print_table(int _table[][MAX_COLUMNS])
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<MAX_COLUMNS;j++)
        {
            cout<<_table[i][j]<<"|";
        }
    }
}

void show_string(char s[], int _pos)
{
    cout<<s[_pos]<<" ";
}
