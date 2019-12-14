#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Record{
public:
    Record(){
        for(int i=0;i<MAX_ROW;i++)
        {
            record[i][0] = NULL;
        }

        recno = -1;//record number
    }

    typedef vector<string> vectorstr;


    Record(vectorstr v){
        for(int i=0;i<v.size();i++)
        {
            strcpy(record[i],v[i].c_str());
        }
        //recno=;
        cout<<"wo qu ni de "<<endl;

    }

//    Record(char str[3][3]){
//        for(int i=0;i<3;i++)
//        {
//            strcpy(record[i],v[i].c_str());
//        }
//        //recno=;
//        cout<<"wo qu ni de "<<endl;

//    }

    long write(fstream& outs);
    long read(fstream& ins, long recno);


    friend ostream& operator<<(ostream& outs,const Record& r)
    {
        for(int i=0;i<MAX_ROW;i++)
        {
            outs<<r.record[i];
        }

           return outs;
    }
private:
    static const int MAX_ROW = 20;
    static const int MAX_COL = 50;
    int recno;
    char record[MAX_ROW][MAX_COL];//& buffer
};

long Record::write(fstream &outs){
    //write to the end of the file.

   // long pos1=outs.end;
    long pos = outs.tellp();
   //  outs.seekp(0,outs.end); //use for read seekp used for write.
    //outs.write(&record[0], sizeof(record));
    outs.write(&record[0][0], sizeof(record));// size of record

    return pos;
}
long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record); //if record array is 100 char.
    ins.seekg(pos, ios_base::beg); // at the begining of stream + pos

    ins.read(&record[0][0], sizeof(record));//then start read at pos.
    return ins.gcount();//how many char i read.

}


bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);



bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;
    ff.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]) throw(char*){
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (!file_exists(filename)){ //check whether exist
        f.open(filename, std::fstream::out|std::fstream::binary);//if not exist then creat
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename,std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}
void open_fileW(fstream& f, const char filename[]){
    f.open (filename,std::fstream::out| std::fstream::binary );
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }

}

void save_list(Record list[][3], int count){
    fstream f;
    open_fileW(f, "record_list.bin");
    for (int i= 0; i<count; i++){
        list[i][1].write(f);
    }
    f.close();

}

#endif // RECORD_H
