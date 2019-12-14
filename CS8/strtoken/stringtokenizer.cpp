#include "stringtokenizer.h"


STokenizer::STokenizer()
{
    make_table(_table);
    _pos=0;
}


STokenizer::STokenizer(char str[])
{
    _pos=0;
    strcpy(_buffer,str);
    make_table(_table);
}

bool STokenizer::done()
{

    if(_pos==strlen(_buffer))
    {
        return true;
    }else
    {
         return false;
    }


}

void STokenizer::set_string(char str[])
{
    _pos=0;
    strcpy(_buffer,str);
}

void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
          init_table(_table);
          const char Punc[]={'.','!',',',':','~','@','#','$','%','(',')','<','>','`','-','='};
          const char Number[]="1234567890";
          const char Word[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
          const char Space[]={' '};
          const char Unknown[]="";

        mark_fail(_table,0);
        mark_success(_table,1);//pun
        mark_success(_table,2);//number
        mark_success(_table,3);//space
        mark_success(_table,4);//alpha
        mark_success(_table,5);//unknown
        mark_fail(_table,6);
        mark_success(_table,7);//number

          mark_cells(0,_table,Punc,1);
          mark_cells(0,_table,Number,2);
          mark_cell(0,_table,' ',3);
          mark_cells(0,_table,Word,4);
          //mark_cells(0,_table,Unknown,5);//unknown

          mark_cells(1,_table,Punc,1);

          mark_cell(2,_table,'.',6);
          mark_cells(2,_table,Number,2);
          mark_cell(3,_table,' ',3);
          mark_cells(4,_table,Word,4);
          //mark_cells(5,_table,Unknown,5);//unkownn
          //5
          mark_cells(6,_table,Number,7);
          mark_cells(7,_table,Number,7);

}

int STokenizer::get_token(int start_state, string& token)
{
    int index=_pos;
    int start=_pos;
    bool success=false;
    int current_state=0;
    while(start_state!=-1 && index <strlen(_buffer))
    {
        if(_buffer[index]<0||_buffer[index]>128)
        {
            index++;
            break;
        }
        start_state=_table[start_state][_buffer[index]];
        if(start_state==-1)
        {
            break;
        }
        if(_table[start_state][0]==1)
        {
            success=true;
            current_state=start_state;
            index++;
            _pos=index;
        }else
        {
            index++;
        }

    }


    if(success)
    {
        for(int i=start;i<_pos;i++)
        {
            token+=_buffer[i];
        }

    }
    return current_state;

}

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];
