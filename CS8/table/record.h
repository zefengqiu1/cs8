#ifndef RECORD_H
#define RECORD_H


#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);

typedef vector<string> vectorstr;

class Record{
public:
    Record(){
        for (int i = 0; i<ROW_MAX; i++)
            record[i][0] = NULL;
        recno = -1;
    }

    Record(vectorstr v){
        for (int i = 0; i<ROW_MAX; i++)
            record[i][0] = NULL;
        for (int i=0; i<v.size(); i++)
            strcpy(record[i], v[i].c_str());
    }
    vectorstr get_fields_value()
    {
        vectorstr data;
        for(int i=0;i<ROW_MAX;i++)
        {
            if(record[i][0])
            {
                string a=record[i];
                data.push_back(a);
            }
        }
        return data;
    }

    long write(fstream& outs);
    long read(fstream& ins, long recno);


    friend ostream& operator<<(ostream& outs,const Record& r);
private:
    static const int ROW_MAX = 10;
    static const int COL_MAX = 500;
    int recno;
    char record[ROW_MAX][COL_MAX];
};
long Record::write(fstream &outs){
    //write to the end of the file.
    outs.seekg(0, outs.end);
    long pos = outs.tellp();

    //outs.write(&record[0], sizeof(record));
    outs.write(&record[0][0], sizeof(record));

    return pos/5000;//recond no.
}

long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);


    ins.read(&record[0][0], sizeof(record));
    return ins.tellg()/5000;
   // return ins.gcount();

}
template <class T>
ostream& operator<<(ostream& outs, const vector<T>& v){
    for (int i= 0; i<v.size(); i++)
        outs<<v[i]<<" ";
    return outs;
}
ostream& operator<<(ostream& outs,
                    const Record& r){
    for (int i=0; i<r.ROW_MAX; i++)
            outs<<r.record[i]<<endl;
    return outs;
}

//-------------------------------------------------
bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,
        std::fstream::in | std::fstream::binary );
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
    if (!file_exists(filename)){
        f.open(filename, std::fstream::out|std::fstream::binary);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename,
            std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}
void open_fileW(fstream& f, const char filename[]){
    f.open (filename,
            std::fstream::out| std::fstream::binary );
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }

}



#endif // RECORD_H
